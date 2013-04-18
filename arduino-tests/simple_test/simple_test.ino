// Written by Nick Gammon
// February 2012

#include <Wire.h>


const byte MY_ADDRESS = 50;
int red = 9;
int green =10;
int blue = 11;

int TestLed = 13;
int red_actual;
int green_actual;
int blue_actual;

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

int fader_red;
int fader_green;
int fader_blue;

void loop() 
  {

    
    
  }
 


unsigned int color_init = 0;
unsigned int color_select =0;
unsigned int color =0;
// called by interrupt service routine when incoming data arrives
void receiveEvent (int howMany) {
  digitalWrite(TestLed,HIGH);
  for (int i = 0; i < howMany; i++) {
    Serial.println(howMany);
    int c = Wire.read ();
    Serial.println(c);  
    char test = char(c);
      if (test == 'C' && color_init !=1){
        color_init = 1;
            Serial.println("got c");
            break;
      }
      if (test == 'R' && color_init ==1 && color_select !=1){
        color_select =1;
        color = 0;
            Serial.println("got r");
            break;
      }
      if (test == 'G' && color_init ==1 && color_select !=1){
        color_select =1;
        color = 1;
            Serial.println("got g");
            break;
      }
      if (test == 'B' && color_init ==1 && color_select !=1){
        color_select =1;
        color = 2;
                    Serial.println("got B");
                    break;

      }
      if (color_init==1 && color_select==1){
        switch (color) {
          case 0:
              analogWrite(red,c);
              color_init =0;
            color_select =0;
        Serial.println("setting r");

          break;
          case 1:
              analogWrite(green,c);

            color_init =0;
            color_select =0;
            Serial.println("setting g");

          break;
          case 2:
            analogWrite(blue,c);
            color_init =0;
            color_select =0;
            Serial.println("settnig b");

          break;
        }
      }
   }
     digitalWrite(TestLed,LOW);
}  
