int led=7;

void setup()
{
  pinMode(led,OUTPUT);
}

void loop()
{
  //for 10% modulation , led should be high for 10% of the time . Lets take 1 second as 100%. 
  digitalWrite(led,HIGH);
  delay(100);
  digitalWrite(led,LOW);
  delay(900);


  //similarly, for 50% modulation, led would be on for 500 microseconds.
  digitalWrite(led,HIGH);
  delay(500);
  digitalWrite(led,LOW);
  delay(500);
}  

