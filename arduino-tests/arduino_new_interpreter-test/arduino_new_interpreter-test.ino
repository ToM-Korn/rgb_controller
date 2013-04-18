// Written by Nick Gammon
// February 2012

#include <Wire.h>


const byte MY_ADDRESS = 42;
int red = 9;
int green =10;
int blue = 11;

int red_actual;
int green_actual;
int blue_actual;

void setup () 
  {
  Wire.begin (MY_ADDRESS);
//  TWBR = 12;
  pinMode (red, OUTPUT);  
  pinMode (green, OUTPUT);  
  pinMode (blue, OUTPUT);
  // set up receive handler
  Wire.onReceive (receiveEvent);
  Wire.onRequest(sendData); 
  Serial.begin(9600);  
}  // end of setup

int fader_red;
int fader_green;
int fader_blue;

void loop() {

    
  }
 
unsigned int c;
// called by interrupt service routine when incoming data arrives
void receiveEvent (int howMany) {
  for (int i = 0; i < howMany; i++) {
    c = Wire.read ();
    Serial.println(c);
   
   }
 }

void sendData()
{ 
}
