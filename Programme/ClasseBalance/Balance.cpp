/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Balance.cpp
 * Author: bguitton
 * 
 * Created on 22 mars 2021, 09:20
 */

#include "Balance.h"
#define TAILLEMAX 11

Balance::Balance(int dout, int sck, int gain) {
    tarage=false;
    
    leHX711=new HX711();
    
   
    leHX711->begin(dout, sck, gain);
    
    
    
}

Balance::Balance(const Balance& orig) {
}

Balance::~Balance() {
    delete leHX711;
}


float Balance::Peser() {
     

    float tab[TAILLEMAX];
    float reserve;
     for (int i = 0; i < TAILLEMAX; i++){
         tab[i]=(leHX711->get_units(1));
     }

    for (int n = 0; n < TAILLEMAX; n++) {
        for (int  p = 0; p < TAILLEMAX; p++) {
            if (tab[n] < tab[p]) {
                reserve = tab[n];
                tab[n] = tab[p];
                tab[p] = reserve;
            }
        }
    }
    
    return tab[5]/1000;
   
    
    
}


void Balance::TarerLaBalance() {
    
   
    leHX711->tare();
    tarage=true;
    scale=leHX711->get_scale();
    
    
}

float Balance::EtalonnerLaBalance() {
  
    
    float scale = (leHX711->read_average(10) - leHX711->get_offset() )/ 5000;
    
    leHX711->set_scale(scale);
    offset=leHX711->get_offset();
    return leHX711->get_offset();
}

bool Balance::TarageEffectuer(){
    return tarage;
}