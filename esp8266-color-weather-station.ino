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
  printMsg("Station Meteo"); 
  delay(500);
}

uint16_t idx = 0;

void loop(void) {
  uint16_t i = idx % NB_LOCATIONS;
  Serial.printf("\nLocation: %s - count: %i\n", locations[i].town, locations[i].count);
  if ((locations[i].count % 50) == 0) {
    printMsg("Connexion au wifi...");
    if (!connectToWifi()) {
      printError("Erreur wifi !");
      delay(60 * 1000);
      return;
    } else {
      boolean jsonParsed = getJSON(locations[i].url);
      if (!jsonParsed) {
        printError("Erreur JSON");
      } else {
        fillWeatherFromJson(&locations[i].weather);
      }
    }
  }
  displayWeather(locations[i].town, &locations[i].weather);
  locations[i].count++;
  idx++;
  delay(8 * 1000);
}
