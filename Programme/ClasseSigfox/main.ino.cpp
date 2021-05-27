#include<Arduino.h>
#include<Wire.h>

#include "ModemSigfox.h"
#define SERIAL_BAUD 115200

//ModemSigfox leModem();
ModemSigfox *leModem;

void setup() {
    Serial.begin(SERIAL_BAUD);
    leModem = new ModemSigfox();
    leModem->begin();
    
    mesure lesMesures;
    
    
    lesMesures.temperature=35.79;
   lesMesures.humidite=46;
   lesMesures.eclairement=7944;
   lesMesures.pression=10142;
   float masse=44.13;
   Serial.println("Setup");
  
    
   leModem->ForgerTrameMesure(lesMesures,masse);
    
    
}



void loop() {

}




