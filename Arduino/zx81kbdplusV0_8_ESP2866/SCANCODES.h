#define NULL  0b00000000 
#define SHIFT 0b01000000

#define stPRESS       0
#define stRELEASE     1
#define stPRESS_E0    2
#define stRELEASE_E0  3
#define stPRESS_E1_1  4
#define stPRESS_E1_2  5

#define NUM_INTL          12
#define NUM_INTL_SHIFTED  22

#ifdef PS2
uint8_t scState = stPRESS;
const uint8_t PROGMEM ps2Codes[] = {
  NULL  + 40,
  NULL  + 40,       // 01 = F9
  NULL  + 40,       // 02 = spare
  NULL  + 40,       // 03 = F5
  NULL  + 40,       // 04 = F3
  NULL  + 40,       // 05 = F1
  NULL  + 40,       // 06 = F2
  NULL  + 40,       // 07 = F12
  NULL  + 40,       // 08 = spare
  NULL  + 40,       // 09 = 10
  NULL  + 40,       // 0A = F8
  NULL  + 40,       // 0B = F6
  NULL  + 40,       // 0C = F4
  NULL  + 40,       // 0D = TAB
  NULL  + 40,       // 0E = `
  NULL  + 40,       // 0F = spare
  NULL  + 40,       // 10 = spare
  SHIFT + 30,       // 11 = ALT LEFT - (SHIFT + ENTER)
  NULL  + 40,       // 12 = SHIFT LEFT - (NONE)
  NULL  + 40,       // 13 = spare
  SHIFT + 40,       // 14 = CTRL LEFT -(SHIFT)
  NULL  + 10,       // 15 = Q - (Q)
  NULL  + 15,       // 16 = 1 - (1)
  NULL  + 40,       // 17 = spare
  NULL  + 40,       // 18 = spare
  NULL  + 40,       // 19 = spare
  NULL  +  1,       // 1A = Z - (Z)
  NULL  +  6,       // 1B = S - (S)
  NULL  +  5,       // 1C = A - (A)
  NULL  + 11,       // 1D = W - (W)
  NULL  + 16,       // 1E = 2 - (2)
  NULL  + 40,       // 1F = spare
  NULL  + 40,       // 20 = spare
  NULL  +  3,       // 21 = C - (C)
  NULL  +  2,       // 22 = X - (X)
  NULL  +  7,       // 23 = D - (D)
  NULL  + 12,       // 24 = E - (E)
  NULL  + 18,       // 25 = 4 - (4)
  NULL  + 17,       // 26 = 3 - (3)
  NULL  + 40,       // 27 = spare
  NULL  + 40,       // 28 = spare
  NULL  + 35,       // 29 = space - (space)
  NULL  +  4,       // 2A = V - (V)
  NULL  +  8,       // 2B = F - (F)
  NULL  + 14,       // 2C = T - (T)
  NULL  + 13,       // 2D = R - (R)
  NULL  + 19,       // 2E = 5 - (5)
  NULL  + 40,       // 2F = spare
  NULL  + 40,       // 30 = spare
  NULL  + 38,       // 31 = N - (N)
  NULL  + 39,       // 32 = B - (B)
  NULL  + 34,       // 33 = H - (H)
  NULL  +  9,       // 34 = G - (G)
  NULL  + 29,       // 35 = Y - (Y)
  NULL  + 24,       // 36 = 6 - (6)
  NULL  + 40,       // 37 = spare
  NULL  + 40,       // 38 = spare
  NULL  + 40,       // 39 = spare
  NULL  + 37,       // 3A = M - (M)
  NULL  + 33,       // 3B = J - (J)
  NULL  + 28,       // 3C = U - (U)
  NULL  + 23,       // 3D = 7 - (7)
  NULL  + 22,       // 3E = 8 - (8)
  NULL  + 40,       // 3F = spare
  NULL  + 40,       // 40 = spare
  SHIFT + 36,       // 41 = , - (,)
  NULL  + 32,       // 42 = K - (K)
  NULL  + 27,       // 43 = I - (I)
  NULL  + 26,       // 44 = O - (O)
  NULL  + 20,       // 45 = 0 - (0)
  NULL  + 21,       // 46 = 9 - (9)
  NULL  + 40,       // 47 = spare
  NULL  + 40,       // 48 = spare
  NULL  + 36,       // 49 = . - (.)
  SHIFT +  4,       // 4A = / - (/)
  NULL  + 31,       // 4B = L - (L)
  SHIFT +  2,       // 4C = ; - (;)
  NULL  + 25,       // 4D = P - (P)
  SHIFT + 33,       // 4E = - - (-)
  NULL  + 40,       // 4F = spare
  NULL  + 40,       // 50 = spare
  NULL  + 40,       // 51 = spare
  SHIFT + 25,       // 52 = ' - (")
  NULL  + 40,       // 53 = spare
  SHIFT + 27,       // 54 = [ - ("(")
  SHIFT + 31,       // 55 = EQUAL - (EQUAL))
  SHIFT + 38,       // 56 = < - (<)
  NULL  + 40,       // 57 = spare
  SHIFT + 21,       // 58 = CAPS LOCK - (GRAPHICS)
  NULL  + 40,       // 59 = RIGHT SHIFT - (NONE))
  NULL  + 30,       // 5A = ENTER - (NEW LINE)
  SHIFT + 26,       // 5B = ] - (")")
  NULL  + 40,       // 5C = spare
  SHIFT +  4,       // 5D = \ - (/)
  NULL  + 40,       // 5E = spare
  NULL  + 40,       // 5F = spare
  NULL  + 40,       // 60 = spare
  SHIFT +  4,       // 5D = \ - (/)
  NULL  + 40,       // 62 = spare
  NULL  + 40,       // 63 = spare
  NULL  + 40,       // 64 = spare
  NULL  + 40,       // 65 = spare
  SHIFT + 20,       // 66 = BS - (RUBOUT))
  NULL  + 40,       // 67 = spare
  NULL  + 40,       // 68 = spare
  NULL  + 15,       // 69 = 1 - (1)
  NULL  + 40,       // 6A = spare
  NULL  + 18,       // 6B = 4 - (4)
  NULL  + 23,       // 6C = 7 - (7)
  NULL  + 40,       // 6D = spare
  NULL  + 40,       // 6E = spare
  NULL  + 40,       // 6F = spare
  NULL  + 20,       // 70 = 0 - (0)
  NULL  + 36,       // 71 = . - (.)
  NULL  + 16,       // 72 = 2 - (2)
  NULL  + 19,       // 73 = 5 - (5)
  NULL  + 24,       // 74 = 6 - (6)
  NULL  + 22,       // 75 = 8 - (8)
  SHIFT + 15,       // 76 = ESC - (EDIT))
  NULL  + 40,       // 77 = NUMLOCK
  NULL  + 40,       // 78 = F11
  SHIFT + 32,       // 79 = + - (+))
  NULL  + 17,       // 7A = 3 - (3)
  SHIFT + 33,       // 7B = - - (-)
  SHIFT + 39,       // 7C = * - (*)
  NULL  + 21,       // 7D = 9 - (9)
  NULL  + 40,       // 7E = SCRLOCK
  NULL  + 40        // 7F = spare
};

const uint8_t PROGMEM ps2E0Codes[] = {
  0x12,           // PtrScr 0
  0x7c,           // PtrScr 1
  0x1f,           // Windows Left
  0x11,           // Alt Right
  0x27,           // Windows Right
  0x2f,           // Menus
  0x14,           // Ctrl Right
  0x70,           // Insert
  0x6c,           // home
  0x7d,           // Pg up
  0x71,           // delete
  0x69,           // End
  0x27,           // Windows Right
  0x7a,           // Pg down
  0x75,           // Up Arrow
  0x6b,           // Left Arrow
  0x72,           // Down Arrow
  0x74,           // Right Arrow
  0x4a,           // /
  0x5a,           // Enter
  0x7e,           // Break
  0xff            // End of list
};

const uint8_t PROGMEM zxE0Codes[] = {
  NULL  + 40,           // PtrScr 0
  NULL  + 40,           // PtrScr 1
  NULL  + 40,           // Windows Left
  SHIFT + 21,           // Alt Right
  NULL  + 40,           // Windows Right
  NULL  + 40,           // Menus
  SHIFT + 40,           // Ctrl Right
  NULL  + 40,           // Insert
  SHIFT + 15,           // home
  SHIFT + 23,           // Pg up
  SHIFT + 20,           // delete
  NULL  + 40,           // End
  NULL  + 40,           // Windows Right
  SHIFT + 24,           // Pg down
  SHIFT + 23,           // Up Arrow
  SHIFT + 19,           // Left Arrow
  SHIFT + 24,           // Down Arrow
  SHIFT + 22,           // Right Arrow
  SHIFT +  4,           // /
  NULL  + 30,           // Enter
  SHIFT + 35,           // Break
  SHIFT +  4            // End of list
};

const uint8_t PROGMEM zx2ShiftedCodes[NUM_INTL_SHIFTED]= {
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

const uint8_t PROGMEM ps2ShiftedCodes[NUM_INTL_SHIFTED]= {
  0x0e, // ROW 1 KEY 01 ` ~
  0x16, // ROW 1 KEY 02 1 !
  0x1e, // ROW 1 KEY 03 2 @
  0x26, // ROW 1 KEY 04 3 #
  0x25, // ROW 1 KEY 05 4 $
  0x2e, // ROW 1 KEY 06 5 %
  0x36, // ROW 1 KEY 07 6 ^
  0x3d, // ROW 1 KEY 08 7 &
  0x3e, // ROW 1 KEY 09 8 *
  0x46, // ROW 1 KEY 10 9 (
  0x45, // ROW 1 KEY 11 0 )
  0x4e, // ROW 1 KEY 12 - _
  0x55, // ROW 1 KEY 13 = +
  0x54, // ROW 2 KEY 12 [ {
  0x5b, // ROW 2 KEY 13 ] }
  0x4c, // ROW 3 KEY 11 ; :
  0x52, // ROW 3 KEY 12 ' "
  0x5d, // ROW 3 KEY 13 \ |
  0x61, // ROW 4 KEY 02 \ |
  0x41, // ROW 4 KEY 10 , <
  0x49, // ROW 4 KEY 11 . >
  0x4a  // ROW 4 KEY 12 / ?
};

// uint8_t ps2ShiftedCodes[][2] = {
//   {0x25, SHIFT + 28},           // $
//   {0x55, SHIFT + 32},           // +
//   {0x3E, SHIFT + 39},           // *
//   {0x36, SHIFT + 34},           // **
//   {0x46, SHIFT + 27},           // (
//   {0x45, SHIFT + 26},           // )
//   {0x52, SHIFT + 25},           // "
//   {0x45, SHIFT + 31},           // =
//   {0x4C, SHIFT +  1},           // :
//   {0x41, SHIFT + 38},           // < (,) 
//   {0x49, SHIFT + 37},           // > (.)
//   {0x4A, SHIFT +  3},           // ?
//   {0x3d, SHIFT + 35},           // £
//   {0xff, SHIFT +  4},           // /
//   {0xff, SHIFT +  4}            // End of list
// };

uint8_t findE0Code(uint8_t sc){
  uint8_t v;
  int i = 0;
  do{
    v=pgm_read_byte_near(zxE0Codes+i);       // ps2E0Codes[i][0]
    if (sc==v) {
      v = pgm_read_byte_near(ps2E0Codes+i); // ps2E0Codes[i][1]
      return v;
    };
    i++;
  } while (v != 0xff);
  return NULL  + 40;
}
#endif
const uint8_t PROGMEM USBCodes[] = {
  NULL  + 40,       // 00 = No event 
  NULL  + 40,       // 01 = Overrun
  NULL  + 40,       // 02 = POST fail
  NULL  + 40,       // 03 = Error unidentified
  NULL  +  5,       // 04 = A - (A)
  NULL  + 39,       // 05 = B - (B)
  NULL  +  3,       // 06 = C - (C)
  NULL  +  7,       // 07 = D - (D)
  NULL  + 12,       // 08 = E - (E)
  NULL  +  8,       // 09 = F - (F)
  NULL  +  9,       // 0A = G - (G)
  NULL  + 34,       // 0B = H - (H)
  NULL  + 27,       // 0C = I - (I)
  NULL  + 33,       // 0D = J - (J)
  NULL  + 32,       // 0E = K - (K)
  NULL  + 31,       // 0F = L - (L)
  NULL  + 37,       // 10 = M - (M)
  NULL  + 38,       // 11 = N - (N)
  NULL  + 26,       // 12 = O - (O)
  NULL  + 25,       // 13 = P - (P)
  NULL  + 10,       // 14 = Q - (Q)
  NULL  + 13,       // 15 = R - (R)
  NULL  +  6,       // 16 = S - (S)
  NULL  + 14,       // 17 = T - (T)
  NULL  + 28,       // 18 = U - (U)
  NULL  +  4,       // 19 = V - (V)
  NULL  + 11,       // 1A = W - (W)
  NULL  +  2,       // 1B = X - (X)
  NULL  + 29,       // 1C = Y - (Y)
  NULL  +  1,       // 1D = Z - (Z)
  NULL  + 15,       // 1E = 1 - (1)
  NULL  + 16,       // 1F = 2 - (2)
  NULL  + 17,       // 20 = 3 - (3)
  NULL  + 18,       // 21 = 4 - (4)
  NULL  + 19,       // 22 = 5 - (5)
  NULL  + 24,       // 23 = 6 - (6)
  NULL  + 23,       // 24 = 7 - (7)
  NULL  + 22,       // 25 = 8 - (8)
  NULL  + 21,       // 26 = 9 - (9)
  NULL  + 20,       // 27 = 0 - (0)
  NULL  + 30,       // 28 = ENTER - (NEW LINE)
  SHIFT + 15,       // 29 = ESC - (EDIT))
  SHIFT + 20,       // 2A = BS - (RUBOUT))
  NULL  + 40,       // 2B = TAB
  NULL  + 35,       // 2C = space - (space)
  SHIFT + 33,       // 2D = - - (-)
  SHIFT + 32,       // 2E = + - (+))
  SHIFT + 27,       // 2F = [ - ("(")
  SHIFT + 26,       // 30 = ] - (")")
  SHIFT +  4,       // 31 = \ - (/)
  NULL  + 40,       // 32 = Europe 1
  SHIFT +  2,       // 33 = ; - (;)
  SHIFT + 25,       // 34 = ' - (")
  NULL  + 40, 		  // 35 = ` ~
  SHIFT + 36,       // 36 = , - (,)
  NULL  + 36,       // 37 = . - (.)
  SHIFT +  4,       // 38 = / - (/)
  SHIFT + 21,       // 39 = CAPS LOCK - (GRAPHICS)
  NULL  + 40,       // 3A = F1
  NULL  + 40,       // 3B = F2
  NULL  + 40,       // 3C = F3
  NULL  + 40,       // 3D = F4
  NULL  + 40,       // 3E = F5
  NULL  + 40,       // 3F = F6
  NULL  + 40,       // 40 = F7
  NULL  + 40,       // 41 = F8
  NULL  + 40,       // 42 = F9
  NULL  + 40,       // 43 = 10
  NULL  + 40,       // 44 = F11
  NULL  + 40,       // 45 = F12
  NULL  + 40,       // 46 = Print Screen
  NULL  + 40,       // 47 = Scroll Lock
  SHIFT + 35,       // 48 = Break
  NULL  + 40,       // 49 = Insert
  SHIFT + 15,       // 4A = Home
  SHIFT + 23,       // 4B = Pg up
  SHIFT + 20,       // 4C = delete
  NULL  + 40,       // 4D = End
  SHIFT + 24,       // 4E = Pg down
  SHIFT + 22,       // 4F = Right Arrow
  SHIFT + 19,       // 50 = Left Arrow
  SHIFT + 24,       // 51 = Down Arrow
  SHIFT + 23,       // 52 = Up Arrow
  NULL  + 40,       // 53 = Num Lock
  SHIFT +  4,       // 54 = / - (/)
  SHIFT + 39,       // 55 = * - (*)
  SHIFT + 33,       // 56 = - - (-)
  SHIFT + 32,       // 57 = + - (+))
  NULL  + 30,       // 58 = Enter
  NULL  + 15,       // 59 = 1 - (1)
  NULL  + 16,       // 5A = 2 - (2)
  NULL  + 17,       // 5B = 3 - (3)
  NULL  + 18,       // 5C = 4 - (4)
  NULL  + 19,       // 5D = 5 - (5)
  NULL  + 24,       // 5E = 6 - (6)
  NULL  + 23,       // 5F = 7 - (7)
  NULL  + 22,       // 60 = 8 - (8)
  NULL  + 21,       // 61 = 9 - (9)
  NULL  + 20,       // 62 = 0 - (0)
  NULL  + 36,       // 63 = . - (.)
  NULL  + 40,       // 64 = Europe 2
  NULL  + 40,       // 65 = App
  NULL  + 40,       // 66 = Power
  SHIFT + 32, 		  // 67 = =
  NULL  + 40,       // 68 = F13 
  NULL  + 40,       // 69 = F14 
  NULL  + 40,       // 6A = F15 
  NULL  + 40,       // 6B = F16 
  NULL  + 40,       // 6C = F17 
  NULL  + 40,       // 6D = F18 
  NULL  + 40,       // 6E = F19 
  NULL  + 40,       // 6F = F20  
  NULL  + 40,       // 70 = F21 
  NULL  + 40,       // 71 = F22 
  NULL  + 40,       // 72 = F23 
  NULL  + 40,       // 73 = F24
  NULL  + 40,       // 74 = spare
  NULL  + 40,       // 75 = spare
  NULL  + 40,       // 76 = spare
  NULL  + 40,       // 77 = spare
  NULL  + 40,       // 77 = spare
  NULL  + 40,       // 78 = spare
  NULL  + 40,       // 79 = spare
  NULL  + 40,       // 7A = spare
  NULL  + 40,       // 7B = spare
  NULL  + 40,       // 7D = spare
  NULL  + 40,       // 7E = spare
  NULL  + 40,       // 7F = spare
  NULL  + 40,       // 80 = spare
  NULL  + 40,       // 81 = spare
  NULL  + 40,       // 82 = spare
  NULL  + 40,       // 83 = spare
  NULL  + 40,       // 84 = spare
  NULL  + 40,       // 85 = spare
  NULL  + 40,       // 86 = spare
  NULL  + 40,       // 87 = spare
  NULL  + 40,       // 88 = spare
  NULL  + 40,       // 89 = spare
  NULL  + 40,       // 8A = spare
  NULL  + 40,       // 8B = spare
  NULL  + 40,       // 8C = spare
  NULL  + 40,       // 8D = spare
  NULL  + 40,       // 8E = spare
  NULL  + 40,       // 8F = spare
  NULL  + 40,       // 90 = spare
  NULL  + 40,       // 91 = spare
  NULL  + 40,       // 92 = spare
  NULL  + 40,       // 93 = spare
  NULL  + 40,       // 94 = spare
  NULL  + 40,       // 95 = spare
  NULL  + 40,       // 96 = spare
  NULL  + 40,       // 97 = spare
  NULL  + 40,       // 98 = spare
  NULL  + 40,       // 99 = spare
  NULL  + 40,       // 9A = spare
  NULL  + 40,       // 9B = spare
  NULL  + 40,       // 9C = spare
  NULL  + 40,       // 9D = spare
  NULL  + 40,       // 9E = spare
  NULL  + 40,       // 9F = spare
  NULL  + 40,       // A0 = spare
  NULL  + 40,       // A1 = spare
  NULL  + 40,       // A2 = spare
  NULL  + 40,       // A3 = spare
  NULL  + 40,       // A4 = spare
  NULL  + 40,       // A5 = spare
  NULL  + 40,       // A6 = spare
  NULL  + 40,       // A7 = spare
  NULL  + 40,       // A8 = spare
  NULL  + 40,       // A9 = spare
  NULL  + 40,       // AA = spare
  NULL  + 40,       // AB = spare
  NULL  + 40,       // AC = spare
  NULL  + 40,       // AD = spare
  NULL  + 40,       // AE = spare
  NULL  + 40,       // AF = spare
  NULL  + 40,       // B0 = spare
  NULL  + 40,       // B1 = spare
  NULL  + 40,       // B2 = spare
  NULL  + 40,       // B3 = spare
  NULL  + 40,       // B4 = spare
  NULL  + 40,       // B5 = spare
  NULL  + 40,       // B6 = spare
  NULL  + 40,       // B7 = spare
  NULL  + 40,       // B8 = spare
  NULL  + 40,       // B9 = spare
  NULL  + 40,       // BA = spare
  NULL  + 40,       // BB = spare
  NULL  + 40,       // BC = spare
  NULL  + 40,       // BD = spare
  NULL  + 40,       // BE = spare
  NULL  + 40,       // BF = spare
  NULL  + 40,       // C0 = spare
  NULL  + 40,       // C1 = spare
  NULL  + 40,       // C2 = spare
  NULL  + 40,       // C3 = spare
  NULL  + 40,       // C4 = spare
  NULL  + 40,       // C5 = spare
  NULL  + 40,       // C6 = spare
  NULL  + 40,       // C7 = spare
  NULL  + 40,       // C8 = spare
  NULL  + 40,       // C9 = spare
  NULL  + 40,       // CA = spare
  NULL  + 40,       // CB = spare
  NULL  + 40,       // CC = spare
  NULL  + 40,       // CD = spare
  NULL  + 40,       // CE = spare
  NULL  + 40,       // CF = spare
  NULL  + 40,       // D0 = spare
  NULL  + 40,       // D1 = spare
  NULL  + 40,       // D2 = spare
  NULL  + 40,       // D3 = spare
  NULL  + 40,       // D4 = spare
  NULL  + 40,       // D5 = spare
  NULL  + 40,       // D6 = spare
  NULL  + 40,       // D7 = spare
  NULL  + 40,       // D8 = spare
  NULL  + 40,       // D9 = spare
  NULL  + 40,       // DA = spare
  NULL  + 40,       // DB = spare
  NULL  + 40,       // DC = spare
  NULL  + 40,       // DD = spare
  NULL  + 40,       // DE = spare
  NULL  + 40,       // DF = spare
  NULL  + 40,       // E0 = spare
  NULL  + 40,       // E1 = spare
  NULL  + 40,       // E2 = spare
  NULL  + 40,       // E3 = spare
  NULL  + 40,       // E4 = spare
  NULL  + 40,       // E5 = spare
  NULL  + 40,       // E6 = spare
  NULL  + 40,       // E7 = spare
  NULL  + 40,       // E8 = spare
  NULL  + 40,       // E9 = spare
  NULL  + 40,       // EA = spare
  NULL  + 40,       // EB = spare
  NULL  + 40,       // EC = spare
  NULL  + 40,       // ED = spare
  NULL  + 40,       // EE = spare
  NULL  + 40,       // EF = spare
  NULL  + 40,       // F0 = spare
  NULL  + 40,       // F1 = spare
  NULL  + 40,       // F2 = spare
  NULL  + 40,       // F3 = spare
  NULL  + 40,       // F4 = spare
  NULL  + 40,       // F5 = spare
  NULL  + 40,       // F6 = spare
  NULL  + 40,       // F7 = spare
  NULL  + 40,       // F8 = spare
  NULL  + 40,       // F9 = spare
  NULL  + 40,       // FA = spare
  NULL  + 40,       // FB = spare
  NULL  + 40,       // FC = spare
  NULL  + 40,       // FD = spare
  NULL  + 40,       // FE = spare
  NULL  + 40        // FF = spare
};

const uint8_t PROGMEM USBShiftedCodes[NUM_INTL_SHIFTED]= {
  0x35, // ROW 1 KEY 01 ` ~
  0x1e, // ROW 1 KEY 02 1 !
  0x1f, // ROW 1 KEY 03 2 @
  0x20, // ROW 1 KEY 04 3 #
  0x21, // ROW 1 KEY 05 4 $
  0x22, // ROW 1 KEY 06 5 %
  0x23, // ROW 1 KEY 07 6 ^
  0x24, // ROW 1 KEY 08 7 &
  0x25, // ROW 1 KEY 09 8 *
  0x26, // ROW 1 KEY 10 9 (
  0x27, // ROW 1 KEY 11 0 )
  0x2d, // ROW 1 KEY 12 - _
  0x2e, // ROW 1 KEY 13 = +
  0x2f, // ROW 2 KEY 12 [ {
  0x30, // ROW 2 KEY 13 ] }
  0x33, // ROW 3 KEY 11 ; :
  0x34, // ROW 3 KEY 12 ' "
  0x31, // ROW 3 KEY 13 \ |
  0x64, // ROW 4 KEY 02 \ |
  0x36, // ROW 4 KEY 10 , <
  0x37, // ROW 4 KEY 11 . >
  0x38  // ROW 4 KEY 12 / ?
};