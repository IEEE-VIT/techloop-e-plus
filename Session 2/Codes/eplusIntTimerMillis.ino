#define INTERRUPT_PIN 0  //Pin 2 on UNO
#define TRIG 12
#define ECHO 2
#define LED_PIN 13

#define LED2_POS 8
#define LED2_NEG 9

#define TIMER_US 500000

#include<TimerOne.h>

volatile unsigned long a =0, b=0, time = 0, prevTime = 0, currTime =0;
volatile int distance= 0;

int interval = 1000;

bool state = 0; // 1 : Increasing delay , 0 : Decreasing Delay

void setup() 
{
  Serial.begin(9600);
  pinMode(TRIG,OUTPUT);
  pinMode(LED_PIN,OUTPUT);

  pinMode(LED2_POS, OUTPUT);
  pinMode(LED2_NEG, OUTPUT);
  digitalWrite(LED2_NEG,LOW);
  
  Timer1.initialize(TIMER_US);
  Timer1.attachInterrupt(blinker);
  
  attachInterrupt(INTERRUPT_PIN, echo, CHANGE);
}

void loop() 
{
trigger();
currTime = millis();
if(currTime - prevTime >= interval)
{
  digitalWrite(LED2_POS,(!digitalRead(LED2_POS)));
  if(state == 0)
  {
    interval -= 50;
    if(interval == 0)
    {
      state = 1;
    }
  }
  else if(state == 1)
  {
    interval += 50;
    if(interval == 1000)
    {
      state = 0;
    }
  }
  prevTime = currTime;
}
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

