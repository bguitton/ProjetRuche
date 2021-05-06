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

ControleurRuche leControleur;

void setup() {

    Serial.begin(SERIAL_BAUD);
    Wire.begin();
    while (!Serial.available());
    while (Serial.available()) Serial.read();
    
}

void loop() {
    leControleur.RecupererDonnees();
  
    
    delay(500);
}


