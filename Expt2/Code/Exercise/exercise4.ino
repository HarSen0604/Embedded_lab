#define BUTTON 7
#define LED 13

int buttonState = 0;
int lastButtonState = HIGH;
int ledState = LOW;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(BUTTON);

  if (buttonState == HIGH && lastButtonState == LOW) {
    ledState = !ledState;
    digitalWrite(LED, ledState);
  }

  lastButtonState = buttonState;
}
