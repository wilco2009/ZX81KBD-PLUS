boolean ctrlPressed = false; 
 
class KbdRptParser : public KeyboardReportParser
{
    void PrintKey(uint8_t mod, uint8_t key);

  protected:
    void OnControlKeysChanged(uint8_t before, uint8_t after);

    void OnKeyDown	(uint8_t mod, uint8_t key);
    void OnKeyUp	(uint8_t mod, uint8_t key);
    void OnKeyPressed(uint8_t key);
};

void KbdRptParser::PrintKey(uint8_t m, uint8_t key)
{
  MODIFIERKEYS mod;
  *((uint8_t*)&mod) = m;
  Serial.print((mod.bmLeftCtrl   == 1) ? "C" : " ");
  Serial.print((mod.bmLeftShift  == 1) ? "S" : " ");
  Serial.print((mod.bmLeftAlt    == 1) ? "A" : " ");
  Serial.print((mod.bmLeftGUI    == 1) ? "G" : " ");

  Serial.print(" >");
  PrintHex<uint8_t>(key, 0x80);
  Serial.print("< ");

  Serial.print((mod.bmRightCtrl   == 1) ? "C" : " ");
  Serial.print((mod.bmRightShift  == 1) ? "S" : " ");
  Serial.print((mod.bmRightAlt    == 1) ? "A" : " ");
  Serial.println((mod.bmRightGUI    == 1) ? "G" : " ");
};

void KbdRptParser::OnKeyDown(uint8_t mod, uint8_t sc)
{
  uint8_t v;
  // uint8_t sc;
  uint8_t shift;
  uint8_t row;
  uint8_t column;
  
  shiftPressed = (bitRead(mod,1)==1)||(bitRead(mod,5)==1);
  //ctrlPressed = (bitRead(mod,0)==1)||(bitRead(mod,4)==1);
  // Serial.println(shiftPressed);

  if (shiftPressed){
    v = findUSBShiftedCode(sc);
    // Serial.println(sc);
    // Serial.println(v);
    //if (v==(NULL  + 40))
    //  v = ps2Codes[sc];
  } else {
    if (sc==0x43) F10Pressed = true;
    if (sc==0x28) enterPressed = true;
    if (sc==0x29) escPressed = true;
    v = findUSBIntlCode(sc);
    if (v == (NULL  + 40)){
      v = pgm_read_byte_near(USBCodes+sc);
    };// else Serial.println(F("INTL"));
  }
  shift = ((v >> 6) & 1);
  row = (v & 0b00111111) / 5;
  column = (v & 0b00111111) % 5;
  if ((shift==0) && (v!=0) && (v!=30) && (v!=36)){
    key_pressed = true;
    row_pressed = row;
    col_pressed = column;
  }
  clearRow(row,column);
// Serial.println(sc);
// Serial.println(row);
// Serial.println(column);
// for (uint8_t i=0;i<8;i++){
//   Serial.print(rows[i]);
//   Serial.print(",");
// }
//  Serial.println(rows[7]);
  if (shift /*|| ctrlPressed*/) clearRow(0,0);

  // Serial.print("DN ");
  // PrintKey(mod, key);
  // uint8_t c = OemToAscii(mod, key);

  // if (c)
  //   OnKeyPressed(c);
}

void KbdRptParser::OnControlKeysChanged(uint8_t before, uint8_t after) {
  boolean newCtrlStatus;
  newCtrlStatus = (bitRead(after,0)==1)||(bitRead(after,4)==1);
  if (ctrlPressed != newCtrlStatus) {
    ctrlPressed = newCtrlStatus; 
    if (ctrlPressed) clearRow(0,0);
    else setRow(0,0);
  }


}

void KbdRptParser::OnKeyUp(uint8_t mod, uint8_t sc)
{
  uint8_t v;
  //uint8_t sc;
  uint8_t shift;
  uint8_t row;
  uint8_t column;

  //  Serial.print("UP ");
  //  PrintKey(mod, sc);
  shiftPressed = (bitRead(mod,1)==1)||(bitRead(mod,5)==1);
  if (shiftPressed){
    v = findUSBShiftedCode(sc);
    //if (v==(NULL  + 40))
    //  v = ps2Codes[sc];
  } else {
    if (sc==0x43) F10Pressed = false;
    if (sc==0x28) enterPressed = false;
    if (sc==0x29) escPressed = false;
    v = findUSBIntlCode(sc);
    if (v == (NULL  + 40)){
      v = pgm_read_byte_near(USBCodes+sc);
    };// else Serial.println(F("INTL"));
  }
  shift = (v >> 6) & 1;
  row = (v & 0b00111111) / 5;
  column = (v & 0b00111111) % 5;
  key_pressed = false;
  setRow(row,column);
// Serial.println(sc);
// Serial.println(row);
// Serial.println(column);
// for (uint8_t i=0;i<8;i++){
  // Serial.print(rows[i]);
  // Serial.print(",");
// }
// Serial.println();
  if (shift/* || ctrlPressed*/) setRow(0,0);
}

void KbdRptParser::OnKeyPressed(uint8_t key)
{
  // Serial.print("ASCII: ");
  // Serial.println((char)key);
};
