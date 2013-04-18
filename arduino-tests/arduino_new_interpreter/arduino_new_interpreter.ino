// Written by Nick Gammon
// February 2012

#include <Wire.h>


const byte MY_ADDRESS = 50;
int red = 9;
int green =10;
int blue = 11;

void setup () 
  {
  Wire.begin (MY_ADDRESS);
//  TWBR = 12;
  pinMode (red, OUTPUT);  
  pinMode (green, OUTPUT);  
  pinMode (blue, OUTPUT);
  // set up receive handler
  Wire.onReceive(receiveEvent);
  Wire.onRequest(sendData); 
  Serial.begin(9600);  
}  // end of setup

int init_c; 
int c;
int color_a[3];
int c_a =4;
int counter =1;
int start_color =0;
void loop() {
  if (start_color){
    start_color_fn();
  }
  }
 
void start_color_fn(){
  for (int i=0;i<=c_a;i++){
    Serial.println("c");
    Serial.println(c_a);
    Serial.print("i: ");
    Serial.println(int(i));
    Serial.println("red+1");
    Serial.println(9+i);

    analogWrite(9+i,color_a[i]);
    c_a++;
  }
  start_color =0;

}

// called by interrupt service routine when incoming data arrives
void receiveEvent (int howMany) {
  for (int i = 0; i < howMany; i++) {
    c = Wire.read ();
    Serial.println(c);
    if (char(c) == 'C') {
      Serial.println("init");
      init_c = 1;
      c_a=0;
    } else if (init_c){
          if (char(c) == 'X') {
          Serial.println("end communication");
          init_c=0;
          counter=0;
          start_color =1;
          } else {
          Serial.println("set color");
          color_a[counter] = c;
        }
    } else {
      Serial.println("break");
    }

}
}

void sendData(){ 
}
