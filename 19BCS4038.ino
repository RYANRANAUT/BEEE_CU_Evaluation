const int  buttonPin = 12;    
const int ledPin = 13;    

int buttonPushCounter = 0;  
int buttonState = 0;        
int lastButtonState = 0;  
void setup()
{
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      Serial.println("off");
   delay(50);
  }
  lastButtonState = buttonState;
  while (buttonPushCounter!=0)
  {
    for(int i=0;i<buttonPushCounter;i++)
    {
    digitalWrite(ledPin, HIGH);
 delay(500);
    digitalWrite(ledPin, LOW);
  delay(500);
    buttonPushCounter=buttonPushCounter-1;
  }
  }
}
}
