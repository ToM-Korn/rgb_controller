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

void loop() 
  {
    int red_fading;
    int green_fading;
    int blue_fading; 
    
    if (fader_red > red_actual){
      red_fading = red_actual +1;
    } else if (fader_red < red_actual) {
      red_fading = red_actual -1;
    } else {
     red_fading = red_actual;
    }

    if (fader_green > green_actual){
      green_fading = green_actual +1;
    } else if (fader_green < green_actual) {
      green_fading = green_actual -1;
    } else {
     green_fading = green_actual;
    }
    
    if (fader_blue > blue_actual){
      blue_fading = blue_actual +1;
    } else if (fader_blue < blue_actual) {
      blue_fading = blue_actual -1;
    } else {
     blue_fading = blue_actual;
    }

    
    if (red_actual != red_fading) {
      analogWrite(red,red_fading);
      red_actual = red_fading;
    }
    if (green_actual != green_fading) {
      analogWrite(green,green_fading);
      green_actual = green_fading;
    }
    if (blue_actual != blue_fading) {
      analogWrite(blue,blue_fading);
      blue_actual=blue_fading;
    }
    delay(1);
    
    
  }
 
unsigned int c;
int color[4] = {};
unsigned int init = 0;
int array_counter =0;
char test_char;
// called by interrupt service routine when incoming data arrives
void receiveEvent (int howMany) {
  for (int i = 0; i < howMany; i++) {
    c = Wire.read ();
    Serial.println(c);
    test_char = char(c);
    if (init ==0){
      if (test_char == 'C' && init !=1){
        init = 1;
        Serial.println("got init");
        break;
      }
    } else {
      if (init == 1 && test_char != 'X'){
        color[array_counter] = c;
        array_counter++;
        Serial.println("set color");
    }
      if (test_char == 'C' && init !=1){
        init = 1;
        Serial.println("got init");
        break;
      }
      if (test_char == 'X') {
        init=0;
        array_counter=0;
        Serial.println("exit setmode - start colorfader");

      }
      else if (init == 1 && test_char != 'X'){
        color[array_counter] = c;
        array_counter++;
        Serial.println("set color");

      }
      else if (test_char == 'X') {
        init=0;
        array_counter=0;
        Serial.println("exit setmode - start colorfader");

      }


      if (test_char == 'R' && init ==1 && color_select !=1){
        color_select =1;
        color = 0;
            Serial.println("got r");
            break;
      }
      if (test_char == 'G' && init ==1 && color_select !=1){
        color_select =1;
        color = 1;
            Serial.println("got g");
            break;
      }
      if (test_char == 'B' && init ==1 && color_select !=1){
        color_select =1;
        color = 2;
                    Serial.println("got B");
                    break;

      }
      if (init==1 && color_select==1){
        switch (color) {
          case 0:
            fader_red = c;
            init =0;
            color_select =0;
        Serial.println("setting r");

          break;
          case 1:
            fader_green = c;
            init =0;
            color_select =0;
            Serial.println("setting g");

          break;
          case 2:
            fader_blue = c;
            init =0;
            color_select =0;
            Serial.println("settnig b");

          break;
        }
      }
   }

void sendData()
{ 
}
  
/*  for (int i = 0; i < howMany; i++)
    {
    byte c = Wire.read ();
    Serial.println(c);
    char test_char = char(c);
    if (init){
    
    } else if (test_char = 'C') {
     color init = 1;
    } else {
    
    }
*/
    // toggle requested LED
    //if (digitalRead (c) == LOW)
    //  digitalWrite (c, HIGH);
    //else
    //  digitalWrite (c, LOW);
//    }  // end of for loop
}  // end of receiveEvent
