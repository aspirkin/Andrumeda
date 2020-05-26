#ifndef DisplayObject_h_
#define DisplayObject_h_

#include <Adafruit_ST7735.h>

//  1.44  128*128
#define TFT_CS     12
#define TFT_RST    10
#define TFT_DC     17
#define TFT_SCLK   20   // set these to be whatever pins you like!
#define TFT_MOSI   21   // set these to be whatever pins you like!

// #define BLACK   0x0000
// #define BLUE    0x001F
// #define RED     0xF800
// #define GREEN   0x07E0
// #define CYAN    0x07FF
// #define MAGENTA 0xF81F
// #define YELLOW  0xFFE0
// #define WHITE   0xFFFF

// #define OPERATOR1_COLOR RED
// #define OPERATOR2_COLOR GREEN
// #define OPERATOR3_COLOR BLUE
// #define OPERATOR4_COLOR YELLOW

Adafruit_ST7735 display = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

#endif  //DisplayObject_h_