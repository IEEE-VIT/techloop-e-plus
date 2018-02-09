int buttonPin=2; //set button to pin 2
int ledPin=13; //set led to pin 13
int buttonStateSpeed=0; //initially setting button to 0

void setup() {
  PinMode(ledPin,OUTPUT); //declaring led as output 
  PinMode(buttonPin,INPUT); //declaring button as input
  attachInterrupt(0,buttonLed,CHANGE); //interrupt whenever theres is a change of state of pin 2
  }



void buttonLed(){
  buttonState= digitalRead(buttonPin); //read the state of button
  
  if buttonState==HIGH{
    
    buttonStateSpeed= 10; //if button is pressed, make the led blink fast
    
    }
    
    if buttonState==LOW{

    buttonStateSpeed= 1000; //if the button is released, make the led blink slower
    }
    
}

void loop() {
  
  digitalWrite(ledPin,HIGH);  //blinking of led according to the state of the button
    delay(buttonStateSpeed);
    digitalWrite(ledPin,LOW);
    delay(uttonStateSpeed);
 
 }


