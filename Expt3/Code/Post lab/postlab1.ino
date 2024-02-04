/* Write an arduino sketch to perform the following:
a. Scan the input entered by the user in the key pad.
b. Convert the entered ASCII into integer and display it in the serial monitor.
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
    Serial.println("Key Pressed: " + String(key));
    
    if (key >= '0' && key <= '9') {
      inputBuffer += key;
    } else if (key == '#') {
      if (inputBuffer.length() > 0) {
        int inputValue = inputBuffer.toInt();
        if (inputValue >= 0 && inputValue <= 255) {
          Serial.println("Valid Input: " + String(inputValue));
          
          // Convert the integer to corresponding ASCII
          char asciiValue = inputValue;
          Serial.println("ASCII Value: " + String(asciiValue));
        } else {
          Serial.println("Invalid Input. Input should be between 0 and 255.");
        }
        inputBuffer = ""; // Clear the input buffer
      } else {
        Serial.println("Invalid Input. Input is empty.");
      }
    }
  }
}
