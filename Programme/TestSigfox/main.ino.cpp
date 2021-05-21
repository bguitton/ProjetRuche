#include<Arduino.h>
#include<Wire.h>

#include "ModemSigfox.h"
#define SERIAL_BAUD 115200

ModemSigfox *leModem;

void setup() {
    leModem=new ModemSigfox();
    mesure lesMesures;
    leModem->begin();
    leModem->ForgerTrameMesure(lesMesures);
    
    
    
}



void loop() {

}




