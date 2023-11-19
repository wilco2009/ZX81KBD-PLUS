#define NUM_KEYBOARDS     3

typedef const uint8_t PROGMEM ps2intlCodes_array[NUM_INTL];
typedef const uint8_t PROGMEM ps2intlShiftedCodes_array[NUM_INTL_SHIFTED];

const uint8_t PROGMEM ps2intlCodes[NUM_INTL]=
{
  0x0e, // ROW 1 KEY 01 `
  0x4e, // ROW 1 KEY 12 -
  0x55, // ROW 1 KEY 13 = SHIFT + 31
  0x54, // ROW 2 KEY 12 [
  0x5b, // ROW 2 KEY 13 ]
  0x4c, // ROW 3 KEY 11 ;
  0x52, // ROW 3 KEY 12 '
  0x5d, // ROW 3 KEY 13 "\"
  0x61, // ROW 4 KEY 02 "\"
  0x41, // ROW 4 KEY 10 ,
  0x49, // ROW 4 KEY 11 .
  0x4a  // ROW 4 KEY 12 /
};

const uint8_t PROGMEM zxUSCodes[NUM_INTL]= {
  SHIFT + 25, // ROW 1 KEY 01 ` ---- "
  SHIFT + 33, // ROW 1 KEY 12 - ---- -
  SHIFT + 31, // ROW 1 KEY 13 = ---- =
  SHIFT + 27, // ROW 2 KEY 12 [ ---- (
  SHIFT + 26, // ROW 2 KEY 13 ] ---- )
  SHIFT +  2, // ROW 3 KEY 11 ; ---- ;
  SHIFT + 25, // ROW 3 KEY 12 ' ---- "
  SHIFT +  4, // ROW 3 KEY 13 "\" -- /
  SHIFT +  4, // ROW 4 KEY 02 "\" -- / 
  SHIFT + 36, // ROW 4 KEY 10 , ---- ,
  NULL  + 36, // ROW 4 KEY 11 . ---- .
  SHIFT +  4  // ROW 4 KEY 12 / ---- /
};

//ps2intlShiftedCodes_array zxUSShiftedCodes= {
const uint8_t PROGMEM zxUSShiftedCodes[NUM_INTL_SHIFTED]= {
  NULL  + 40, // ROW 1 KEY 01 ` ~
  NULL  + 40, // ROW 1 KEY 02 1 !
  NULL  + 40, // ROW 1 KEY 03 2 @
  NULL  + 40, // ROW 1 KEY 04 3 #
  SHIFT + 28, // ROW 1 KEY 05 4 $ ---- $
  NULL  + 40, // ROW 1 KEY 06 5 %
  SHIFT + 34, // ROW 1 KEY 07 6 ^ ---- **
  SHIFT + 35, // ROW 1 KEY 08 7 & ---- £
  SHIFT + 39, // ROW 1 KEY 09 8 * ---- *
  SHIFT + 27, // ROW 1 KEY 10 9 ( ---- (
  SHIFT + 26, // ROW 1 KEY 11 0 ) ---- )
  NULL  + 40, // ROW 1 KEY 12 - _
  SHIFT + 32, // ROW 1 KEY 13 = + ---- +
  NULL  + 40, // ROW 2 KEY 12 [ {
  NULL  + 40, // ROW 2 KEY 13 ] }
  SHIFT +  1, // ROW 3 KEY 11 ; : ---- :
  SHIFT + 25, // ROW 3 KEY 12 ' " ---- "
  NULL  + 40, // ROW 3 KEY 13 \ |
  NULL  + 40, // ROW 4 KEY 02 \ |
  SHIFT + 38, // ROW 4 KEY 10 , < ---- <
  SHIFT + 37, // ROW 4 KEY 11 . > ---- >
  SHIFT +  3  // ROW 4 KEY 12 / ? ---- ?
};

const uint8_t PROGMEM zxESCodes[NUM_INTL]= {
  SHIFT +  4, // ROW 1 KEY 01 ` ---- /
  SHIFT + 25, // ROW 1 KEY 12 - ---- "
  SHIFT +  3, // ROW 1 KEY 13 = ---- ?
  SHIFT + 25, // ROW 2 KEY 12 [ ---- "
  SHIFT + 32, // ROW 2 KEY 13 ] ---- +
  NULL  + 38, // ROW 3 KEY 11 ; ---- N
  SHIFT + 25, // ROW 3 KEY 12 ' ---- "
  NULL  +  3, // ROW 3 KEY 13 "\" -- C
  SHIFT + 38, // ROW 4 KEY 02 "\" -- < 
  SHIFT + 36, // ROW 4 KEY 10 , ---- ,
  NULL  + 36, // ROW 4 KEY 11 . ---- .
  SHIFT + 33  // ROW 4 KEY 12 / ---- -
};

const uint8_t PROGMEM zxESShiftedCodes[NUM_INTL_SHIFTED]= {
  NULL  + 40, // ROW 1 KEY 01 ` ~
  NULL  + 40, // ROW 1 KEY 02 1 !
  SHIFT + 25, // ROW 1 KEY 03 2 @ ---- "
  SHIFT + 28, // ROW 1 KEY 04 3 # ---- $
  NULL  + 40, // ROW 1 KEY 05 4 $ 
  NULL  + 40, // ROW 1 KEY 06 5 %
  SHIFT + 35, // ROW 1 KEY 07 6 ^ ---- £
  SHIFT +  4, // ROW 1 KEY 08 7 & ---- /
  SHIFT + 27, // ROW 1 KEY 09 8 * ---- (
  SHIFT + 26, // ROW 1 KEY 10 9 ( ---- )
  SHIFT + 31, // ROW 1 KEY 11 0 ) ---- =
  SHIFT +  3, // ROW 1 KEY 12 - _ ---- ?
  SHIFT +  3, // ROW 1 KEY 13 = + ---- ?
  SHIFT + 34, // ROW 2 KEY 12 [ { ---- **
  SHIFT + 39, // ROW 2 KEY 13 ] } ---- *
  NULL  + 38, // ROW 3 KEY 11 ; : ---- N
  SHIFT + 25, // ROW 3 KEY 12 ' " ---- " 
  NULL  +  3, // ROW 3 KEY 13 \ | ---- C
  SHIFT + 37, // ROW 4 KEY 02 \ | ---- >
  SHIFT +  2, // ROW 4 KEY 10 , < ---- ;
  SHIFT +  1, // ROW 4 KEY 11 . > ---- :
  SHIFT + 33  // ROW 4 KEY 12 / ? ---- -
};

ps2intlCodes_array *zxCodesList[NUM_KEYBOARDS] {
  &zxUSCodes,
  &zxUSCodes,
  &zxESCodes
};

ps2intlCodes_array *zxintlCodes = &zxUSCodes; 
ps2intlShiftedCodes_array *zxShiftedCodes = &zxUSShiftedCodes;

ps2intlShiftedCodes_array *zxShiftedCodesList[NUM_KEYBOARDS] {
  &zxUSShiftedCodes,
  &zxUSShiftedCodes,
  &zxESShiftedCodes
};

const char intlNames_0[] PROGMEM = "US";
const char intlNames_1[] PROGMEM = "UK";
const char intlNames_2[] PROGMEM = "ES";

const char *const ps2IntlNames[NUM_KEYBOARDS] PROGMEM={
  intlNames_0,
  intlNames_1,
  intlNames_2
};

void selectIntlKeyboard(uint8_t n){
  zxintlCodes = zxCodesList[n];
  zxShiftedCodes = zxShiftedCodesList[n];
  currentKeyboard = n;
}

uint8_t findShiftedCode(uint8_t sc){
  uint8_t v;
  int i = 0;
  do{
    v=pgm_read_byte_near((ps2ShiftedCodes)+i);    // ps2ShiftedCodes[i];
    if (sc==v) {
      //Serial.println(v);
      v = pgm_read_byte((*zxShiftedCodes)+i); // zxShiftedCodes[i]
      //Serial.println(v);
      return v;
    };
    i++;
  } while (i<NUM_INTL_SHIFTED);
  return NULL  + 40;
}

uint8_t findIntlCode(uint8_t sc){
  uint8_t v;
  int i = 0;
  do{
    v=pgm_read_byte_near((ps2intlCodes)+i);    // ps2ShiftedCodes[i];
    if (sc==v) {
      //Serial.println(v);
      v = pgm_read_byte((*zxintlCodes)+i); // zxShiftedCodes[i]
      //Serial.println(v);
      return v;
    };
    i++;
  } while (i<NUM_INTL);
  return NULL  + 40;
}