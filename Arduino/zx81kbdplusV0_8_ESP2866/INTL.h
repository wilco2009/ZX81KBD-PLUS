#define NUM_KEYBOARDS     5
#if defined (__AVR__)

typedef const uint8_t PROGMEM ps2intlCodes_array[NUM_INTL];
typedef const uint8_t PROGMEM ps2intlShiftedCodes_array[NUM_INTL_SHIFTED];
#else
typedef const uint8_t ps2intlCodes_array[NUM_INTL];
typedef const uint8_t ps2intlShiftedCodes_array[NUM_INTL_SHIFTED];
#endif

#ifdef PS2

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
#endif
#ifdef USB
const uint8_t PROGMEM USBintlCodes[NUM_INTL]=
{
  0x35, // ROW 1 KEY 01 `
  0x2d, // ROW 1 KEY 12 -
  0x2e, // ROW 1 KEY 13 = SHIFT + 31
  0x2f, // ROW 2 KEY 12 [
  0x30, // ROW 2 KEY 13 ]
  0x33, // ROW 3 KEY 11 ;
  0x34, // ROW 3 KEY 12 '
  0x32, // ROW 3 KEY 13 "\"
  0x64, // ROW 4 KEY 02 "\"
  0x36, // ROW 4 KEY 10 ,
  0x37, // ROW 4 KEY 11 .
  0x38  // ROW 4 KEY 12 /
};
#endif
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

// const uint8_t PROGMEM zxUKCodes[NUM_INTL]= {
//   SHIFT + 25, // ROW 1 KEY 01 ` ---- "
//   SHIFT + 33, // ROW 1 KEY 12 - ---- -
//   SHIFT + 31, // ROW 1 KEY 13 = ---- =
//   SHIFT + 27, // ROW 2 KEY 12 [ ---- (
//   SHIFT + 26, // ROW 2 KEY 13 ] ---- )
//   SHIFT +  2, // ROW 3 KEY 11 ; ---- ;
//   SHIFT + 25, // ROW 3 KEY 12 ' ---- "
//   SHIFT +  4, // ROW 3 KEY 13 "\" -- /
//   SHIFT +  4, // ROW 4 KEY 02 "\" -- / 
//   SHIFT + 36, // ROW 4 KEY 10 , ---- ,
//   NULL  + 36, // ROW 4 KEY 11 . ---- .
//   SHIFT +  4  // ROW 4 KEY 12 / ---- /
// };

const uint8_t PROGMEM zxUKShiftedCodes[NUM_INTL_SHIFTED]= {
  NULL  + 40, // ROW 1 KEY 01 ` ~
  NULL  + 40, // ROW 1 KEY 02 1 !
  SHIFT + 25, // ROW 1 KEY 03 2 "
  SHIFT + 35, // ROW 1 KEY 04 3 £
  SHIFT + 28, // ROW 1 KEY 05 4 $ ---- $
  NULL  + 40, // ROW 1 KEY 06 5 %
  SHIFT + 34, // ROW 1 KEY 07 6 ^ ---- **
  NULL  + 40, // ROW 1 KEY 08 7 &
  SHIFT + 39, // ROW 1 KEY 09 8 * ---- *
  SHIFT + 27, // ROW 1 KEY 10 9 ( ---- (
  SHIFT + 26, // ROW 1 KEY 11 0 ) ---- )
  NULL  + 40, // ROW 1 KEY 12 - _
  SHIFT + 32, // ROW 1 KEY 13 = + ---- +
  NULL  + 40, // ROW 2 KEY 12 [ {
  NULL  + 40, // ROW 2 KEY 13 ] }
  SHIFT +  1, // ROW 3 KEY 11 ; : ---- :
  NULL  + 40, // ROW 3 KEY 12 ' @
  NULL  + 40, // ROW 3 KEY 13 # ~
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

const uint8_t PROGMEM zxDECodes[NUM_INTL]= {
  NULL  + 40, // ROW 1 KEY 01 ^
  NULL  + 40, // ROW 1 KEY 12 beta 
  SHIFT + 31, // ROW 1 KEY 13 ´ ---- "
  NULL  + 40, // ROW 2 KEY 12 ü
  SHIFT +  3, // ROW 2 KEY 13 + ---- +
  NULL  + 40, // ROW 3 KEY 11 ö
  NULL  + 40, // ROW 3 KEY 12 ä 
  SHIFT + 25, // ROW 3 KEY 13 "'" -- "
  SHIFT + 38, // ROW 4 KEY 02 "<" -- < 
  SHIFT + 36, // ROW 4 KEY 10 , ---- ,
  NULL  + 36, // ROW 4 KEY 11 . ---- .
  SHIFT + 33  // ROW 4 KEY 12 - ---- -
};

const uint8_t PROGMEM zxDEShiftedCodes[NUM_INTL_SHIFTED]= {
  NULL  + 40, // ROW 1 KEY 01 ^ º
  NULL  + 40, // ROW 1 KEY 02 1 !
  SHIFT + 25, // ROW 1 KEY 03 2 "
  NULL  + 40, // ROW 1 KEY 04 3 #
  SHIFT + 28, // ROW 1 KEY 05 4 $ ---- $
  NULL  + 40, // ROW 1 KEY 06 5 %
  SHIFT + 35, // ROW 1 KEY 07 6 & ---- £
  SHIFT + 33, // ROW 1 KEY 08 7 / ---- /
  SHIFT + 27, // ROW 1 KEY 09 8 ( ---- (
  SHIFT + 26, // ROW 1 KEY 10 9 ) ---- )
  SHIFT + 31, // ROW 1 KEY 11 0 = ---- =
  NULL  +  3, // ROW 1 KEY 12 BETA ?
  SHIFT + 25, // ROW 1 KEY 13 ´ ` ---- "
  NULL  + 40, // ROW 2 KEY 12 ü Ü 
  SHIFT + 27, // ROW 2 KEY 13 + *
  NULL  + 40, // ROW 3 KEY 11 ö Ö
  NULL  + 40, // ROW 3 KEY 12 ä Ä
  SHIFT + 25, // ROW 3 KEY 13 # '
  SHIFT + 37, // ROW 4 KEY 02 < >
  SHIFT +  2, // ROW 4 KEY 10 , ;
  SHIFT +  1, // ROW 4 KEY 11 . :
  SHIFT + 33  // ROW 4 KEY 12 - _
};

const uint8_t PROGMEM zxITCodes[NUM_INTL]= {
  SHIFT +  4, // ROW 1 KEY 01 \
  SHIFT + 31, // ROW 1 KEY 12 ' 
  NULL  + 40, // ROW 1 KEY 13 ì
  NULL  + 40, // ROW 2 KEY 12 è
  SHIFT + 27, // ROW 2 KEY 13 +
  NULL  + 40, // ROW 3 KEY 11 ò
  NULL  + 40, // ROW 3 KEY 12 à 
  NULL  + 40, // ROW 3 KEY 13 ù
  SHIFT + 38, // ROW 4 KEY 02 "<" -- < 
  SHIFT + 36, // ROW 4 KEY 10 , ---- ,
  NULL  + 36, // ROW 4 KEY 11 . ---- .
  SHIFT + 33  // ROW 4 KEY 12 - ---- -
};

const uint8_t PROGMEM zxITShiftedCodes[NUM_INTL_SHIFTED]= {
  NULL  + 40, // ROW 1 KEY 01 \ |
  NULL  + 40, // ROW 1 KEY 02 1 !
  SHIFT + 25, // ROW 1 KEY 03 2 "
  SHIFT + 35, // ROW 1 KEY 04 3 £
  SHIFT + 28, // ROW 1 KEY 05 4 $ ---- $
  NULL  + 40, // ROW 1 KEY 06 5 %
  SHIFT + 35, // ROW 1 KEY 07 6 & ---- £
  SHIFT + 33, // ROW 1 KEY 08 7 / ---- /
  SHIFT + 27, // ROW 1 KEY 09 8 ( ---- (
  SHIFT + 26, // ROW 1 KEY 10 9 ) ---- )
  SHIFT + 31, // ROW 1 KEY 11 0 = ---- =
  NULL  +  3, // ROW 1 KEY 12 ' ?
  SHIFT + 34, // ROW 1 KEY 13 ì ^ ---- **
  NULL  + 40, // ROW 2 KEY 12 è é 
  SHIFT + 27, // ROW 2 KEY 13 + *
  NULL  + 40, // ROW 3 KEY 11 ò ç
  NULL  + 40, // ROW 3 KEY 12 à º
  NULL  + 40, // ROW 3 KEY 13 ù 
  SHIFT + 37, // ROW 4 KEY 02 < >
  SHIFT +  2, // ROW 4 KEY 10 , ;
  SHIFT +  1, // ROW 4 KEY 11 . :
  SHIFT + 33  // ROW 4 KEY 12 - _
};
ps2intlCodes_array *zxCodesList[NUM_KEYBOARDS] {
  &zxUSCodes,
  &zxUSCodes,
  &zxESCodes,
  &zxDECodes,
  &zxITCodes
};
ps2intlCodes_array *zxintlCodes = &zxUSCodes; 
ps2intlShiftedCodes_array *zxShiftedCodes = &zxUSShiftedCodes;

ps2intlShiftedCodes_array *zxShiftedCodesList[NUM_KEYBOARDS] {
  &zxUSShiftedCodes,
  &zxUSShiftedCodes,
  &zxESShiftedCodes,
  &zxDEShiftedCodes,
  &zxITShiftedCodes
};


const char intlNames_0[] PROGMEM = "US";
const char intlNames_1[] PROGMEM = "UK";
const char intlNames_2[] PROGMEM = "ES";
const char intlNames_3[] PROGMEM = "DE";
const char intlNames_4[] PROGMEM = "IT";

const char *const ps2IntlNames[NUM_KEYBOARDS] PROGMEM={
  intlNames_0,
  intlNames_1,
  intlNames_2,
  intlNames_3,
  intlNames_4
};

void selectIntlKeyboard(uint8_t n){
  zxintlCodes = zxCodesList[n];
  zxShiftedCodes = zxShiftedCodesList[n];
  currentKeyboard = n;
}

#ifdef PS2
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
#endif

#ifdef USB
uint8_t findUSBShiftedCode(uint8_t sc){
  uint8_t v;
  int i = 0;
  do{
    v=pgm_read_byte_near((USBShiftedCodes)+i);    // ps2ShiftedCodes[i];
    Serial.print(i);
    Serial.print(":");
    Serial.println(v);
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
#endif

#ifdef PS2
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
#endif
#ifdef USB
uint8_t findUSBIntlCode(uint8_t sc){
  uint8_t v;
  int i = 0;
  do{
    v=pgm_read_byte_near((USBintlCodes)+i);    // USBShiftedCodes[i];
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
#endif