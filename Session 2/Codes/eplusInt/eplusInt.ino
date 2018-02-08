#define INTERRUPT_PIN 0  //Pin 2 on UNO
#define TRIG 12
#define ECHO 2

#include<TimerOne.h>

volatile unsigned long a =0,b=0,time = 0;
volatile int distance= 0;

void echo()
{
   if (digitalRead(ECHO)==HIGH)
   int lastButtonState = LOW;
  int currentButtonState = digitalRead(buttonPin);
  if (currentButtonState == HIGH && lastButtonState == LOW) {
     // Switch the state of the output
     digitalWrite(ledPin, !digitalRead(ledPin));
     lastButtonState = currentButtonState;
}
}

void blink()
{
  //a = 0; //for the inefficient method
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);
}

void setup() 
{
  Serial.begin(9600);
  pinMode(TRIG,OUTPUT);
  attachInterrupt(INTERRUPT_PIN, echo, CHANGE);
}

void loop() 
{
blink();
Serial.println(distance);
}
