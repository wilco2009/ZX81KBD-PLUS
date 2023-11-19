#define NULL  0b00000000 
#define SHIFT 0b01000000

#define stPRESS       0
#define stRELEASE     1
#define stPRESS_E0    2
#define stRELEASE_E0  3
#define stPRESS_E1_1  4
#define stPRESS_E1_2  5

uint8_t scState = stPRESS;

uint8_t ps2Codes[] = {
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

uint8_t ps2E0Codes[][2] = {
  {0x12, NULL  + 40},           // PtrScr 0
  {0x7c, NULL  + 40},           // PtrScr 1
  {0x1f, NULL  + 40},           // Windows Left
  {0x11, SHIFT + 21},           // Alt Right
  {0x27, NULL  + 40},           // Windows Right
  {0x2f, NULL  + 40},           // Menus
  {0x14, SHIFT + 40},           // Ctrl Right
  {0x70, NULL  + 40},           // Insert
  {0x6c, SHIFT + 15},           // home
  {0x7d, SHIFT + 23},           // Pg up
  {0x71, SHIFT + 20},           // delete
  {0x69, NULL  + 40},           // End
  {0x27, NULL  + 40},           // Windows Right
  {0x7a, SHIFT + 24},           // Pg down
  {0x75, SHIFT + 23},           // Up Arrow
  {0x6b, SHIFT + 19},           // Left Arrow
  {0x72, SHIFT + 24},           // Down Arrow
  {0x74, SHIFT + 22},           // Right Arrow
  {0x4a, SHIFT +  4},           // /
  {0xff, SHIFT +  4}            // End of list
};

uint8_t ps2ShiftedCodes[][2] = {
  {0x25, SHIFT + 28},           // $
  {0x55, SHIFT + 32},           // +
  {0x3E, SHIFT + 39},           // *
  {0x36, SHIFT + 34},           // **
  {0x46, SHIFT + 27},           // (
  {0x45, SHIFT + 26},           // )
  {0x52, SHIFT + 25},           // "
  {0x45, SHIFT + 31},           // =
  {0x4C, SHIFT +  1},           // :
  {0x41, SHIFT + 38},           // < (,) 
  {0x49, SHIFT + 37},           // > (.)
  {0x4A, SHIFT +  3},           // ?
  {0x3d, SHIFT + 35},           // £
  {0xff, SHIFT +  4},           // /
  {0xff, SHIFT +  4}            // End of list
};

uint8_t findE0Code(uint8_t sc){
  for (int i=0; ps2E0Codes[i][0]!=0xff;i++){
    if (sc==ps2E0Codes[i][0]) return ps2E0Codes[i][1];
  }
  return NULL  + 40;
}

uint8_t findShiftedCode(uint8_t sc){
  uint8_t v;
  //Serial.println("SEARCHING");
  int i = 0;
//  for (int i=0; (v=ps2ShiftedCodes[i,0]) !=0xff;i++){
  do{
    v=ps2ShiftedCodes[i][0];
    //Serial.println(v);
    if (sc==v) return ps2ShiftedCodes[i][1];
    i++;
  } while (v != 0xff);
  return NULL  + 40;
}