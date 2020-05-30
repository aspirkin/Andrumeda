#ifndef ST7735_144_128x128_greenTab_Display_h_
#define ST7735_144_128x128_greenTab_Display_h_

#include <Adafruit_ST7735.h>

const int TFT_CS = 12;
const int TFT_DC = 17;
const int TFT_MOSI = 21;
const int TFT_SCLK = 20;
const int TFT_RST = 10;

Adafruit_ST7735 display = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

#endif  //ST7735_144_128x128_greenTab_Display_h_