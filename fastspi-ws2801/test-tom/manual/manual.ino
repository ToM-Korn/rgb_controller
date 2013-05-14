

int SDI = 20; //Red wire (not the red 1V wire!)
int CKI = 21; //Green wire
int ledPin = 13; //On board LED


void setup() {
  pinMode(SDI, OUTPUT);
  pinMode(CKI, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
 
}

void loop() {
 
 while (1){ 
 
 int counter =0;
   
 for (int i = 0; i<2; i++){


  for (int R = 0; R<=7; R++){
    if (counter) {
    digitalWrite(CKI, LOW);
    
    } else {
    counter =1;
    }

    digitalWrite(SDI, HIGH);

    digitalWrite(CKI, HIGH);

  }
  for (int R = 0; R<=7; R++){
    digitalWrite(CKI, LOW);

    digitalWrite(SDI, LOW);

    digitalWrite(CKI, HIGH);

  }
  for (int R = 0; R<=7; R++){
    digitalWrite(CKI, LOW);

    digitalWrite(SDI, LOW);

    digitalWrite(CKI, HIGH);

  }
  
  }
  digitalWrite(CKI, LOW);
  delayMicroseconds(500); //Wait for 100us to go into reset

 }
 

  

} 


