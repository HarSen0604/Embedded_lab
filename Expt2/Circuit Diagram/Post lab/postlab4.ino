void setup() {
  for (int i = 8; i >= 2; i--) {
  	pinMode(i, OUTPUT);
  }
}

void loop() {
  for (int i = 8; i >= 2; i--) {
	digitalWrite(i, HIGH);
    delay(1000);
 	digitalWrite(i, LOW);
  }
}
