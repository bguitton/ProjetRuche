/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Environnement.cpp
 * Author: bguitton
 * 
 * Created on 26 mars 2021, 11:14
 */

#include "Environnement.h"
 

Environnement::Environnement() {
    
BME280I2C::Settings settings(
            BME280::OSR_X1,
            BME280::OSR_X1,
            BME280::OSR_X1,
            BME280::Mode_Forced,
            BME280::StandbyTime_1000ms,
            BME280::Filter_Off,
            BME280::SpiEnable_False,
            BME280I2C::I2CAddr_0x76 // 0x77 I2C address pour BME 280 Adafruit.
            );
    lesMesures.temperature = 0;
    lesMesures.humidite = 0;
    lesMesures.pression = 0;
    lesMesures.eclairement=0;
    leBme280 = new BME280I2C(settings);
    leBh1750 = new BH1750();

    leBh1750->begin();
    leBme280->begin();
}

Environnement::Environnement(const Environnement& orig) {
}

Environnement::~Environnement() {
    delete leBh1750;
    delete leBme280;
}

mesure Environnement::ObtenirMesures() {
    float temp(NAN), hum(NAN), pres(NAN), ecl(NAN);

    BME280::TempUnit tempUnit(BME280::TempUnit_Celsius);
    BME280::PresUnit presUnit(BME280::PresUnit_Pa);

    leBme280->read(pres, temp, hum, tempUnit, presUnit);

    lesMesures.temperature = temp;
    lesMesures.humidite = hum;
    lesMesures.pression = pres;
    lesMesures.eclairement = leBh1750->readLightLevel();
    


    return lesMesures;
}

