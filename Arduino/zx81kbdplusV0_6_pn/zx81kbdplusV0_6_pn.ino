#include <Wire.h>
#include <EEPROM.h>
#include <U8g2lib.h>
#include <hidboot.h>
#include <usbhub.h>
#include <SPI.h>
#include "KBDPARSER.h"
#include "PS2Keyboard.h"
#include "GLOBAL.h"
#include "SCANCODES.h"
#include "INTL.h"
#include "KEYBOARD.h"
#include "MENUS.h"
#include "LOGO.h"

#define RESET   digitalWrite(NRST, 0);  \
                delay(1);               \
                digitalWrite(NRST, 1);  \
                delay(1);               

 //delayMicroseconds(50);
 #define CLOCK  digitalWrite(CLK, 0);   \
                delay(1);               \
                digitalWrite(CLK, 1);   \
                delay(1);               

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
  //u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.setFont(u8g2_font_smallsimple_tr);
  u8g2.firstPage();
  do {
    u8g2.drawXBMP(0,0,ZXKBDPLUS_width,ZXKBDPLUS_height,ZXKBDPLUS_bits);
  } while ( u8g2.nextPage() );
  //SJOY[0] = 0;
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

  
  config_ver = EEPROM.read(0);
  switch (config_ver){
    case 1: 
      currentKeyboard = EEPROM.read(1);
      for (int i=0; i<7; i++){
        joyKeys[i] = EEPROM.read(i+2);
      }
      break;
    default:
      break;

  }
}

boolean button_pressed(){
  return CONFIG || F10Pressed;
}

// the loop function runs over and over again forever
void loop() {

  readPS2Keyboard();
// Leer dato de canal 'channel'
  Wire.requestFrom(pcfAddress, 1 << channel);
  if (Wire.available())
  {
    value = Wire.read();
    // if (JUP) clearRow(2,0); else if (PREV_JUP) setRow(2,0); 
    // if (JDOWN) clearRow(1,0); else if (PREV_JDOWN) setRow(1,0); 
    // if (JLEFT) clearRow(5,1); else if (PREV_JLEFT) setRow(5,1); 
    // if (JRIGHT) clearRow(5,0); else if (PREV_JRIGHT) setRow(5,0); 
    // //if (JBUTB) clearRow(4,0); // else setRow(5,0); 
    // if (JTRIGER) clearRow(4,0); else if (PREV_JTRIGER)setRow(4,0); 
    // if (JBUTA) clearRow(6,0); else if (PREV_JBUTA) setRow(6,0); 
    if (JUP) pressKey(joyKeys[UP]); else if (PREV_JUP) releaseKey(joyKeys[UP]); 
    if (JDOWN) pressKey(joyKeys[DOWN]); else if (PREV_JDOWN) releaseKey(joyKeys[DOWN]); 
    if (JLEFT) pressKey(joyKeys[LEFT]); else if (PREV_JLEFT) releaseKey(joyKeys[LEFT]); 
    if (JRIGHT) pressKey(joyKeys[RIGHT]); else if (PREV_JRIGHT) releaseKey(joyKeys[RIGHT]); 
    if (JBUTB) pressKey(joyKeys[BUTB]); else releaseKey(joyKeys[BUTB]); 
    if (JTRIGER) pressKey(joyKeys[TRIG]); else if (PREV_JTRIGER) releaseKey(joyKeys[TRIG]);  
    if (JBUTA) pressKey(joyKeys[BUTA]); else if (PREV_JBUTA) releaseKey(joyKeys[BUTA]); 
    prev_value=value;
  }
  Wire.endTransmission();

  // Mostrar el valor por puerto serie
  //Serial.println(rows[5]);
  displayKeyboard(false,0,0,0);  
  // displayJoystick();
  RESET
  for (int i=0; i<=7;i++){
    for (int j=0; j<=4; j++){
        digitalWrite(C[j],bitRead(rows[i],j));
    }
    CLOCK
  }
  Usb.Task();
  if (button_pressed()) {waitNoKey(); configMenu();}
}
