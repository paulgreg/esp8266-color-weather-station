struct Weather {
  char iconH[10];
  char tempH[10];
  char feelsLikeH[10];
  char humidityH[6];

  char iconD[10];
  char tempMinD[10];
  char tempMaxD[10];
  char humidityD[6];

  char iconD1[10];
  char tempMinD1[10];
  char tempMaxD1[10];
  char humidityD1[6];

  char updated[20];
};

struct Location {
  char town[30];
  char url[200];
  uint16_t count;
  Weather weather;
};

void fillWeatherFromJson(Weather* weather) {
  int tempH = (int) round(json["current"]["temp"]);
  int feelsLikeH = (int) round(json["current"]["feels_like"]);
  boolean tempHLower = tempH < feelsLikeH;

  sprintf(weather->iconH, "%s", (const char*) json["current"]["weather"][0]["icon"]);
  sprintf(weather->tempH, "%2i C", tempHLower ? tempH : feelsLikeH);
  sprintf(weather->feelsLikeH, "%2i C", tempHLower ? feelsLikeH : tempH);
  sprintf(weather->humidityH, "%3i %%", (int) json["current"]["humidity"]);
  
  sprintf(weather->iconD, "%s", (const char*) json["daily"][0]["weather"][0]["icon"]);
  sprintf(weather->tempMinD, "%2i C", (int) round(json["daily"][0]["temp"]["min"]));
  sprintf(weather->tempMaxD, "%2i C", (int) round(json["daily"][0]["temp"]["max"]));
  sprintf(weather->humidityD, "%3i %%", (int) json["daily"][0]["humidity"]);

  sprintf(weather->iconD1, "%s", (const char*) json["daily"][1]["weather"][0]["icon"]);
  sprintf(weather->tempMinD1, "%2i C", (int) round(json["daily"][1]["temp"]["min"]));
  sprintf(weather->tempMaxD1, "%2i C", (int) round(json["daily"][1]["temp"]["max"]));
  sprintf(weather->humidityD1, "%3i %%", (int) json["daily"][1]["humidity"]);

  int timezone_offset = (int) json["timezone_offset"];
  int dt = (int) json["current"]["dt"];
  int t = dt + timezone_offset;
  sprintf(weather->updated, "MAJ : %02d/%02d %02d:%02d", day(t), month(t), hour(t), minute(t));
}
