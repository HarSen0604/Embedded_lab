#define ROW_NUM    4
#define COLUMN_NUM 3

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6};
byte pin_column[COLUMN_NUM] = {5, 4, 3};

void setup() {
  Serial.begin(9600);
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
  if (key != -1) {
    Serial.println(key);
    delay(500); // Add a small delay to debounce the keypress
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
  return -1; // No key pressed
}
