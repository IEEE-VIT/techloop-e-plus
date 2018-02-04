#define INTERRUPT_PIN 0  //Pin 2 on UNO
#define TRIG 12
#define ECHO 2
#define LED_PIN 13

#define TIMER_US 500000

#include<TimerOne.h>

volatile unsigned long a =0, b=0,time = 0;
volatile int distance= 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(TRIG,OUTPUT);
  pinMode(LED_PIN,OUTPUT);
  
  Timer1.initialize(TIMER_US);
  Timer1.attachInterrupt(blinker);
  
  attachInterrupt(INTERRUPT_PIN, echo, CHANGE);
}

void loop() 
{
trigger();
Serial.println(distance);
}

void trigger()
{
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);
}

void echo()
{
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

void blinker()
{
  digitalWrite(LED_PIN,(!digitalRead(LED_PIN)));
}

