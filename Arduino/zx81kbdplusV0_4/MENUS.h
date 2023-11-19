#define MENU_DOWN   0
#define MENU_UP     1
#define MENU_ENTER  2
#define MENU_ESC    3
#define MENU_NONE   255

uint8_t get_menu_key(){
  value = 255;
  Wire.requestFrom(pcfAddress, 1 << channel);
  if (Wire.available())
  {
    value = Wire.read();
    if      (JDOWN) return MENU_DOWN;
    else if (JUP)   return MENU_UP;
    else if (JTRIGER) return MENU_ENTER;
    else if (JBUTA) return MENU_ESC;
  };
  readPS2Keyboard();
  if (downPressed) return MENU_DOWN;
  if (upPressed) return MENU_UP;
  if (enterPressed) return MENU_ENTER;
  if (F10Pressed || escPressed) return MENU_ESC;
  return MENU_NONE;
}

void waitNoKey(){
  uint8_t key=255;
  while (key=get_menu_key(),key!=MENU_NONE){
  };
}

void selectKeyboard(){
  uint8_t option = 0;
  uint8_t key;
  boolean menuEnd = false;
  do {
    u8g2.firstPage();
    do {
      u8g2.setDrawColor(1);
      u8g2_drawStringP(0,7,PSTR("CONFIG"));
      u8g2_drawStringP(0,24,PSTR("KEYBOARD"));
      u8g2.setDrawColor(2);
      u8g2.drawBox(0,0,48,8);
      u8g2.drawBox(0,16,48,8);
      if ((option >= 0) && (option < NUM_KEYBOARDS)) {
        strcpy_P(buffer, (char *)pgm_read_ptr(&(ps2IntlNames[option])));
        u8g2.drawStr(88,24,buffer); //ps2IntlNames[option]);
      } else {
        u8g2_drawStringP(88,24,PSTR("EXIT"));
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
            break;
          case 1:
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