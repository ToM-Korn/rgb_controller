// Written by Nick Gammon
// February 2012

#include <Wire.h>

byte SLAVE_ADDRESS;
const byte LED = 13;

void setup () 
  {
  Wire.begin ();
//  TWBR = 12;
  pinMode (LED, OUTPUT);
Serial.begin(9600);  
  }  // end of setup

unsigned int color_code = 0;
unsigned int red_led = 0;
unsigned int green_led = 0;
unsigned int blue_led =0;
unsigned int color_select =0;

void transmit_pwm(){
Wire.beginTransmission (SLAVE_ADDRESS);
   switch (color_select) {
   case 0:
     Wire.write (red_led);
     Serial.println(red_led);
   break;
   case 1:
     Wire.write (green_led);
      Serial.println(green_led);
   break;
   case 2:
     Wire.write (blue_led);
     Serial.println(blue_led);
   break;
   }
   if (Wire.endTransmission () == 0) {
     digitalWrite(LED,HIGH);
     Serial.println("pwm send");
     if (color_select == 2){
       color_select = 0;
       if (color_code == 5) {
         color_code=0;
       } else {
         color_code ++;
       }       
       delay(5000);
     } else {
         color_select ++;
     }
   } else {
     Serial.println('pwm not send');
     digitalWrite(LED,LOW);
     transmit_pwm();
   }

}

void transmit_color (){
  Wire.beginTransmission (SLAVE_ADDRESS);
  Wire.write ('C');
  if (Wire.endTransmission () == 0) {
    Wire.beginTransmission (SLAVE_ADDRESS);
    digitalWrite(LED,HIGH);
    switch (color_select) {
    case 0:
      Serial.println("R");
      Wire.write ('R');
   break;
   case 1:
      Serial.println("G");
      Wire.write ('G');
    break;
    case 2:
      Serial.println("B");
      Wire.write ('B');
    break;
    }
    if (Wire.endTransmission () == 0) {
      Serial.println("color_send");
      digitalWrite(LED,HIGH);
      transmit_pwm();
    } else {
      digitalWrite(LED,LOW);
      Serial.println("color_not_send");
      color_select = 0;
    } 
  
  
  } else {
    digitalWrite(LED,LOW);
    transmit_color();
  }
  
}

void loop ()  {
  
  if(SLAVE_ADDRESS == 42){
  SLAVE_ADDRESS = 43;
  } else if (SLAVE_ADDRESS == 43){
  SLAVE_ADDRESS = 42;
  } else {
  SLAVE_ADDRESS = 42;  
  }
  switch (color_code) {
  case 0:
    red_led =255;
    green_led = 0;
    blue_led =0;
    transmit_color();
  break;
  case 1:
    red_led =255;
    green_led = 255;
    blue_led =0;
    transmit_color();
  break;
  case 2:
    red_led =0;
    green_led = 255;
    blue_led =0;
    transmit_color();
  break;
  case 3:
    red_led =0;
    green_led = 255;
    blue_led =255;
    transmit_color();
  break;
  case 4:
    red_led =0;
    green_led = 0;
    blue_led =255;
    transmit_color();
  break;
  case 5:
    red_led =255;
    green_led = 255;
    blue_led =255;
    transmit_color();
  break;
  default:
    red_led = 0;
    green_led = 0;
    blue_led =0;
    transmit_color();
  break;  
  
  }

delay (50);
    }  // end of for loop
//  }  // end of loop
