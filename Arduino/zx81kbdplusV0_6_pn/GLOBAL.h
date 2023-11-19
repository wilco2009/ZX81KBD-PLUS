#define CONFIG_VER 1

const int DataPin = A2;
const int IRQpin =  3;

#define CLK   A3 
#define NRST  A6
#define C0    A1
#define C1    2
#define C2    4
#define C3    5
#define C4    6

#define UP    0
#define DOWN  1
#define LEFT  2
#define RIGHT 3
#define BUTB  4
#define TRIG  5
#define BUTA  6

#define JUP     (value & 1)==0
#define JDOWN   (value & 2)==0
#define JLEFT   (value & 4)==0
#define JRIGHT  (value & 8)==0
#define JBUTB   (value & 16)==0
#define JTRIGER (value & 32)==0
#define JBUTA   (value & 64)==0
#define CONFIG  (value & 128)==0
#define BLINK (millis() % 64) <32

#define PREV_JUP     (prev_value & 1)==0
#define PREV_JDOWN   (prev_value & 2)==0
#define PREV_JLEFT   (prev_value & 4)==0
#define PREV_JRIGHT  (prev_value & 8)==0
#define PREV_JBUTB   (prev_value & 16)==0
#define PREV_JTRIGER (prev_value & 32)==0
#define PREV_JBUTA   (prev_value & 64)==0

uint8_t config_ver;
uint8_t currentKeyboard = 0;

uint8_t joyKeys[] = {
  10,   // UP = Q
  5,    // DOWN = A
  26,   // LEFT = O
  25,   // RIGHT = P
  35,   // BUTB = SPACE
  20,   // TRIG = 
  30    // BUTA = ENTER
};
char buffer[10];


void saveConfig(){
  EEPROM.update(0,CONFIG_VER);
  EEPROM.update(1,currentKeyboard);
  for (int i=0; i<7; i++){
    EEPROM.update(i+2,joyKeys[i]);
  }
}


uint8_t C[5]={C0,C1,C2,C3,C4};
uint8_t rows[8]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
//char SJOY[10] ="QAOP0>          ";
    // if (JUP)      SJOY[0]='U'; else SJOY[0]=' ';
    // if (JDOWN)    SJOY[1]='D'; else SJOY[1]=' ';
    // if (JLEFT)    SJOY[2]='L'; else SJOY[2]=' ';
    // if (JRIGHT)   SJOY[3]='R'; else SJOY[3]=' ';
    // if (JBUTA)    SJOY[4]='A'; else SJOY[4]=' ';
    // if (JBUTB)    SJOY[5]='B'; else SJOY[5]=' ';
    // if (JTRIGER)  SJOY[6]='T'; else SJOY[6]=' ';
    // if (CONFIG)   SJOY[7]='C'; else SJOY[7]=' ';

uint8_t value = 255;
uint8_t prev_value = 255;
U8G2_SSD1306_128X32_UNIVISION_1_HW_I2C u8g2(U8G2_R2); //, /* clock=*/ 21, /* data=*/ 20, /* reset=*/ U8X8_PIN_NONE);   // Adafruit Feather M0 Basic Proto + FeatherWing OLED
const int pcfAddress = 0x20;
short channel = 1;

void u8g2_drawStringP(uint8_t x, uint8_t y, const char * progmem_ptr) {
  u8g2.setCursor(x, y);
  u8g2.print((const __FlashStringHelper *)progmem_ptr);  // use arduino progmem print
}

const char keys[8][5]={
  {'s','Z','X','C','V'},
  {'A','S','D','F','G'},
  {'Q','W','E','R','T'},
  {'1','2','3','4','5'},

  {'0','9','8','7','6'},
  {'P','O','I','U','Y'},
  {'>','L','K','J','H'},
  {'-','.','M','N','B'}
};

uint8_t ch_w = 8;
uint8_t ch_h = 8;

char getCharKey(uint8_t key){
  uint8_t row = (key & 0b00111111) / 5;
  uint8_t column = (key & 0b00111111) % 5;
  return keys[row][column];
}

