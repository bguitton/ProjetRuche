/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.ino.cpp
 * Author: bguitton
 *
 * Created on 19 mars 2021, 09:31
 */

#include <cstdlib>
#include "HX711.h"
#include<Arduino.h>

#define TAILLEMAX 11

#include <soc/rtc.h>



using namespace std;

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 26;
const int LOADCELL_SCK_PIN = 25;


HX711 balance;

void setup() {
    Serial.begin(115200);
   rtc_clk_cpu_freq_set(RTC_CPU_FREQ_80M);
    balance.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN, 64);
    while (!Serial.available());
    while (Serial.available()) Serial.read();
    Serial.println("Initializing the scale");
    Serial.println("Appuyer sur une touche pour tarer : \t\t");
    while (!Serial.available());
    while (Serial.available()) Serial.read();
    balance.tare(); // reset the scale to 0


   
    Serial.println("Poser 5kg puis Appuyer sur une touche pour etalonner : \t\t");
    while (!Serial.available());
    while (Serial.available()) Serial.read();
    float scale = (balance.read_average(10) - balance.get_offset() )/ 5000;
    Serial.print("scale = " );
    Serial.println(scale);
    balance.set_scale(scale); // this value is obtained by calibrating the scale with known weights; see the README for details
    Serial.print("scale = " );
    Serial.println(balance.get_scale());
}

void loop() {
    Serial.print("one reading:\t");
    Serial.print(balance.get_units()/1000, 1);
    Serial.print("\t| average:\t");
    Serial.println(balance.get_units(10)/1000, 1);


    
    balance.power_down(); // put the ADC in sleep mode
    delay(250);
    balance.power_up();
}








//    float tab[TAILLEMAX];
//    float reserve;
//     for (int i = 0; i < TAILLEMAX; i++){
//         tab[i]=(balance.get_units(1));
//     }
//
//    for (int n = 0; n < TAILLEMAX; n++) {
//        for (int  p = 0; p < TAILLEMAX; p++) {
//            if (tab[n] < tab[p]) {
//                reserve = tab[n];
//                tab[n] = tab[p];
//                tab[p] = reserve;
//            }
//        }
//    }
//    Serial.print("Masse = " );
//    Serial.println(tab[5]/1000);