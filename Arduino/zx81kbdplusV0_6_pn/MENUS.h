#define MENU_DOWN   0
#define MENU_UP     1
#define MENU_ENTER  2
#define MENU_ESC    3
#define MENU_LEFT   4
#define MENU_RIGHT  5
#define MENU_NONE   255

uint8_t get_menu_key(){
  value = 255;
  Wire.requestFrom(pcfAddress, 1 << channel);
  if (Wire.available())
  {
    value = Wire.read();
    if      (JDOWN) return MENU_DOWN;
    else if (JUP)   return MENU_UP;
    else if (JRIGHT) return MENU_RIGHT;
    else if (JLEFT)   return MENU_LEFT;
    else if (JTRIGER) return MENU_ENTER;
    else if (JBUTA) return MENU_ESC;
  };
  readPS2Keyboard();
  Usb.Task();
  if (key_pressed){
          Serial.println(row_pressed);
          Serial.println(col_pressed);
  }
  if (downPressed) return MENU_DOWN;
  if (upPressed) return MENU_UP;
  if (leftPressed) return MENU_LEFT;
  if (rightPressed) return MENU_RIGHT;
  if (enterPressed || key_pressed) return MENU_ENTER;
  if (F10Pressed || escPressed) return MENU_ESC;
  return MENU_NONE;
}

void waitNoKey(){
  uint8_t key=255;
  while (key=get_menu_key(),key!=MENU_NONE){
  };
}

#define JOYKEY_TO_XY                \
        k = joyKeys[joykey];        \
        row = (k & 0b00111111) / 5; \
        col = (k & 0b00111111) % 5; \
        if (row<=3){                \
          x = col;                  \
          y = row;                  \
        } else {                    \
          x = 4-(col-5);            \
          y = 3-row+4;              \
        }

#define XY_TO_ROWCOL    \
    if (x<=4) {         \
      col = x;          \
      row = y;          \
    } else {            \
      col = 4-(x-5);    \
      row = 3-y+4;      \
    }       



void selectJoystick(){

  uint8_t key;
  uint8_t row=0;
  uint8_t col=0;
  uint8_t x=0;
  uint8_t y=0;
  uint8_t joykey = UP;

  uint8_t k;

  JOYKEY_TO_XY

  do {
    displayKeyboard(true,joykey,row,col);
    key_pressed = false;
    key = get_menu_key();
    switch (key){
      case MENU_UP:
        if (y<3) y++;
        waitNoKey();
        break;
      case MENU_DOWN:
        if (y>0) y--;
        waitNoKey();
        break;
      case MENU_LEFT:
        if (x>0) x--;
        waitNoKey();
        break;
      case MENU_RIGHT:
        if (x<9) x++;
        waitNoKey();
        break;
      case MENU_ENTER:
        if (key_pressed){
          k = row_pressed*5+col_pressed;
        } else 
          k = row*5+col; 
        joyKeys[joykey]=k;
        joykey++;
        JOYKEY_TO_XY
        waitNoKey();
        break;
      case MENU_ESC:
        joykey++;
        JOYKEY_TO_XY
        waitNoKey();
        break;
    }
    XY_TO_ROWCOL
  } while (joykey<7);
  waitNoKey();
}

void selectKeyboard(){
  uint8_t option;
  option = currentKeyboard;
  uint8_t key;
  boolean menuEnd = false;
  do {
    u8g2.firstPage();
    do {
      u8g2.setDrawColor(1);
      u8g2_drawStringP(60,7,PSTR("*"));
      strcpy_P(buffer, (char *)pgm_read_ptr(&(ps2IntlNames[currentKeyboard])));
      u8g2.drawStr(68,7,buffer); //ps2IntlNames[option]);
      u8g2_drawStringP(60,16,PSTR("UP/DOWN TO SEL"));
      u8g2_drawStringP(0,7,PSTR("CONFIG"));
      u8g2_drawStringP(0,24,PSTR("KEYBOARD"));
      u8g2.setDrawColor(2);
      u8g2.drawBox(0,0,48,8);
      u8g2.drawBox(0,16,48,8);
      u8g2.drawBox(60,0,48,8);
      if ((option >= 0) && (option < NUM_KEYBOARDS)) {
        if (currentKeyboard==option)
          u8g2.drawGlyph(60, 31, '*');
        strcpy_P(buffer, (char *)pgm_read_ptr(&(ps2IntlNames[option])));
        u8g2.drawStr(68,31,buffer); //ps2IntlNames[option]);
      } else {
        u8g2_drawStringP(68,31,PSTR("EXIT"));
      }
    } while ( u8g2.nextPage() );
    key = get_menu_key();
    switch (key){
      case MENU_DOWN: 
        if (option < NUM_KEYBOARDS+1)
          option++;
        else option = 0;
        waitNoKey();
        break;
      case MENU_UP:   
        if (option > 0)
          option--;
        else option = 2;
        waitNoKey();
        break;
      case MENU_ENTER:
        waitNoKey();
        selectIntlKeyboard(option);
        menuEnd = true;
        break;
      case MENU_ESC:
        waitNoKey();
        menuEnd = true;
        break;
    }
  } while (!menuEnd);
}

void configMenu(){
  uint8_t option = 0;
  uint8_t key;
  boolean menuEnd = false;
  do {
    u8g2.firstPage();
    do {
      u8g2.setDrawColor(1);
      u8g2_drawStringP(60,7,PSTR("UP/DOWN TO SEL"));
      u8g2_drawStringP(0,7,PSTR("CONFIG"));
      u8g2.setDrawColor(2);
      u8g2.drawBox(0,0,48,8);
      switch (option){
        case 0: 
          u8g2_drawStringP(0,24,PSTR("KEYBOARD"));
          break;
        case 1: 
          u8g2_drawStringP(0,24,PSTR("JOYSTICK"));
          break;
        case 2: 
          u8g2_drawStringP(0,24,PSTR("EXIT"));
          break;
      }
    } while ( u8g2.nextPage() );
    key = get_menu_key();
    switch (key){
      case MENU_DOWN: 
        if (option < 2)
          option++;
        else option = 0;
        waitNoKey();
        break;
      case MENU_UP:   
        if (option > 0)
          option--;
        else option = 2;
        waitNoKey();
        break;
      case MENU_ENTER:
        waitNoKey();
        switch (option) {
          case 0:
            selectKeyboard();
            saveConfig();
            break;
          case 1:
            selectJoystick();
            saveConfig();
            break;
          case 2: 
            menuEnd = true;
            break;
        }   
        break;
      case MENU_ESC:
        waitNoKey();
        menuEnd = true;
        break;
    }
  } while (!menuEnd);
}