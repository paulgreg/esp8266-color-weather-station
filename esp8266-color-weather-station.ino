#include <TimeLib.h>
#include <Arduino_JSON.h>

JSONVar json;

#include "weather.h"
#include "parameters.h"
#include "network.h"
#include "display.h"

void setup() {
  Serial.begin(115200);
  Serial.println("\n\nLed Screen Weather Station"); 
  setupScreen();
  printMsg("Weather Station"); 
  delay(500);
}

uint16_t idx = 0;

void loop(void) {
  uint16_t i = idx % NB_LOCATIONS;
  Serial.printf("\nLocation: %s - count: %i\n", locations[i].town, locations[i].count);
  if ((locations[i].count % 25) == 0) {
    printMsg("Connecting to wifi...");
    if (!connectToWifi()) {
      printError("Can't connect to wifi !");
      delay(60 * 1000);
      return;
    } else {
      boolean jsonParsed = getJSON(locations[i].url);
      if (!jsonParsed) {
        printError("Error getting JSON");
      } else {
        fillWeatherFromJson(&locations[i].weather);
      }
    }
  }
  displayWeather(locations[i].town, &locations[i].weather);
  locations[i].count++;
  idx++;
  delay(15 * 1000);
}
