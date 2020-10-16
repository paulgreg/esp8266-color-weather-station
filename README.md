# ESP8266 Weather Station

That project is another version of my [esp32 weather station](https://github.com/paulgreg/esp32-weather-station), using here an esp8266 and a TFT screen to display multiple locations.

## Hardware

  - esp8266
  - ILI9341 TFT screen compatible 3.3V

The ILI9341 TFT display is connected to the NodeMCU board as follows:
 - CS pin is connected to D2 (GPIO4),
 - RST pin is connected to D3 (GPIO0),
 - D/C pin is connected to D4 (GPIO2),
 - MOSI pin is connected to D7 (GPIO13),
 - SCK pin is connected to D5 (GPIO14),
 - VCC and BL are connected to pin 3V3,
 - GND is connected to pin GND of the NodeMCU board.

## Arduino env

use Board "NodeMCU 1.0 (ESP12E)" to build with Arduino IDE.

Copy `parameters.h.dist` to `parameters.h` and update it with your wifi settings and update the locations array (you need to change lat/lng and set your OpenWeatherMap API token).

## Weather API

  * https://openweathermap.org/api/one-call-api
  * create an account and an API KEY

## Icons

Icons are [official icons from OpenWeatherMap](https://openweathermap.org/weather-conditions#How-to-get-icon-URL).

I’ve used Gimp to convert them into BMP then used [lcd-image-converter](https://sourceforge.net/projects/lcd-image-converter/) to transform them into `.h` file.
You’ll need to set color profile to R5G6B5 and little-endian.

## ILI9341 library

Here’s useful links :

 -  https://github.com/adafruit/Adafruit_ILI9341/blob/master/Adafruit_ILI9341.h
 -  https://github.com/adafruit/Adafruit-GFX-Library/blob/master/Adafruit_GFX.cpp
 - https://github.com/adafruit/Adafruit_ILI9341/blob/master/examples/pictureEmbed/pictureEmbed.ino

## HTTP request & JSON parsing

  * https://randomnerdtutorials.com/esp32-http-get-post-arduino/

