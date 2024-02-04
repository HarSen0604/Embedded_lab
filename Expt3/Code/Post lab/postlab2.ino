/*
Write an arduino sketch to perform the following:
    a.  Scan the input entered by the user in the key pad.
    b.  Extract the value. The inbuilt LED must be in HIGH state for the value Seconds and must remain in LOW state otherwise.
        Eg: Value pressed is 5. LED must be HIGH for 5 Seconds, and then it must remain LOW.
*/

#include <Keypad.h>

#define ROW_NUM    4
#define COLUMN_NUM 3

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte pin_rows[ROW_NUM] = {10, 9, 8, 7};
byte pin_column[COLUMN_NUM] = {6, 5, 4};

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

String inputBuffer = "";

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    if (key >= '0' && key <= '9') {
      int inputValue = key - '0';
      
      if (inputValue >= 0 && inputValue <= 9) {
        Serial.println("Valid Input: " + String(inputValue));
        
        // Turn on the LED for the entered value in seconds
        digitalWrite(LED_BUILTIN, HIGH);
        delay(inputValue * 1000);
        digitalWrite(LED_BUILTIN, LOW);
      } 
      else {
        Serial.println("Invalid Input. Please enter a single digit integer.");
      }
    }
    else {
        Serial.println("Invalid Input. Please enter a single digit integer.");
    }
  }
}
