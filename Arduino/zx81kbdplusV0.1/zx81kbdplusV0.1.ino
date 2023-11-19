#include <Wire.h>
#include <U8g2lib.h>
#include <hidboot.h>
#include <usbhub.h>
#include <SPI.h>
#include "KBDPARSER.h"
#include <PS2Keyboard.h>
#include "SCANCODES.h"

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
  Serial.println("START");
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
    Serial.println("OSC did not start.");
  else
    Serial.println("OSC started.");

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

// the loop function runs over and over again forever
void loop() {
  short channel = 1;
  byte value = 0;
  //memset(rows,0xff,8);

  if (keyboard.available()) {
    uint8_t sc = keyboard.readScanCode();
    //char sc = keyboard.read();
    if (sc!=0) {
      //Serial.println(sc);
      switch (scState){
        case stPRESS:
          if (sc==0xF0) scState = stRELEASE;
          else {
            uint8_t v = ps2Codes[sc];
            uint8_t shift = v >> 5;
            uint8_t row = (v & 0b00111111) / 5;
            uint8_t column = (v & 0b00111111) % 5;
            bitClear(rows[row],column);
            if (shift) bitClear(rows[0],0);
            // Serial.print("PRESS: ");
            // Serial.print(v);
            // Serial.print("SFT: ");
            // Serial.print(shift);
            // Serial.print("ROW: ");
            // Serial.print(row);
            // Serial.print("COL: ");
            // Serial.print(column);
            // Serial.println();
          }
          break;
        case stRELEASE:
            uint8_t v = ps2Codes[sc];
            uint8_t shift = v >> 5;
            uint8_t row = (v & 0b00111111) / 5;
            uint8_t column = (v & 0b00111111) % 5;
            setRow(row,column);
            if (shift) setRow(0,0);
            scState = stPRESS;
            // Serial.println("RELEASE");
          break;
      }
      Serial.println(sc);
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
    if (JUP) bitClear(rows[2],0); else if (PREV_JUP) bitSet(rows[2],0); 
    if (JDOWN) bitClear(rows[1],0); else if (PREV_JDOWN) bitSet(rows[1],0); 
    if (JLEFT) bitClear(rows[5],1); else if (PREV_JLEFT) bitSet(rows[5],1); 
    if (JRIGHT) bitClear(rows[5],0); else if (PREV_JRIGHT) bitSet(rows[5],0); 
    //if (JBUTB) bitClear(rows[4],0); // else bitSet(rows[5],0); 
    if (JTRIGER) bitClear(rows[4],0); else if (PREV_JTRIGER)bitSet(rows[4],0); 
    if (JBUTA) bitClear(rows[6],0); else if (PREV_JBUTA) bitSet(rows[6],0); 
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
