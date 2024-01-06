#define LED1 12
#define LED2 10
#define LED3 9

void setup() {
	pinMode(LED1, OUTPUT);
  	pinMode(LED2, OUTPUT);
  	pinMode(LED3, OUTPUT);
}

void loop() {
  digitalWrite(LED1, HIGH);
  delay(2000);
  digitalWrite(LED1, LOW);
  
  digitalWrite(LED2, HIGH);
  delay(2000);
  digitalWrite(LED2, LOW);

  digitalWrite(LED3, HIGH);
  delay(3000);
  digitalWrite(LED3, LOW);

}
