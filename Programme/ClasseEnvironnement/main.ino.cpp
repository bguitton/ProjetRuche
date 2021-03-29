/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Environnement.h
 * Author: bguitton
 *
 * Created on 26 mars 2021, 11:14
 */

#include<Arduino.h>
#include<Wire.h>
#include "Environnement.h"

#define SERIAL_BAUD 115200
Environnement unEnvironnement;

void setup() {

    Serial.begin(SERIAL_BAUD);

    Wire.begin();
    Serial.println("Fonction setup");
}

void loop() {
    mesure lesMesures;
    lesMesures = unEnvironnement.ObtenirMesures();

    Serial.print("Temp: ");
    Serial.print(lesMesures.temperature);
    Serial.print("°C\t");
    Serial.print("Humidity: ");
    Serial.print(lesMesures.humidite);
    Serial.print("% RH\t");
    Serial.print("Pressure: ");
    Serial.print(lesMesures.pression);
    Serial.print("Pa\t");
    Serial.print("eclairement: ");
    Serial.print(lesMesures.eclairement);
    Serial.println("lux\t");
    delay(1000);
}




