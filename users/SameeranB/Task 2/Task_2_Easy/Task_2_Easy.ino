int button=2;
int dl= 100;
int led=7;

void setup()
{
  pinMode(button,INPUT);
  pinMode(led,OUTPUT);
  attachInterrupt(0,switcher,CHANGE);

}
 void switcher()
 {
   if (dl==100)
   {
     dl=800;
   }
   else
   {
     dl=100;
   }
 }
  void loop()
 {
   digitalWrite(led,HIGH);
   delay(dl);
   digitalWrite(led,LOW);
   delay(dl);
 }
   
