#include <Adafruit_GFX.h>       // include Adafruit graphics library
#include <Adafruit_ILI9341.h>   // include Adafruit ILI9341 TFT library
 
#define TFT_CS    4 // D2            // TFT CS  pin is connected to NodeMCU pin D2 / GPIO 4
#define TFT_RST   0 // D3            // TFT RST pin is connected to NodeMCU pin D3 / GPIO 0
#define TFT_DC    2 // D4            // TFT DC  pin is connected to NodeMCU pin D4 / GPIO 2
Adafruit_ILI9341  tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

#define BACKGND 0x7618 // https://ee-programming-notepad.blogspot.com/2016/10/16-bit-color-generator-picker.html

#include "icons/01d.h"
#include "icons/01n.h"
#include "icons/02d.h"
#include "icons/02n.h"
#include "icons/03d.h"
#include "icons/04d.h"
#include "icons/09d.h"
#include "icons/10d.h"
#include "icons/10n.h"
#include "icons/11d.h"
#include "icons/13d.h"
#include "icons/50d.h"

#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>

#define SCREEN_HORIZONTAL 1
#define SCREEN_HORIZONTAL_INVERSE 3

#define SCREEN_ORIENTATION SCREEN_HORIZONTAL

// https://github.com/adafruit/Adafruit_ILI9341/blob/master/Adafruit_ILI9341.h
// https://github.com/adafruit/Adafruit-GFX-Library/blob/master/Adafruit_GFX.cpp

void screenDiagnostics() {
  // read diagnostics (optional but can help debug problems)
  uint8_t x = tft.readcommand8(ILI9341_RDMODE);
  Serial.print("\nDisplay Power Mode: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDMADCTL);
  Serial.print("MADCTL Mode: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDPIXFMT);
  Serial.print("Pixel Format: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDIMGFMT);
  Serial.print("Image Format: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDSELFDIAG);
  Serial.print("Self Diagnostic: 0x"); Serial.println(x, HEX); 
}

void fillScreen(int color) {
  tft.fillScreen(color);
}

void setupScreen() {
  tft.begin();;
  screenDiagnostics();
  tft.setRotation(SCREEN_ORIENTATION);
  fillScreen(ILI9341_WHITE);
}

void _text(int x, int y, int color, char* text) {
  tft.setTextSize(1);
  tft.setTextColor(color);
  tft.setCursor(x, y);
  tft.println(text);
}

void drawSmallText(int x, int y, int color, char* text) {
  tft.setFont(&FreeMonoBold9pt7b);
  _text(x, y, color, text);
}

void drawBigText(int x, int y, int color, char* text) {
  tft.setFont(&FreeMonoBold18pt7b);
  _text(x, y, color, text);
}

void drawText(int x, int y, int color, char* text) {
  tft.setFont(&FreeMonoBold12pt7b);
  _text(x, y, color, text);
}

void printMsg(char* text) {
  fillScreen(BACKGND);
  drawText(5, 50, ILI9341_BLACK, text);
}

void printError(char* text) {
  fillScreen(ILI9341_WHITE);
  drawText(5, 50, ILI9341_RED, text);
}

void drawIcon(int x, int y, char* icon) {
  if (strcmp(icon, "01d") == 0) {
    // 01d - Sun
    tft.drawRGBBitmap(x, y, icon_01d, 100, 100);
  } else if (strcmp(icon, "01n") == 0) {
    // 01n - Sun - night
    tft.drawRGBBitmap(x, y, icon_01n, 100, 100);
  } else if (strcmp(icon, "02d") == 0) {
    // 02d - Cloud, sun
    tft.drawRGBBitmap(x, y, icon_02d, 100, 100);
  } else if (strcmp(icon, "02n") == 0) {
    // 02d - Cloud, sun - night
    tft.drawRGBBitmap(x, y, icon_02n, 100, 100);
  } else if (strcmp(icon, "03d") == 0 || strcmp(icon, "03n") == 0) {
    // 03d - Cloud
    tft.drawRGBBitmap(x, y, icon_03d, 100, 100);
  } else if (strcmp(icon, "04d") == 0 || strcmp(icon, "04n") == 0) {
    // 04d - Cloud, second cloud
    tft.drawRGBBitmap(x, y, icon_04d, 100, 100);
  } else if (strcmp(icon, "09d") == 0 || strcmp(icon, "09n") == 0) {
    // 09d - Clouds, rain
    tft.drawRGBBitmap(x, y, icon_09d, 100, 100);
  } else if (strcmp(icon, "10d") == 0) {
    // 10d - Clouds, sun, rain
    tft.drawRGBBitmap(x, y, icon_10d, 100, 100);
  } else if (strcmp(icon, "10n") == 0) {
    // 10d - Clouds, sun, rain - night
    tft.drawRGBBitmap(x, y, icon_10n, 100, 100);
  } else if (strcmp(icon, "11d") == 0 || strcmp(icon, "11n") == 0) {
    // 11d - Clouds, lightning
    tft.drawRGBBitmap(x, y, icon_11d, 100, 100);
  } else if (strcmp(icon, "13d") == 0 || strcmp(icon, "13n") == 0) {
    // 13d - Snow
    tft.drawRGBBitmap(x, y, icon_13d, 100, 100);
  } else if (strcmp(icon, "50d") == 0 ||strcmp(icon, "50n") == 0) {
    // 50d - Fog
    tft.drawRGBBitmap(x, y, icon_50d, 100, 100);
  }
}

void displayDayMinMax(int x, char* title, char* icon, char* temp1, char* temp2, char* humidity) {
  drawIcon(     x +  0,  50, icon);
  drawBigText(  x + 20,  65, ILI9341_BLACK, title);
  drawText(     x + 30, 155, ILI9341_BLACK, temp1);
  drawText(     x + 30, 180, ILI9341_RED, temp2);
  drawSmallText(x + 35, 200, ILI9341_BLACK, humidity);
}

void displayWeather(char* town, Weather* weather) {
  fillScreen(BACKGND);
  drawBigText(20, 30, ILI9341_BLACK, town);
  displayDayMinMax(0, " H", weather->iconH, weather->tempH, weather->feelsLikeH, weather->humidityH);
  displayDayMinMax(100, " J", weather->iconD, weather->tempMinD, weather->tempMaxD, weather->humidityD);
  displayDayMinMax(200, "J+1", weather->iconD1, weather->tempMinD1, weather->tempMaxD1, weather->humidityD1);
  drawSmallText(60, 230, ILI9341_BLACK, weather->updated);
}
