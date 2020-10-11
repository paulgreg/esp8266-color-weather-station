#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

boolean connectToWifi() {
  Serial.printf("\nconnecting to %s\n", WIFI_SSID);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  unsigned int retries = 100;
  while (WiFi.status() != WL_CONNECTED && (retries-- > 0)) {
    Serial.print(".");
    delay(500);
  }
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("\nWifi connection failed");
    return false;
  }
  Serial.print("\nwifi connected\nIP address: ");
  Serial.println(WiFi.localIP());
  // to force DNS : WiFi.config(WiFi.localIP(), WiFi.gatewayIP(), WiFi.subnetMask(), IPAddress(9,9,9,9));
  return true;
}

boolean getJSON(const char* url) {
  boolean success = false;
  WiFiClient client;
  HTTPClient http;

  if ((WiFi.status() == WL_CONNECTED)) {
    Serial.printf("Connecting to %s\n", url);
    http.begin(client, url);
    int httpCode = http.GET();
    Serial.printf("GET - status: %d\n", httpCode);
    if (httpCode > 0 && httpCode == HTTP_CODE_OK) {
      json = JSON.parse(http.getString());
      if (JSON.typeof(json) == "undefined") {
        Serial.println("Parsing input failed!");
      } else {
        success = true;
      }
    } else {
      Serial.printf("GET failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();
  }  
  return success;
}
