#define LED 13
#define BUTTON 7

void setup()
{
  pinMode(LED,OUTPUT);
  pinMode(BUTTON,INPUT_PULLUP);
}

void loop()
{
  int digitalVal = digitalRead(BUTTON);

  if(HIGH == digitalVal)
  {
    digitalWrite(LED,LOW);
  }
  else
  {
    digitalWrite(LED,HIGH);
  }
}
