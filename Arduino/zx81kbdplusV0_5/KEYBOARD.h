PS2Keyboard keyboard;
boolean shiftPressed = false;
boolean F10Pressed = false;
boolean enterPressed = false;
boolean upPressed = false;
boolean downPressed = false;
boolean leftPressed = false;
boolean rightPressed = false;
boolean escPressed = false;

void inline setRow(uint8_t row, uint8_t col){
  bitSet(rows[row],col);
}

void inline clearRow(uint8_t row, uint8_t col){
  bitClear(rows[row],col);
}

void displayKeyboard(boolean select, uint8_t joykey, uint8_t rowSelected, uint8_t colSelected){
  u8g2.firstPage();
  do {
    u8g2.setDrawColor(1);
    u8g2.drawFrame(0,0,10*ch_w,4*ch_h);    
    u8g2.drawFrame(103,7,25,24);    
    u8g2.drawFrame(10*ch_w+24,0,24,8);    
    u8g2.drawFrame(10*ch_w,0,24,4*ch_h);    
    u8g2.setDrawColor(2);
    //Serial.println("KEY");
    for (int i=0;i<8;i++){
      for (int j=0;j<5;j++){
        uint8_t x = i<4?(j*ch_w):((4-j)*ch_w+5*ch_w);
        uint8_t y = i<4?(32-(i*ch_h)):(i-4)*ch_h+8;
        // char ch = pgm_read_byte(keys+i*5+j);
        char ch = keys[i][j];
        //Serial.print(ch);
        u8g2.setDrawColor(1);
        u8g2.drawGlyph(x+2, y, ch);
        if (select && (rowSelected==i) && (colSelected==j))
          u8g2.drawFrame(x,y-7,ch_w,ch_h);
        u8g2.setDrawColor(2);
        if (bitRead(rows[i],j)==0) {
          u8g2.drawBox(x,y-7,ch_w,ch_h);
        }
      }
      //Serial.println();
    }
    u8g2.drawGlyph(89, 7, getCharKey(joyKeys[UP]));//SJOY[0]);
    if (select){
      u8g2.drawGlyph(89, 31, getCharKey(joyKeys[DOWN]));// SJOY[1]);
      u8g2.drawGlyph(81, 19, getCharKey(joyKeys[LEFT]));// SJOY[2]);
      u8g2.drawGlyph(97, 19, getCharKey(joyKeys[RIGHT]));// SJOY[3]);
      u8g2.drawGlyph(105, 7, getCharKey(joyKeys[TRIG]));// SJOY[4]);
      u8g2.drawGlyph(113, 7, getCharKey(joyKeys[BUTA]));// SJOY[5]);
      u8g2.drawGlyph(121, 7, getCharKey(joyKeys[BUTB]));// SJOY[6]);
      switch (joykey){
        case UP:
          //Serial.println(millis() % 64);
          if (BLINK) {
            u8g2.drawBox(87,0,ch_w,ch_h);
            //Serial.println("2");
          }
          break; 
        case DOWN:
          if (BLINK) u8g2.drawBox(87,24,ch_w,ch_h);
          break; 
        case LEFT:
          if (BLINK) u8g2.drawBox(79,12,ch_w,ch_h);
          break; 
        case RIGHT:
          if (BLINK) u8g2.drawBox(95,12,ch_w,ch_h);
          break; 
        case TRIG:
          if (BLINK) u8g2.drawBox(103,0,ch_w,ch_h);
          break; 
        case BUTA:
          if (BLINK) u8g2.drawBox(111,0,ch_w,ch_h);
          break; 
        case BUTB:
          if (BLINK) u8g2.drawBox(119,0,ch_w,ch_h);
          break; 
      } 
    } else {
      if (JUP) u8g2.drawBox(87,0,ch_w,ch_h);
      u8g2.drawGlyph(89, 31, getCharKey(joyKeys[DOWN]));// SJOY[1]);
      if (JDOWN) u8g2.drawBox(87,24,ch_w,ch_h);
      u8g2.drawGlyph(81, 19, getCharKey(joyKeys[LEFT]));// SJOY[2]);
      if (JLEFT) u8g2.drawBox(79,12,ch_w,ch_h);
      u8g2.drawGlyph(97, 19, getCharKey(joyKeys[RIGHT]));// SJOY[3]);
      if (JRIGHT) u8g2.drawBox(95,12,ch_w,ch_h);
      u8g2.drawGlyph(105, 7, getCharKey(joyKeys[TRIG]));// SJOY[4]);
      if (JTRIGER) u8g2.drawBox(103,0,ch_w,ch_h);
      u8g2.drawGlyph(113, 7, getCharKey(joyKeys[BUTA]));// SJOY[5]);
      if (JBUTA) u8g2.drawBox(111,0,ch_w,ch_h);
      u8g2.drawGlyph(121, 7, getCharKey(joyKeys[BUTB]));// SJOY[6]);
      if (JBUTB) u8g2.drawBox(119,0,ch_w,ch_h);
      strcpy_P(buffer, (char *)pgm_read_ptr(&(ps2IntlNames[currentKeyboard])));
      u8g2.drawStr(104,30,buffer);
    } 
  } while ( u8g2.nextPage() );
  u8g2.setDrawColor(1);

}

void pressKey(uint8_t key){
  uint8_t row = (key & 0b00111111) / 5;
  uint8_t column = (key & 0b00111111) % 5;
  clearRow(row,column);
}

void releaseKey(uint8_t key){
  uint8_t row = (key & 0b00111111) / 5;
  uint8_t column = (key & 0b00111111) % 5;
  setRow(row,column);
}

void readPS2Keyboard(){
  uint8_t v;
  uint8_t shift;
  uint8_t row;
  uint8_t column;
  //memset(rows,0xff,8);

  /*if (keyboard.available()) {*/
    uint8_t sc = keyboard.readScanCode();
    //char sc = keyboard.read();
    if (sc!=0) {
      //  Serial.print(F("code: "));
      //  Serial.println(sc);
      switch (scState){
        case stPRESS:
        // Serial.print(F("stPRESS:")); Serial.println(sc);
        if (sc==0xF0) scState = stRELEASE;
          else if (sc==0xE0) scState = stPRESS_E0;
          else if (sc==0xE1) scState = stPRESS_E1_1;
          else if ((sc==0x59) | (sc==0x12)) {shiftPressed = true; /*Serial.println(F("SHIFT"));*/}
          else {
             if (sc==0x09) F10Pressed = true;
             if (sc==0x5a) enterPressed = true;
             if (sc==0x76) escPressed = true;
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
            // Serial.print(F("SHIFTP:")); Serial.print(shiftPressed);
            // Serial.print(F("shift:")); Serial.print(shift);
            // Serial.print(F(" v:")); Serial.print(v);
            // Serial.print(F(" row:")); Serial.print(row);
            // Serial.print(F(" column:")); Serial.print(column);
            // Serial.println();
          }
          break;
        case stRELEASE:
          // Serial.print("stRELEASE:"); Serial.println(sc);
          if ((sc==0x59) | (sc==0x12)) { shiftPressed = false; /*Serial.println(F("SHIFT RELEASE"));*/}
          else {
             if (sc==0x09) F10Pressed = false;
             if (sc==0x5a) enterPressed = false;
             if (sc==0x76) escPressed = false;
             if (shiftPressed){
              v = findShiftedCode(sc);
              //if (v==(NULL  + 40))
              //  v = ps2Codes[sc];
             }
              else {
                v = findIntlCode(sc);
                if (v == (NULL  + 40))
                  v = pgm_read_byte_near(ps2Codes+sc);
              }
            shift = (v >> 6) & 1;
            row = (v & 0b00111111) / 5;
            column = (v & 0b00111111) % 5;
            setRow(row,column);
            if (shift) setRow(0,0);
            scState = stPRESS;
            // Serial.print(F("SHIFTP:")); Serial.print(shiftPressed);
            // Serial.print(F("shift:")); Serial.print(shift);
            // Serial.print(F(" v:")); Serial.print(v);
            // Serial.print(F(" row:")); Serial.print(row);
            // Serial.print(F(" column:")); Serial.print(column);
            // Serial.println();
          }
          scState = stPRESS;
          break;
        case stPRESS_E0:
          // Serial.print(F("stPRESS_E0:")); Serial.println(sc);
          if (sc==0xF0) {scState = stRELEASE_E0; /*Serial.println(F("GO TO RELEASE E0"));*/}
          else {
            if (sc==0x75) upPressed = true;
            if (sc==0x72) downPressed = true;
            if (sc==0x6b) leftPressed = true;
            if (sc==0x74) rightPressed = true;
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
          // Serial.print(F("stRELEASE_E0:")); Serial.println(sc);
          if ((sc==0x59) | (sc==0x12)) { shiftPressed = false; /*Serial.println(F("SHIFT RELEASE"));*/}
          else {
            if (sc==0x75) upPressed = false;
            if (sc==0x72) downPressed = false;
            if (sc==0x6b) leftPressed = true;
            if (sc==0x74) rightPressed = true;
            v = findE0Code(sc);
            shift = (v >> 6) & 1;
            row = (v & 0b00111111) / 5;
            column = (v & 0b00111111) % 5;
            setRow(row,column);
            if (shift) setRow(0,0);
            scState = stPRESS;
            // Serial.print(F("SHIFTP:")); Serial.print(shiftPressed);
            // Serial.print(F("shift:")); Serial.print(shift);
            // Serial.print(F(" v:")); Serial.print(v);
            // Serial.print(F(" row:")); Serial.print(row);
            // Serial.print(F(" column:")); Serial.print(column);
            // Serial.println();
          }
          scState = stPRESS;
          break;
         case stPRESS_E1_1:
          // Serial.print(F("stPRESS_E1_1:")); Serial.println(sc);
          scState = stPRESS_E1_2;
          break;
         case stPRESS_E1_2:
          // Serial.print(F("stPRESS_E1_2:")); Serial.println(sc);
          scState = stPRESS;
          break;
     }
    //  Serial.print(F("ShiftP:")); Serial.print(shiftPressed);
    //  Serial.print(F(" rows=(")); 
    //  Serial.print(rows[0]);Serial.print(F(", "));Serial.print(rows[1]);Serial.print(F(", "));Serial.print(rows[2]); Serial.print(F(", "));Serial.print(rows[3]);Serial.print(F(", "));
    //  Serial.print(rows[4]);Serial.print(F(", "));Serial.print(rows[5]);Serial.print(F(", "));Serial.print(rows[6]);Serial.print(F(", "));Serial.print(rows[7]);Serial.println(F(")"));
    //}
  }
}