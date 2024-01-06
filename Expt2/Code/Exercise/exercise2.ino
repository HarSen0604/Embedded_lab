#define RED 11
#define GREEN 10
#define BLUE 9

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);

  delay(1000);

  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, LOW);

  delay(1000);

  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, HIGH);

  delay(1000);
}
