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
  printMsg("Weather\nStation"); 
  delay(500);
}

void loop(void) {
  printMsg("Connecting to wifi");
  if (!connectToWifi()) {
    printError("Can't connect to wifi");
  } else {    
    boolean jsonParsed = getJSON(URL);
    if (!jsonParsed) {
      printError("Error getting JSON");
    } else {
      Weather weather;
      fillWeatherFromJson(&weather);
      displayWeather(&weather);
    }
  }
  delay(5 * 60 * 1000);
}
