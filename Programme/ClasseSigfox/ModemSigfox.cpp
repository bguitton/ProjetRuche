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

ModemSigfox::ModemSigfox():Sigfox(26,27,true){
    
}

void ModemSigfox::ForgerTrameMesure(mesure lesMesures,float masse){
     
   
   laTrameMesure.temperature=short(lesMesures.temperature*100);
   laTrameMesure.humidite=lesMesures.humidite;
   laTrameMesure.masse=masse;
   laTrameMesure.pression=lesMesures.pression;
   laTrameMesure.eclairement=lesMesures.eclairement; 
   laTrameMesure.typeTrame=1;
   
   bool statusSig=envoyer(&laTrameMesure,sizeof(laTrameMesure));
   
   
   
}
ModemSigfox::~ModemSigfox()
{
}