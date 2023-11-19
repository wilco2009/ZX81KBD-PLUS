typedef uint8_t ps2intl [34];

ps2intl ps2USA = {

}

uint8_t ps2intlCodes[34]=
{
  0x0e, // ROW 1 KEY 01 `
  0x4e, // ROW 1 KEY 12 -
  0x55, // ROW 1 KEY 13 =
  0x54, // ROW 2 KEY 12 [
  0x5b, // ROW 2 KEY 13 ]
  0x4c, // ROW 3 KEY 11 ;
  0x52, // ROW 3 KEY 12 '
  0x5d, // ROW 3 KEY 13 "\"
  0x61, // ROW 4 KEY 02 "\"
  0x41, // ROW 4 KEY 10 ,
  0x49, // ROW 4 KEY 11 .
  0x4a, // ROW 4 KEY 12 /

// shifted keys

  0x80+ 0x0e, // ROW 1 KEY 01 ` ~
  0x80+ 0x16, // ROW 1 KEY 02 1 !
  0x80+ 0x1e, // ROW 1 KEY 03 2 @
  0x80+ 0x26, // ROW 1 KEY 04 3 #
  0x80+ 0x25, // ROW 1 KEY 05 4 $
  0x80+ 0x2e, // ROW 1 KEY 06 5 %
  0x80+ 0x36, // ROW 1 KEY 07 6 ^
  0x80+ 0x3d, // ROW 1 KEY 08 7 &
  0x80+ 0x3e, // ROW 1 KEY 09 8 *
  0x80+ 0x46, // ROW 1 KEY 10 9 (
  0x80+ 0x45, // ROW 1 KEY 11 0 )
  0x80+ 0x4e, // ROW 1 KEY 12 - _
  0x80+ 0x55, // ROW 1 KEY 13 = +
  0x80+ 0x54, // ROW 2 KEY 12 [ {
  0x80+ 0x5b, // ROW 2 KEY 13 ] }
  0x80+ 0x4c, // ROW 3 KEY 11 ; :
  0x80+ 0x52, // ROW 3 KEY 12 ' "
  0x80+ 0x5d, // ROW 3 KEY 13 \ |
  0x80+ 0x61, // ROW 4 KEY 02 \ |
  0x80+ 0x41, // ROW 4 KEY 10 , <
  0x80+ 0x49, // ROW 4 KEY 11 . >
  0x80+ 0x4a  // ROW 4 KEY 12 / ?
}