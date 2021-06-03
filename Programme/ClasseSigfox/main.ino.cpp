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
    
    mesureBatterie lesMesures;
    mesure lesMesures2;
    lesMesures.tensionBatterie=12.03;
    lesMesures.intensiteBatterie=-0.14;
    lesMesures.puissanceBatterie=-1.73;
    lesMesures.chargeBatterie=2.878;
    lesMesures.tauxDeChargeBatterie=41;
    
    
    lesMesures2.temperature=35.79;
   lesMesures2.humidite=46;
   lesMesures2.eclairement=7944;
   lesMesures2.pression=10142;
   float masse=44.13;
   
   Serial.println("Setup");
   leModem->ForgerTrameMesure(lesMesures2,masse);
  
    
   leModem->ForgerTrameBatterie(lesMesures);
    
    
}



void loop() {

}




