/*
Get the input from keypad (password) and display it on LCD Screen. 
Let the pin be 1234. Get the input pin from the user. 
If it matches the given pin display welcome on the LCD screen. Else display Invalid user
*/

#include <LiquidCrystal.h>
#include <Keypad.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define ROW_NUM    4
#define COLUMN_NUM 3

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte pin_rows[ROW_NUM] = {13, 10, 9, 8};
byte pin_column[COLUMN_NUM] = {A0, A1, A2};

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

const String correctPin = "1234";
String enteredPin = "";

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("PIN: " + enteredPin);
  char key = keypad.getKey();

  if (key) {
    Serial.println("Key Pressed: " + String(key));

    if (key == '#') {
      if (enteredPin == correctPin) {
        lcd.clear();
        lcd.print("Welcome");
      } else {
        lcd.clear();
        lcd.print("Invalid user");
      }
      
      delay(2000);
      lcd.clear();
      enteredPin = "";
    } else {
      enteredPin += key;
    }
  }
}
