/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.ino.cpp
 * Author: bguitton
 *
 * Created on 22 mars 2021, 09:19
 */

#include <cstdlib>
#include<Arduino.h>
#include <soc/rtc.h>
#include <string.h>
#include <valarray>
#include "ControleurRuche.h"




using namespace std;


/*
 * 
 */

ControleurRuche *leControleur;
//Menu leMenu;

void setup() {

    Serial.begin(SERIAL_BAUD);
    Wire.begin();
    EEPROM.begin(EEPROM_SIZE);
    
    while (!Serial.available());
    while (Serial.available()) Serial.read();
    leControleur =new ControleurRuche();
}

void loop() {
    leControleur->RecupererDonnees();
     float choix = 0;
    leControleur->leMenu->AfficherMenu();

    while (Serial.available() == 0) {
    }
    choix = Serial.read();
    Serial.println(choix);
    leControleur->GestionMenu(choix);


    delay(1000);
}

