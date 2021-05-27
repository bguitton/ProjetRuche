/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModemSigfox.cpp
 * Author: bguitton
 * 
 * Created on 21 mai 2021, 10:31
 */

#include "ModemSigfox.h"

ModemSigfox::ModemSigfox():Sigfox(27,26,true){
    
}

void ModemSigfox::ForgerTrameMesure(mesure lesMesures,float masse){
     
   
   laTrameMesure.temperature = (short)(lesMesures.temperature*100);
   laTrameMesure.humidite = (char)lesMesures.humidite;
   laTrameMesure.masse = (short)(masse*100);
   laTrameMesure.pression=(short)lesMesures.pression;
   laTrameMesure.eclairement=(short)lesMesures.eclairement; 
   laTrameMesure.pointDeRosee=2234;
   laTrameMesure.typeTrame=1;
   
    bool StatusSig=envoyer((void*)&laTrameMesure,sizeof(laTrameMesure));
    Serial.println("Envoi effectuer");
   
   
}
ModemSigfox::~ModemSigfox()
{
}