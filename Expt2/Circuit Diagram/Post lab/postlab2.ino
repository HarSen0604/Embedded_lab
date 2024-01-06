#define LED1 8
#define LED2 9
#define LED3 10

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  for (int i = 0; i <= 7; i++) {
    displayBinary(i);
    delay(1000);
  }
}

void displayBinary(int num) {
  digitalWrite(LED1, num & 0b001);
  digitalWrite(LED2, (num >> 1) & 0b001);
  digitalWrite(LED3, (num >> 2) & 0b001);
}
