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
#include "Balance.h"
#include <soc/rtc.h>

using namespace std;

const int LOADCELL_DOUT_PIN = 26;
const int LOADCELL_SCK_PIN = 25;
/*
 * 
 */

Balance laBalance;

void setup() {

    rtc_clk_cpu_freq_set(RTC_CPU_FREQ_80M);
    Serial.begin(115200);
    Serial.println("Fonction setup");

    while (!Serial.available());
    while (Serial.available()) Serial.read();

}

void loop() {

    int reponse = 0;
    Serial.println("1 - pour Tarer ");
    Serial.println("2 - pour Etalonner ");
    Serial.println("3 - pour Peser ");
    while (!Serial.available());


    reponse = Serial.read();
    // Serial.println(reponse);
    if (reponse == '1' || reponse == '2' || reponse == '3') {
        switch (reponse) {
            case '1':
                Serial.println("vider le plateau et appuyer sur une touche pour tarer ");
                while (!Serial.available());
                while (Serial.available()) Serial.read();
                laBalance.TarerLaBalance();
                Serial.println("tarage effectuer: \t\t");
                break;
            case '2':
                Serial.println("Poser 5 kg et appuyer sur une touche pour etalonner ");
                while (!Serial.available());
                while (Serial.available()) Serial.read();
                laBalance.EtalonnerLaBalance();
                break;
            case '3':
                Serial.print("masse = ");
                Serial.println(laBalance.Peser());
                break;
        }
    } else {
        Serial.println("Veuiller saisir un chiffre entre 1 et 3  ");
    }
    delay(500);
}


