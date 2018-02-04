#define INTERRUPT_PIN 0  //Pin 2 on UNO
#define TRIG 12
#define ECHO 2

#include<TimerOne.h>

volatile unsigned long a =0,b=0,time = 0;
volatile int distance= 0;

void echo()
{
  //This below method is inefficient as shown in session
  /*  
  if(a==0)
  {
    a = micros();
  }
  else
  {
    time = micros() - a;
  }
  */
  //Below is efficient method
  switch (digitalRead(ECHO))
  {
    case HIGH:  
      b = 0;
      a = micros();
      break;
      
    case LOW: 
      b = micros();
      time = b - a; 
      break;
  }
  
  distance = time/58;
}

void trigger()
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
trigger();
Serial.println(distance);
}
