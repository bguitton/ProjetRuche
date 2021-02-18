/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controleur.h
 * Author: bguitton
 *
 * Created on 18 février 2021, 16:41
 */

#ifndef CONTROLEUR_H
#define CONTROLEUR_H
#include "Menu.h"

class Controleur {
public:
    Controleur();
    Controleur(const Controleur& orig);
    virtual ~Controleur();
    
private:
    Menu leMenu;

};

#endif /* CONTROLEUR_H */

