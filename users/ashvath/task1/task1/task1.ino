int led=2;//we can create square waves by manuplating duty cycles(0,255)

void setup()
{
  pinMode(led1,OUTPUT);
}

void loop()
{
   
  digitalWrite(led1,HIGH);
  delay(800);
  digitalWrite(led1,LOW);
  delay(200);

}  
