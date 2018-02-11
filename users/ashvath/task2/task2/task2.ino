//i have not tried the code on an ardunio,iam hoping the logic of the code is correct 
volatile byte state=LOW;
int reading;      
int previous = HIGH;    
long time = 0; 
volatile int interval;   
long debounce = 10;   
long previousMillis = 0; 
void setup() {
  pinMode(13, OUTPUT);
  pinMode(2,INPUT);
  attachInterrupt(0, blink1, RISING);

}

void loop() {
    
 unsigned long currentMillis = millis();
if (currentMillis - previousMillis >= interval) {
    
previousMillis = currentMillis;

 if (ledState == LOW)
 {
      ledState = HIGH;
    } else 
    {
      ledState = LOW;
    }
    digitalWrite(13, ledState);
  }
}

}
void blink1()//code to handle debounce of the button switch
{
 reading = digitalRead(2);
  if (reading == HIGH && previous == LOW && millis() - time > debounce) 
  {
    if (state == HIGH)
      state = LOW;
      interval=1000;//interval get updated instead of delay
    else
      state = HIGH;
      interval=2000;

    time = millis();    
  }
previous = reading;

}
