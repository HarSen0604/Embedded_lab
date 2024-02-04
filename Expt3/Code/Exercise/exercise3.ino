/*
Identify the Number pressed in the keypad and make the in built LED glow for the value of the number.
  i.	LED initially must be in LOW state.
  ii.	IF number pressed is 1 LED must blink once and then go to LOW state.
  iii.	IF 5 pressed then LED must blink 5 times and then go to LOW state.
  iv.	IF characters * and # are pressed no operation should occur.
*/

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
byte ledPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  
  for (byte i = 0; i < ROW_NUM; i++) {
    pinMode(pin_rows[i], INPUT_PULLUP);
  }
  for (byte i = 0; i < COLUMN_NUM; i++) {
    pinMode(pin_column[i], OUTPUT);
    digitalWrite(pin_column[i], HIGH);
  }
}

void loop() {
  char key = getKey();
  if (key != 0) {
    if (key >= '0' && key <= '9') {
      int num = key - '0';
      blinkLED(num);
    }
    delay(500); // Add a small delay to debounce the keypress
  }
}

void blinkLED(int count) {
  for (int i = 0; i < count; i++) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
}

char getKey() {
  for (byte i = 0; i < COLUMN_NUM; i++) {
    digitalWrite(pin_column[i], LOW);
    for (byte j = 0; j < ROW_NUM; j++) {
      if (digitalRead(pin_rows[j]) == LOW) {
        delay(50); // Add a small delay to debounce the keypress
        while (digitalRead(pin_rows[j]) == LOW); // Wait for the key to be released
        digitalWrite(pin_column[i], HIGH);
        return keys[j][i];
      }
    }
    digitalWrite(pin_column[i], HIGH);
  }
  return 0; // No key pressed
}
