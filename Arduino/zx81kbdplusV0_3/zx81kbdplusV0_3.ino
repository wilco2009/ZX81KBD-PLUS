#include <Wire.h>
#include <U8g2lib.h>[i]
#include <hidboot.h>
#include <usbhub.h>
#include <SPI.h>
#include "KBDPARSER.h"
#include <PS2Keyboard.h>
#include "SCANCODES.h"
#include "INTL.h"

const int DataPin = A2;
const int IRQpin =  3;
uint8_t value = 0;
uint8_t prev_value = 0;

PS2Keyboard keyboard;

#define CLK   A3 
#define NRST  9
#define C0    4
#define C1    5
#define C2    6
#define C3    7
#define C4    8

#define JUP     (value & 1)==0
#define JDOWN   (value & 2)==0
#define JLEFT   (value & 4)==0
#define JRIGHT  (value & 8)==0
#define JBUTB   (value & 16)==0
#define JTRIGER (value & 32)==0
#define JBUTA   (value & 64)==0
#define STORE   (value & 128)==0

#define PREV_JUP     (prev_value & 1)==0
#define PREV_JDOWN   (prev_value & 2)==0
#define PREV_JLEFT   (prev_value & 4)==0
#define PREV_JRIGHT  (prev_value & 8)==0
#define PREV_JBUTB   (prev_value & 16)==0
#define PREV_JTRIGER (prev_value & 32)==0
#define PREV_JBUTA   (prev_value & 64)==0

#define RESET   digitalWrite(NRST, 0);  \
                delay(1);               \
                digitalWrite(NRST, 1);  \
                delay(1);               

 //delayMicroseconds(50);
 #define CLOCK  digitalWrite(CLK, 0);   \
                delay(1);               \
                digitalWrite(CLK, 1);   \
                delay(1);               

uint8_t C[5]={C0,C1,C2,C3,C4};
const int pcfAddress = 0x20;
char S[10];
uint8_t rows[8]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};

U8G2_SSD1306_128X32_UNIVISION_1_HW_I2C u8g2(U8G2_R2); //, /* clock=*/ 21, /* data=*/ 20, /* reset=*/ U8X8_PIN_NONE);   // Adafruit Feather M0 Basic Proto + FeatherWing OLED
USB     Usb;
//USBHub     Hub(&Usb);
HIDBoot<USB_HID_PROTOCOL_KEYBOARD>    HidKeyboard(&Usb);

KbdRptParser Prs;

  
void setup() {
  Wire.begin();
  u8g2.begin();
  Serial.begin(9600);
  Serial.println(F("START"));
  pinMode(CLK,OUTPUT);
  pinMode(NRST,OUTPUT);
  pinMode(C0,OUTPUT);
  pinMode(C1,OUTPUT);
  pinMode(C2,OUTPUT);
  pinMode(C3,OUTPUT);
  pinMode(C4,OUTPUT);
  u8g2.setFont(u8g2_font_ncenB14_tr);
  S[0] = 0;
  memset(rows,0xff,8);
  //for (int i=0;i<=7;i++) rows[i]=0xff;
  if (Usb.Init() == -1)
    Serial.println(F("OSC did not start."));
  else
    Serial.println(F("OSC started."));

  delay( 1000 );

  HidKeyboard.SetReportParser(0, &Prs);
  keyboard.begin(DataPin, IRQpin);
  scState = stPRESS;
  prev_value = 0;
}

void inline setRow(uint8_t row, uint8_t col){
  bitSet(rows[row],col);
}

void inline clearRow(uint8_t row, uint8_t col){
  bitClear(rows[row],col);
}

boolean shiftPressed = false;

// the loop function runs over and over again forever
void loop() {
  short channel = 1;
  byte value = 0;
  uint8_t v;
  uint8_t shift;
  uint8_t row;
  uint8_t column;
  //memset(rows,0xff,8);

  if (keyboard.available()) {
    uint8_t sc = keyboard.readScanCode();
    //char sc = keyboard.read();
    if (sc!=0) {
      Serial.print(F("code: "));
      Serial.print(sc);
      switch (scState){
        case stPRESS:
        Serial.print(F("stPRESS:")); Serial.println(sc);
        if (sc==0xF0) scState = stRELEASE;
          else if (sc==0xE0) scState = stPRESS_E0;
          else if (sc==0xE1) scState = stPRESS_E1_1;
          else if ((sc==0x59) | (sc==0x12)) {shiftPressed = true; Serial.println(F("SHIFT"));}
          else {
             if (shiftPressed){
              v = findShiftedCode(sc);
              //if (v==(NULL  + 40))
              //  v = ps2Codes[sc];
             } else {
                v = findIntlCode(sc);
                if (v == (NULL  + 40)){
                  v = pgm_read_byte_near(ps2Codes+sc);
                };// else Serial.println(F("INTL"));
             }
            // Serial.println(v);
            shift = (v >> 6) & 1;
            row = (v & 0b00111111) / 5;
            column = (v & 0b00111111) % 5;
            clearRow(row,column);
            if (shift) clearRow(0,0);
            Serial.print(F("SHIFTP:")); Serial.print(shiftPressed);
            Serial.print(F("shift:")); Serial.print(shift);
            Serial.print(F(" v:")); Serial.print(v);
            Serial.print(F(" row:")); Serial.print(row);
            Serial.print(F(" column:")); Serial.print(column);
            Serial.println();
          }
          break;
        case stRELEASE:
          Serial.print("stRELEASE:"); Serial.println(sc);
          if ((sc==0x59) | (sc==0x12)) { shiftPressed = false; Serial.println(F("SHIFT RELEASE"));}
          else {
             if (shiftPressed){
              v = findShiftedCode(sc);
              //if (v==(NULL  + 40))
              //  v = ps2Codes[sc];
             }
              else v = pgm_read_byte_near(ps2Codes+sc);
            shift = (v >> 6) & 1;
            row = (v & 0b00111111) / 5;
            column = (v & 0b00111111) % 5;
            setRow(row,column);
            if (shift) setRow(0,0);
            scState = stPRESS;
            Serial.print(F("SHIFTP:")); Serial.print(shiftPressed);
            Serial.print(F("shift:")); Serial.print(shift);
            Serial.print(F(" v:")); Serial.print(v);
            Serial.print(F(" row:")); Serial.print(row);
            Serial.print(F(" column:")); Serial.print(column);
            Serial.println();
          }
          scState = stPRESS;
          break;
        case stPRESS_E0:
          Serial.print(F("stPRESS_E0:")); Serial.println(sc);
          if (sc==0xF0) {scState = stRELEASE_E0; Serial.println(F("GO TO RELEASE E0"));}
          else {
            v = findE0Code(sc);
            shift = (v >> 6) & 1;
            row = (v & 0b00111111) / 5;
            column = (v & 0b00111111) % 5;
            clearRow(row,column);
            if (shift) clearRow(0,0);
            scState = stPRESS;
          }
          break;
        case stRELEASE_E0:
          Serial.print(F("stRELEASE_E0:")); Serial.println(sc);
          if ((sc==0x59) | (sc==0x12)) { shiftPressed = false; Serial.println(F("SHIFT RELEASE"));}
          else {
            v = findE0Code(sc);
            shift = (v >> 6) & 1;
            row = (v & 0b00111111) / 5;
            column = (v & 0b00111111) % 5;
            setRow(row,column);
            if (shift) setRow(0,0);
            scState = stPRESS;
            Serial.print(F("SHIFTP:")); Serial.print(shiftPressed);
            Serial.print(F("shift:")); Serial.print(shift);
            Serial.print(F(" v:")); Serial.print(v);
            Serial.print(F(" row:")); Serial.print(row);
            Serial.print(F(" column:")); Serial.print(column);
            Serial.println();
          }
          scState = stPRESS;
          break;
         case stPRESS_E1_1:
          Serial.print(F("stPRESS_E1_1:")); Serial.println(sc);
          scState = stPRESS_E1_2;
          break;
         case stPRESS_E1_2:
          Serial.print(F("stPRESS_E1_2:")); Serial.println(sc);
          scState = stPRESS;
          break;
     }
     Serial.print(F("ShiftP:")); Serial.print(shiftPressed);
     Serial.print(F(" rows=(")); 
     Serial.print(rows[0]);Serial.print(F(", "));Serial.print(rows[1]);Serial.print(F(", "));Serial.print(rows[2]); Serial.print(F(", "));Serial.print(rows[3]);Serial.print(F(", "));
     Serial.print(rows[4]);Serial.print(F(", "));Serial.print(rows[5]);Serial.print(F(", "));Serial.print(rows[6]);Serial.print(F(", "));Serial.print(rows[7]);Serial.println(F(")"));
    }
  }
// Leer dato de canal 'channel'
  Wire.requestFrom(pcfAddress, 1 << channel);
  if (Wire.available())
  {
    value = Wire.read();
    if (JUP)      S[0]='U'; else S[0]=' ';
    if (JDOWN)    S[1]='D'; else S[1]=' ';
    if (JLEFT)    S[2]='L'; else S[2]=' ';
    if (JRIGHT)   S[3]='R'; else S[3]=' ';
    if (JBUTA)    S[4]='A'; else S[4]=' ';
    if (JBUTB)    S[5]='B'; else S[5]=' ';
    if (JTRIGER)  S[6]='T'; else S[6]=' ';
    if (STORE)    S[7]='S'; else S[7]=' ';
    S[8]=0;
    if (JUP) clearRow(2,0); else if (PREV_JUP) setRow(2,0); 
    if (JDOWN) clearRow(1,0); else if (PREV_JDOWN) setRow(1,0); 
    if (JLEFT) clearRow(5,1); else if (PREV_JLEFT) setRow(5,1); 
    if (JRIGHT) clearRow(5,0); else if (PREV_JRIGHT) setRow(5,0); 
    //if (JBUTB) clearRow(4,0); // else setRow(5,0); 
    if (JTRIGER) clearRow(4,0); else if (PREV_JTRIGER)setRow(4,0); 
    if (JBUTA) clearRow(6,0); else if (PREV_JBUTA) setRow(6,0); 
    prev_value=value;
  }
  Wire.endTransmission();

  // Mostrar el valor por puerto serie
  //Serial.println(rows[5]);
  u8g2.firstPage();
  do {
    u8g2.drawStr(0,24,S);
  } while ( u8g2.nextPage() );
  
  RESET
  for (int i=0; i<=7;i++){
    for (int j=0; j<=4; j++){
        digitalWrite(C[j],bitRead(rows[i],j));
    }
    CLOCK
  }
  Usb.Task();
}
