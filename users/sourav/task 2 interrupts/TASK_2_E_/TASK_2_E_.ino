int led=13;
int button=2;
int a=0;


void setup() {
  pinMode(led,OUTPUT);
  pinMode(button,INPUT);
  attachInterrupt(digitalPinToInterrupt(2),push,CHANGE);
  Serial.begin(9600);
}

void loop() {

  if(a==1)
  {Serial.print("hello123");
    digitalWrite(led,LOW);
    delay(5000);
    digitalWrite(led,HIGH);
    delay(5000);
    a=0;
    }

    else
    {
      digitalWrite(led,LOW);
    delay(1000);
    digitalWrite(led,HIGH);
    delay(1000);
    
      }

}

void push()
{
  a=1;
  }
