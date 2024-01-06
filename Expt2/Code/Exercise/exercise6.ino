#define BUTTON 7
#define RED 11
#define GREEN 10
#define BLUE 9

int buttonState = 0;
int lastButtonState = LOW;
int colorIndex = 0;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  int reading = digitalRead(BUTTON);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
        
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, LOW);
        digitalWrite(BLUE, LOW);

        if (colorIndex == 0) {
          digitalWrite(RED, HIGH);
        } else if (colorIndex == 1) {
          digitalWrite(GREEN, HIGH);
        } else if (colorIndex == 2) {
          digitalWrite(BLUE, HIGH);
        }

        colorIndex = (colorIndex + 1) % 3;
      }
    }
  }

  lastButtonState = reading;
}
