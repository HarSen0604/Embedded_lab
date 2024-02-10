/*
Scroll the given text. (19Z604 – Embedded Systems Lab)
*/

#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("19z604 Embedded Systems Laboratory");
  delay(1000);
}

void loop() {
  lcd.setCursor(0, 0);
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
//lcd.scrollDisplayRight() for scrolling the text from left to right
    lcd.scrollDisplayLeft();
    delay(100);
  }
}
