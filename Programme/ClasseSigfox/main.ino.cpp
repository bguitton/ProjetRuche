#include<Arduino.h>
#include<Wire.h>

#include "ModemSigfox.h"
#define SERIAL_BAUD 115200

//ModemSigfox leModem();
ModemSigfox *leModem;

void setup() {
    Serial.begin(SERIAL_BAUD);
    leModem=new ModemSigfox();
    leModem->begin();
    mesure lesMesures;
    
    
    lesMesures.temperature=35.46;
   lesMesures.humidite=36;
   lesMesures.eclairement=44898;
   lesMesures.pression=10132;

  
    
    
    
    
}



void loop() {

}




