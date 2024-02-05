/*
Display the given text in the LCD screen.
Line 1: 19Z604 Line 2: Embedded System Lab
*/
#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
  lcd.begin(16, 2);
}

void loop()
{
  lcd.setCursor(0, 0);
  lcd.print("19Z604");
  lcd.setCursor(0, 1);
  lcd.print("Embedded System Lab");
}
