/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModemSigfox.h
 * Author: bguitton
 *
 * Created on 21 mai 2021, 10:31
 */

#ifndef MODEMSIGFOX_H
#define MODEMSIGFOX_H
#include "sigfox.h"

struct trameMesure{
    short temperature;
    char humidite;
    unsigned short masse;
    unsigned short eclairement;
    unsigned short pression;
    short pointDeRosee;
    char typeTrame=1;
};

struct mesure {
    float temperature;
    float humidite;
    float pression;
    float eclairement;
};


class ModemSigfox : public Sigfox
{
    
public:
    
    ModemSigfox();
    void ForgerTrameMesure(mesure lesMesures,float masse);
     virtual ~ModemSigfox();
   // trameBatterie ForgerTrameBatterie();
    
private:
    trameMesure laTrameMesure;

};

#endif /* MODEMSIGFOX_H */

