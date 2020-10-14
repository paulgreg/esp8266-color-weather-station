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

#define SCREEN_ORIENTATION SCREEN_HORIZONTAL_INVERSE

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
  fillScreen(ILI9341_WHITE);
  drawText(0, 0, ILI9341_BLACK, text);
}

void drawIcon(int x, int y, char* icon) {
  fillScreen(ILI9341_ORANGE);
  tft.drawRGBBitmap(  0,   0, icon_01d, 100, 100);
  tft.drawRGBBitmap(100,   0, icon_01n, 100, 100);
  tft.drawRGBBitmap(200,   0, icon_02d, 100, 100);
  tft.drawRGBBitmap(  0, 100, icon_02n, 100, 100);
  tft.drawRGBBitmap(100, 100, icon_03d, 100, 100);
//  tft.drawRGBBitmap(200, 100, icon_04d, 100, 100);
/*
icon_03d
icon_04d
icon_09d
icon_10d
icon_10n
icon_11d
icon_13d
icon_50d
  
/*  if (strcmp(icon, "01d") == 0) {
    // 01d - Sun
    tft.drawRGBBitmap(x, y, icon_01d_sun_bits, icon_01d_sun_width, icon_01d_sun_height); //, ILI9341_RED);
  } else if (strcmp(icon, "01n") == 0) {
    // 01d - Sun - night
    tft.drawRGBBitmap(x, y, icon_01d_sun_bits, icon_01d_sun_width, icon_01d_sun_height); //, ILI9341_BLACK);
  } else if (strcmp(icon, "02d") == 0) {
    // 02d - Cloud, sun
    tft.drawRGBBitmap(x, y, icon_02d_sun_bits, icon_02d_sun_width, icon_02d_sun_height); //, ILI9341_RED);
    tft.drawRGBBitmap(x, y, icon_02d_cloud_bits, icon_02d_cloud_width, icon_02d_cloud_height); //, ILI9341_BLACK);
  } else if (strcmp(icon, "02n") == 0) {
    // 02d - Cloud, sun - night
    tft.drawRGBBitmap(x, y, icon_02d_sun_bits, icon_02d_sun_width, icon_02d_sun_height); //, ILI9341_BLACK);
    tft.drawRGBBitmap(x, y, icon_02d_cloud_bits, icon_02d_cloud_width, icon_02d_cloud_height); //, ILI9341_BLACK);
  } else if (strcmp(icon, "03d") == 0 || strcmp(icon, "03n") == 0) {
    // 03d - Cloud
    tft.drawRGBBitmap(x, y, icon_03d_cloud_bits, icon_03d_cloud_width, icon_03d_cloud_height); //, ILI9341_BLACK);
  } else if (strcmp(icon, "04d") == 0) {
    // 04d - Cloud, second cloud
    tft.drawRGBBitmap(x, y, icon_04d_cloud_bits, icon_04d_cloud_width, icon_04d_cloud_height); //, ILI9341_BLACK);
    tft.drawRGBBitmap(x, y, icon_04d_cloud_back_bits, icon_04d_cloud_back_width, icon_04d_cloud_back_height); //, ILI9341_RED);
  } else if (strcmp(icon, "04n") == 0) {
    // 04d - Cloud, second cloud - night
    tft.drawRGBBitmap(x, y, icon_04d_cloud_bits, icon_04d_cloud_width, icon_04d_cloud_height); //, ILI9341_BLACK);
    tft.drawRGBBitmap(x, y, icon_04d_cloud_back_bits, icon_04d_cloud_back_width, icon_04d_cloud_back_height); //, ILI9341_BLACK);
  } else if (strcmp(icon, "09d") == 0) {
    // 09d - Clouds, rain
    tft.drawRGBBitmap(x, y, icon_09d_cloud_bits, icon_09d_cloud_width, icon_09d_cloud_height); //, ILI9341_BLACK);
    tft.drawRGBBitmap(x, y, icon_09d_rain_bits, icon_09d_rain_width, icon_09d_rain_height); //, ILI9341_RED);
  } else if (strcmp(icon, "09n") == 0) {
    // 09d - Clouds, rain - night
    tft.drawRGBBitmap(x, y, icon_09d_cloud_bits, icon_09d_cloud_width, icon_09d_cloud_height); //, ILI9341_BLACK);
    tft.drawRGBBitmap(x, y, icon_09d_rain_bits, icon_09d_rain_width, icon_09d_rain_height); //, ILI9341_BLACK);
  } else if (strcmp(icon, "10d") == 0) {
    // 10d - Clouds, sun, rain
    tft.drawRGBBitmap(x, y, icon_10d_cloud_bits, icon_10d_cloud_width, icon_10d_cloud_height); //, ILI9341_BLACK);
    tft.drawRGBBitmap(x, y, icon_10d_sun_bits, icon_10d_sun_width, icon_10d_sun_height); //, ILI9341_RED);
  } else if (strcmp(icon, "10n") == 0) {
    // 10d - Clouds, sun, rain - night
    tft.drawRGBBitmap(x, y, icon_10d_cloud_bits, icon_10d_cloud_width, icon_10d_cloud_height); //, ILI9341_BLACK);
    tft.drawRGBBitmap(x, y, icon_10d_sun_bits, icon_10d_sun_width, icon_10d_sun_height); //, ILI9341_BLACK);
  } else if (strcmp(icon, "11d") == 0) {
    // 11d - Clouds, lightning
    tft.drawRGBBitmap(x, y, icon_11d_cloud_bits, icon_11d_cloud_width, icon_11d_cloud_height); //, ILI9341_BLACK);
    tft.drawRGBBitmap(x, y, icon_11d_ligthning_bits, icon_11d_ligthning_width, icon_11d_ligthning_height); //, ILI9341_RED);
  } else if (strcmp(icon, "11n") == 0) {
    // 11d - Clouds, lightning - night
    tft.drawRGBBitmap(x, y, icon_11d_cloud_bits, icon_11d_cloud_width, icon_11d_cloud_height); //, ILI9341_BLACK);
    tft.drawRGBBitmap(x, y, icon_11d_ligthning_bits, icon_11d_ligthning_width, icon_11d_ligthning_height); //, ILI9341_BLACK);
  } else if (strcmp(icon, "13d") == 0 || strcmp(icon, "13n") == 0) {
    // 13d - Snow
    tft.drawRGBBitmap(x, y, icon_13d_snow_bits, icon_13d_snow_width, icon_13d_snow_height); //, ILI9341_BLACK);
  } else if (strcmp(icon, "50d") == 0 ||strcmp(icon, "50n") == 0) {
    // 50d - Fog
    tft.drawRGBBitmap(x, y, icon_50d_fog_bits, icon_50d_fog_width, icon_50d_fog_height); //, ILI9341_BLACK);
  }
  */
}
/*
void displayDayMinMax(int x, char* title, char* icon, char* temp1, char* temp2, char* humidity) {
  int offsetTitle = strlen(title) == 1 ? 32 : 10;
  drawBigText(x + offsetTitle, 28, title);
  drawIcon(x, 28, icon);
  drawText(x + 10, 114, temp1, ILI9341_BLACK);
  drawText(x + 10, 136, temp2, ILI9341_RED);
  drawSmallText(x + 16, 155, humidity);
}*/

void displayWeather(Weather* weather) {
  fillScreen(ILI9341_WHITE);
  //drawText(10, 20, ILI9341_BLACK, weather->timezone);
  drawIcon(10, 40, weather->iconD);
  //drawSmallText(10, 190, ILI9341_BLACK, weather->updated);
//displayDayMinMax(95, "J", weather->iconD, weather->tempMinD, weather->tempMaxD, weather->humidityD);
}
