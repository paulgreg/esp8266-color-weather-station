
ILI9341 TFT screen

The ILI9341 TFT display is connected to the NodeMCU board as follows:
CS pin is connected to D2 (ESP8266EX GPIO4),
RST pin is connected to D3 (ESP8266EX GPIO0),
D/C pin is connected to D4 (ESP8266EX GPIO2),
MOSI pin is connected to D7 (ESP8266EX GPIO13),
SCK pin is connected to D5 (ESP8266EX GPIO14),
VCC and BL are connected to pin 3V3,
GND is connected to pin GND of the NodeMCU board.


To transform image : http://www.rinkydinkelectronics.com/t_imageconverter565.php
or GIMP (https://www.gimp.org/) as follows:
    1. File -> Export As
    2. In Export Image dialog, use 'C source code (*.c)' as filetype.
    3. Press export to get the export options dialog.
    4. Type the desired variable name into the 'prefixed name' box.
    5. Uncheck 'GLIB types (guint8*)'
    6. Check 'Save as RGB565 (16-bit)'
    7. Press export to save your image.

Source : https://github.com/adafruit/Adafruit_ILI9341/blob/master/examples/pictureEmbed/pictureEmbed.ino
