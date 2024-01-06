#define R_LED 8
#define Y_LED 6
#define G_LED 4

void setup() {
	pinMode(R_LED, OUTPUT);
  	pinMode(Y_LED, OUTPUT);
  	pinMode(G_LED, OUTPUT);
}

void loop() {
  digitalWrite(R_LED, HIGH);
  delay(45 * 1000);
  digitalWrite(R_LED, LOW);
  
  digitalWrite(Y_LED, HIGH);
  delay(5 * 1000);
  digitalWrite(Y_LED, LOW);

  digitalWrite(G_LED, HIGH);
  delay(50 * 1000);
  digitalWrite(G_LED, LOW);

}
