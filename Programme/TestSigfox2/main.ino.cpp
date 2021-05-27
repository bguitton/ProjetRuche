/*
   Bridge Série pour modem SigFox 
 * Projet ballon sonde
*/
#include <HardwareSerial.h>
#define LED 22


HardwareSerial serialSigfox(2);


void setup() {
  Serial.begin(9600);
  serialSigfox.begin(9600, SERIAL_8N1, 27, 26);
  Serial.println("Sigfox Serial Bridge");
  
  pinMode(LED, OUTPUT);
}



void loop() {
  
  char car;
  
  if (Serial.available() > 0) {
    car = Serial.read();
    serialSigfox.write(car);
    Serial.write(car);
  }

  if (serialSigfox.available() > 0) {
    car = serialSigfox.read();
    Serial.write(car);
  }
  
}
