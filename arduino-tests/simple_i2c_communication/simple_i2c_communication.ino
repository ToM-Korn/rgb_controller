// Written by Nick Gammon
// February 2012

#include <Wire.h>


const byte MY_ADDRESS = 40;
int red = 9;
int green =10;
int blue = 11;

int TestLed = 13;

void setup () 
  {
  Wire.begin (MY_ADDRESS);
  TWAR = (MY_ADDRESS << 1) | 1;  // enable broadcasts to be received

//  TWBR = 12;
  pinMode (red, OUTPUT);  
  pinMode (green, OUTPUT);  
  pinMode (blue, OUTPUT);
  // set up receive handler
  Wire.onReceive (receiveEvent);
  Serial.begin(9600);  
  //testrun leds

  digitalWrite(red,1);
  digitalWrite(green,1);
  digitalWrite(blue,1);
  digitalWrite(TestLed,1);
  delay (1000);
  digitalWrite(red,0);
  digitalWrite(green,0);
  digitalWrite(blue,0);
  digitalWrite(TestLed,0);
  delay (1000);
  

  
}  // end of setup


void loop() {

  }
 
unsigned int c =0; 
// called by interrupt service routine when incoming data arrives
void receiveEvent (int howMany) {
  digitalWrite(TestLed,HIGH);
  for (int i = 0; i < howMany; i++) {
    c = Wire.read ();
    Serial.println(c);
    Serial.println(int(c));    
    
    if (c == 1) {
      digitalWrite(red_led,HIGH);
    } else {
      digitalWrite(red_led,LOW);
    }
  }
     digitalWrite(TestLed,LOW);
}  
