#include <Adafruit_GFX.h>       // include Adafruit graphics library
#include <Adafruit_ILI9341.h>   // include Adafruit ILI9341 TFT library
 
#define TFT_CS    D2            // TFT CS  pin is connected to NodeMCU pin D2
#define TFT_RST   D3            // TFT RST pin is connected to NodeMCU pin D3
#define TFT_DC    D4            // TFT DC  pin is connected to NodeMCU pin D4
Adafruit_ILI9341  tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

#include <TimeLib.h>
#include <Arduino_JSON.h>

JSONVar json;

#include "parameters.h"
#include "weather.h"
#include "network.h"
#include "display.h"

void setup() {
  Serial.begin(115200);
  Serial.println("\n\nLed Screen Weather Station"); 
  setupScreen();
  //printMsg("Weather Station"); 
  //delay(1000);
}

void loop(void) {
/*
  printMsg("Connecting to wifi");
  if (!connectToWifi()) {
    printMsg("Can't connect to wifi");
  } else {    
    boolean jsonParsed = getJSON(URL);
    if (!jsonParsed) {
      printMsg("Error getting JSON");
    } else {
      Weather weather;
      fillWeatherFromJson(&weather);
      displayWeather(&weather);
    }
  }
*/
Weather weather;
displayWeather(&weather);
  delay(5 * 60 * 1000);
}
