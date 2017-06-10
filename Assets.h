#ifndef ASSETS_H
#define ASSETS_H

const unsigned char PROGMEM sprite_logotype[] = {
  // width, height,
  52, 8,
  // FRAME 00
  0x41, 0x61, 0x51, 0x49, 0x41, 0x41, 0x00, 0x40, 0x38, 0x10, 0x11, 0x10, 0x38, 0x40, 0x00, 0x41, 0x41, 0x79, 0x41, 0x41, 0x00, 0x79, 0x49, 0x49, 0x49, 0x30, 0x00, 0x40, 0x38, 0x10, 0x11, 0x10, 0x38, 0x41, 0x01, 0x01, 0x79, 0x01, 0x01, 0x01, 0x40, 0x49, 0x49, 0x49, 0x31, 0x00, 0x00, 0x39, 0x40, 0x40, 0x40, 0x39,
};

const unsigned char PROGMEM sprite_logo[] = {
  // width, height,
  54, 24,
  // FRAME 00
  0x00, 0x00, 0x00, 0x00, 0xb8, 0xb8, 0xb8, 0xb8, 0xb8, 0xb8, 0xb8, 0xb8, 0xb8, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xb8, 0xb8, 0xb8, 0x80, 0x80, 0x00, 0x00, 0xbc, 0xbc, 0xbc, 0xbc, 0xbc, 0xbc, 0xbc, 0xbc, 0xbc, 0x00, 0xbc, 0xbc, 0xbc, 0xbc, 0xbc, 0xbc, 0xbc, 0xbc, 0xbc, 0xbc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x77, 0x77, 0x77, 0x55, 0x55, 0x55, 0x77, 0x77, 0x77, 0x00, 0x41, 0x61, 0x71, 0x71, 0x35, 0x17, 0x77, 0x77, 0x77, 0x01, 0x01, 0x00, 0x00, 0x77, 0x77, 0x77, 0x61, 0x71, 0x77, 0x77, 0x25, 0x71, 0x76, 0x77, 0x71, 0x35, 0x77, 0x35, 0x31, 0x01, 0x77, 0x77, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x10, 0x59, 0x1b, 0x1b, 0x09, 0x01, 0x09, 0x1b, 0x1b, 0x19, 0x13, 0x03, 0x03, 0x09, 0x50, 0x50, 0x50, 0x5b, 0x5b, 0x1b, 0x00, 0x00, 0x00, 0x00, 0x5b, 0x5b, 0x5b, 0x01, 0x1b, 0x1b, 0x1b, 0x08, 0x18, 0x18, 0x1b, 0x0b, 0x1b, 0x1b, 0x1b, 0x58, 0x50, 0x5b, 0x5b, 0x1b, 0x00, 0x00, 0x10, 0x50, 0x00, 0x70, 0x20,
};

const unsigned char PROGMEM sprite_scanner[] =
{
// width, height,
52, 32,
// FRAME 00
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0xa0, 0xe0, 0x70, 0xd0, 0xf8, 0x38, 0x48, 0xf8, 0xfc, 0xfc, 0xd4, 0xfc, 0xf4, 0x7c, 0xbc, 0x74, 0xfc, 0xfc, 0xf8, 0xe8, 0xe8, 0xf8, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x80, 0x60, 0x50, 0xf8, 0xec, 0xea, 0xcf, 0xd8, 0x35, 0xfd, 0xfe, 0xfe, 0xff, 0xff, 0xfe, 0x7f, 0x2e, 0xf5, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xef, 0xf6, 0xe7, 0x2e, 0xab, 0xbf, 0xa3, 0xbb, 0xff, 0x7f, 0xbf, 0xff, 0xcd, 0xf3, 0x9f, 0xa7, 0xe7, 0xea, 0xe4, 0xd8, 0xf0, 0xe0, 0x80, 0x00, 0x00, 0x00, 
0x80, 0xf8, 0x76, 0xbd, 0xf7, 0xfc, 0x6b, 0xf5, 0xe7, 0xbd, 0xff, 0xfe, 0xff, 0xff, 0xef, 0xef, 0xf0, 0x7e, 0x4d, 0x1d, 0xc9, 0x2e, 0xa6, 0x97, 0xd7, 0xd7, 0xd7, 0xd7, 0x97, 0xa7, 0x2f, 0xcf, 0x07, 0x38, 0xfd, 0x36, 0x74, 0x9f, 0x3f, 0xfb, 0xd5, 0xfd, 0xff, 0xbf, 0xef, 0xff, 0xff, 0xdf, 0xff, 0xfe, 0xf8, 0x80, 
0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x04, 0x05, 0x04, 0x0f, 0x00, 0x1e, 0x7f, 0x7f, 0xe7, 0xc3, 0xc3, 0xe7, 0x7f, 0x7f, 0x1e, 0x00, 0x0f, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
// FRAME 01
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x40, 0xa0, 0xe0, 0x70, 0xd0, 0xf8, 0xf8, 0xe8, 0xf8, 0xfc, 0xfc, 0xd4, 0x7c, 0x94, 0xdc, 0xac, 0xf4, 0xec, 0x64, 0x18, 0xe8, 0xe8, 0xf8, 0xf0, 0xf0, 0xe0, 0x60, 0xc0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x80, 0xe0, 0xd0, 0xf8, 0xfc, 0xfa, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0x7a, 0x97, 0xff, 0xe7, 0xff, 0xef, 0xf7, 0xff, 0xb7, 0xe7, 0xff, 0xda, 0xff, 0x3f, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xee, 0xee, 0xee, 0xfe, 0xfd, 0xfa, 0xff, 0xfc, 0xff, 0x3e, 0xfc, 0xf8, 0xf0, 0xe0, 0x80, 0x00, 0x00, 0x00, 
0x80, 0xf8, 0x76, 0xfd, 0xff, 0xff, 0x6f, 0xfd, 0xff, 0xbc, 0xff, 0xae, 0xfb, 0xff, 0x26, 0xff, 0xff, 0x7f, 0x4f, 0x1f, 0xcf, 0x2f, 0xa7, 0x97, 0xd7, 0xd5, 0xd4, 0xd5, 0x97, 0xa7, 0x2f, 0xcf, 0x0f, 0x3f, 0xff, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbb, 0xef, 0x5f, 0xaf, 0x55, 0x75, 0x9e, 0xf8, 0x80, 
0x05, 0x05, 0x05, 0x05, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x04, 0x05, 0x04, 0x0f, 0x00, 0x1e, 0x7f, 0x7f, 0xe7, 0xc3, 0xc3, 0xe7, 0x7f, 0x7f, 0x1e, 0x00, 0x0f, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x04, 0x05, 0x04, 0x05, 0x04, 0x05, 0x05, 0x04, 0x05, 0x04, 0x05, 
// FRAME 02
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0x38, 0x58, 0xf8, 0xfc, 0xfc, 0x7c, 0x7c, 0x9c, 0x5c, 0xec, 0x74, 0xec, 0xe4, 0x98, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xe0, 0x60, 0xc0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x80, 0x60, 0x70, 0xf8, 0xec, 0xee, 0x6f, 0x7a, 0xb7, 0xfd, 0xfe, 0x7b, 0xff, 0xff, 0xee, 0xff, 0x3e, 0xfd, 0xfe, 0xbe, 0xe7, 0xff, 0xda, 0xef, 0xbc, 0xed, 0x2e, 0xef, 0xff, 0xeb, 0xfb, 0xfd, 0x7f, 0xae, 0xfe, 0xcf, 0xf6, 0x9f, 0xbc, 0xff, 0x3a, 0xe4, 0xd8, 0xf0, 0xe0, 0x80, 0x00, 0x00, 0x00, 
0x80, 0xf8, 0xfe, 0x9f, 0xc7, 0xfc, 0xfb, 0xf7, 0xe7, 0xfc, 0xff, 0xaf, 0xfb, 0xff, 0x3e, 0xef, 0xf1, 0x7f, 0x4d, 0x1d, 0xcb, 0x2e, 0xa6, 0x97, 0xd7, 0xd7, 0xd7, 0xd5, 0x97, 0xa7, 0x2f, 0xcf, 0x07, 0x3b, 0xff, 0x3f, 0x74, 0x89, 0x23, 0xe8, 0xd5, 0xfd, 0xff, 0xfb, 0xff, 0x5f, 0xaf, 0x75, 0x75, 0x9e, 0xf8, 0x80, 
0x05, 0x05, 0x05, 0x05, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x04, 0x05, 0x04, 0x0f, 0x00, 0x1e, 0x7f, 0x7f, 0xe7, 0xc3, 0xc3, 0xe7, 0x7f, 0x7f, 0x1e, 0x00, 0x0f, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x04, 0x05, 0x04, 0x05, 0x04, 0x05, 0x04, 0x05, 0x05, 0x04, 0x05, 0x04, 0x05,
};

const unsigned char PROGMEM sprite_pragmata[] =
{
// width, height,
5, 8,
// FRAME 00
0x00, 0x3e, 0x45, 0x49, 0x3e, 
// FRAME 01
0x00, 0x42, 0x7f, 0x40, 0x00, 
// FRAME 02
0x00, 0x63, 0x51, 0x49, 0x46, 
// FRAME 03
0x00, 0x23, 0x41, 0x49, 0x36, 
// FRAME 04
0x18, 0x14, 0x12, 0x7f, 0x10, 
// FRAME 05
0x00, 0x27, 0x45, 0x45, 0x39, 
// FRAME 06
0x00, 0x3e, 0x49, 0x49, 0x72, 
// FRAME 07
0x00, 0x01, 0x61, 0x1d, 0x03, 
// FRAME 08
0x00, 0x36, 0x49, 0x49, 0x76, 
// FRAME 09
0x00, 0x27, 0x49, 0x49, 0x3e, 
// FRAME 10
0x60, 0x1c, 0x13, 0x1c, 0x60, 
// FRAME 11
0x00, 0x7f, 0x49, 0x49, 0x36, 
// FRAME 12
0x00, 0x3e, 0x41, 0x41, 0x22, 
// FRAME 13
0x00, 0x7f, 0x41, 0x41, 0x3e, 
// FRAME 14
0x00, 0x7f, 0x49, 0x49, 0x41, 
// FRAME 15
0x00, 0x7f, 0x09, 0x09, 0x01, 
// FRAME 16
0x00, 0x3e, 0x41, 0x49, 0x3a, 
// FRAME 17
0x00, 0x7f, 0x08, 0x08, 0x7f, 
// FRAME 18
0x00, 0x41, 0x7f, 0x41, 0x00, 
// FRAME 19
0x00, 0x30, 0x40, 0x40, 0x3f, 
// FRAME 20
0x00, 0x7f, 0x0c, 0x12, 0x61, 
// FRAME 21
0x00, 0x7f, 0x40, 0x40, 0x40, 
// FRAME 22
0x7f, 0x02, 0x0c, 0x02, 0x7f, 
// FRAME 23
0x00, 0x7f, 0x02, 0x04, 0x7f, 
// FRAME 24
0x00, 0x3e, 0x41, 0x41, 0x3e, 
// FRAME 25
0x00, 0x7f, 0x09, 0x09, 0x06, 
// FRAME 26
0x00, 0x3e, 0x41, 0xc1, 0x3e, 
// FRAME 27
0x00, 0x7f, 0x19, 0x29, 0x46, 
// FRAME 28
0x00, 0x26, 0x49, 0x49, 0x32, 
// FRAME 29
0x01, 0x01, 0x7f, 0x01, 0x01, 
// FRAME 30
0x00, 0x3f, 0x40, 0x40, 0x3f, 
// FRAME 31
0x07, 0x38, 0x40, 0x38, 0x07, 
// FRAME 32
0x0f, 0x70, 0x0c, 0x70, 0x0f, 
// FRAME 33
0x00, 0x63, 0x1c, 0x1c, 0x63, 
// FRAME 34
0x03, 0x04, 0x78, 0x04, 0x03, 
// FRAME 35
0x00, 0x61, 0x51, 0x4d, 0x43,
};

const unsigned char PROGMEM sprite_menuGylphs[] =
{
// width, height,
27, 16,
// FRAME 00
0xfa, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0xfa, 0x00, 0x00, 0x00, 0x88, 0xfa, 0x68, 0x80, 0xba, 0xaa, 0xba, 0xaa, 0xba, 0xaa, 0xaa, 0xba, 0x00, 0x00, 
0x3f, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x3f, 0x00, 0x00, 0x02, 0x01, 0x1f, 0x00, 0x0a, 0x0a, 0x06, 0x12, 0x1e, 0x0e, 0x06, 0x06, 0x0a, 0x0a, 0x00, 
// FRAME 01
0xfe, 0x2a, 0x2a, 0xaa, 0xba, 0x80, 0x80, 0xba, 0xaa, 0x2a, 0x2a, 0xfa, 0x00, 0x00, 0xba, 0xaa, 0xaa, 0xaa, 0xba, 0x80, 0x02, 0xfa, 0xaa, 0xaa, 0xaa, 0xfa, 0x00, 
0x1f, 0x00, 0x00, 0x0f, 0x04, 0x04, 0x04, 0x04, 0x07, 0x10, 0x10, 0x1f, 0x00, 0x10, 0x0e, 0x08, 0x0f, 0x12, 0x12, 0x1a, 0x18, 0x17, 0x12, 0x12, 0x16, 0x1b, 0x10, 
// FRAME 02
0x18, 0xca, 0x4a, 0x4a, 0x4a, 0xfa, 0x4a, 0x4a, 0x4a, 0x4a, 0xca, 0x18, 0x00, 0x00, 0xfa, 0xaa, 0xaa, 0xfa, 0xaa, 0xf9, 0x09, 0x08, 0xfa, 0x08, 0x08, 0xf8, 0x00, 
0x00, 0x0f, 0x05, 0x05, 0x05, 0x1f, 0x15, 0x15, 0x15, 0x15, 0x17, 0x10, 0x0c, 0x00, 0x12, 0x12, 0x12, 0x1f, 0x12, 0x12, 0x12, 0x0c, 0x03, 0x10, 0x10, 0x0f, 0x00,
};

const unsigned char PROGMEM sprite_end[] =
{
// width, height,
13, 8,
// FRAME 00
0x36, 0x24, 0x3d, 0x24, 0x26, 0x30, 0x40, 0x22, 0x12, 0x0b, 0x02, 0x42, 0x3a,
};

const unsigned char PROGMEM sprite_corner[] =
{
// width, height,
11, 8,
// FRAME 00
0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03,
};

const unsigned char PROGMEM sprite_confirm[] =
{
// width, height,
36, 8,
// FRAME 00
0x7c, 0x00, 0x7c, 0x7c, 0x10, 0x82, 0xc6, 0x6c, 0x18, 0x30, 0x6c, 0xc6, 0x82, 0x10, 0x7c, 0x7c, 0x00, 0x7c, 0x00, 0x7c, 0x7c, 0x0c, 0x04, 0x24, 0x64, 0xc4, 0x60, 0x30, 0x18, 0x0c, 0x46, 0x62, 0x70, 0x78, 0x7c, 0x7c,
};

const unsigned char PROGMEM sprite_charges[] =
{
// width, height,
12, 8,
// FRAME 00
0x2e, 0x2f, 0x27, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 
// FRAME 01
0x2e, 0x2f, 0x21, 0x2c, 0x2f, 0x27, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 
// FRAME 02
0x2e, 0x2f, 0x21, 0x2c, 0x2f, 0x21, 0x2c, 0x2f, 0x27, 0x20, 0x20, 0x00, 
// FRAME 03
0x2e, 0x2f, 0x21, 0x2c, 0x2f, 0x21, 0x2c, 0x2f, 0x21, 0x2c, 0x2f, 0x07,
};

const unsigned char PROGMEM sprite_arrow[] =
{
// width, height,
3, 8,
// FRAME 00
0x1f, 0x0e, 0x04,
};

const unsigned char PROGMEM sprite_menu[] =
{
// width, height,
74, 16,
// FRAME 00
0xfa, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0xfa, 0x00, 0x00, 0x00, 0x88, 0xfa, 0x68, 0x80, 0xba, 0xaa, 0xba, 0xaa, 0xba, 0xaa, 0xaa, 0xba, 0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xe4, 0x24, 0x64, 0x04, 0xe4, 0x24, 0x64, 0x04, 0xc4, 0x64, 0x84, 0x04, 0xe4, 0x84, 0xe4, 0x04, 0xe4, 0x84, 0xe4, 0x04, 0xe4, 0x24, 0x24, 0x04, 0xe4, 0x24, 0xe4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x3f, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x3f, 0x00, 0x00, 0x02, 0x01, 0x1f, 0x00, 0x0a, 0x0a, 0x06, 0x12, 0x1e, 0x0e, 0x06, 0x06, 0x0a, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x05, 0x06, 0x00, 0x07, 0x04, 0x06, 0x00, 0x07, 0x02, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x05, 0x04, 0x00, 0x07, 0x03, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// FRAME 01
0xfe, 0x2a, 0x2a, 0xaa, 0xba, 0x80, 0x80, 0xba, 0xaa, 0x2a, 0x2a, 0xfa, 0x00, 0x00, 0xba, 0xaa, 0xaa, 0xaa, 0xba, 0x80, 0x02, 0xfa, 0xaa, 0xaa, 0xaa, 0xfa, 0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xe4, 0x24, 0xe4, 0x04, 0x24, 0xe4, 0x24, 0x04, 0xc4, 0x64, 0x84, 0x04, 0xe4, 0x24, 0x64, 0x04, 0xe4, 0x84, 0xe4, 0x04, 0xe4, 0x24, 0xe4, 0x04, 0xe4, 0x24, 0x64, 0x04, 0x24, 0xe4, 0x24, 0x04, 0x24, 0xe4, 0x24, 0x04, 0xe4, 0x24, 0x64, 
0x1f, 0x00, 0x00, 0x0f, 0x04, 0x04, 0x04, 0x04, 0x07, 0x10, 0x10, 0x1f, 0x00, 0x10, 0x0e, 0x08, 0x0f, 0x12, 0x12, 0x1a, 0x18, 0x17, 0x12, 0x12, 0x16, 0x1b, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x07, 0x00, 0x04, 0x07, 0x04, 0x00, 0x07, 0x02, 0x07, 0x00, 0x07, 0x04, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x04, 0x07, 0x00, 0x06, 0x05, 0x06, 0x00, 0x00, 0x07, 0x00, 0x00, 0x04, 0x07, 0x04, 0x00, 0x07, 0x04, 0x06, 
// FRAME 02
0x18, 0xca, 0x4a, 0x4a, 0x4a, 0xfa, 0x4a, 0x4a, 0x4a, 0x4a, 0xca, 0x18, 0x00, 0x00, 0xfa, 0xaa, 0xaa, 0xfa, 0xaa, 0xf8, 0x08, 0x08, 0xfa, 0x08, 0x08, 0xf8, 0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xe4, 0x24, 0xe4, 0x04, 0xe4, 0x24, 0xe4, 0x04, 0xe4, 0x84, 0xe4, 0x04, 0xe4, 0x24, 0x24, 0x04, 0xe4, 0x24, 0xe4, 0x04, 0x04, 0x04, 0x04, 0x04, 0xe4, 0x84, 0xe4, 0x04, 0xe4, 0x84, 0xe4, 0x04, 0xe4, 0x24, 0x64, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x0f, 0x05, 0x05, 0x05, 0x1f, 0x15, 0x15, 0x15, 0x15, 0x17, 0x10, 0x0c, 0x00, 0x12, 0x12, 0x12, 0x1f, 0x12, 0x12, 0x12, 0x0c, 0x03, 0x10, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x01, 0x01, 0x00, 0x07, 0x04, 0x07, 0x00, 0x07, 0x07, 0x01, 0x00, 0x07, 0x05, 0x04, 0x00, 0x07, 0x03, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x01, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00,
};

#endif
