const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state=LOW;
int reading;      
int previous = HIGH;    
long time = 0;   
long debounce = 10;   

void setup() {
 pinMode(ledPin, OUTPUT);
  attachInterrupt(interruptPin, blink1, CHANGE);

}

void loop() {
  if (state==LOW)
 {digitalWrite(ledPin, HIGH);
 delay(1000);
 digitalWrite(ledPin,LOW)}
 if (state==HIGH)
{ digitalWrite(ledPin,HIGH);
 delay(2000);
 digitalWrite(ledPin,LOW);
 }

}
void blink1(){
 reading = digitalRead(interruptPin);
  if (reading == HIGH && previous == LOW && millis() - time > debounce) 
  {
    if (state == HIGH)
      state = LOW;
    else
      state = HIGH;

    time = millis();    
  }
previous = reading;
}
