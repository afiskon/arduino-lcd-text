#include <Arduino.h>
#include "LiquidCrystal.h"

/* RS, E, DB4-DB7 */
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup()
{
    /* number of columns and rows */
    lcd.begin(16, 2);

    /* select page 0 (selected by default) */
    lcd.command(0b101000);
    /* select page 1: */
    /* lcd.command(0b101010); */

    lcd.setCursor(0, 0);
    lcd.print("Te\xbay\xe6""ee \xb3pe\xbc\xc7:");
    /* lcd.print("Current time:"); */
}

void loop()
{
    delay(100);
    
    lcd.setCursor(0, 1);
    unsigned long tstamp = millis();
    int h = tstamp / 1000 / 60 / 60;
    int m = (tstamp / 1000 / 60) % 60;
    int s = (tstamp / 1000) % 60;

/*
     String line = String(h) + "h " +
                  String(m) + "m " +
                  String(s) + "s";
*/

     String line = String(h) + "\xc0 " +
                  String(m) + "\xbc " +
                  String(s) + "c";

    int len = line.length();
    while(len < 16)
    {
        line += " ";
        len++;
    }

    lcd.print(line);
}
