/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 /

/ 
 * File:   ControleurRuche.h
 * Author: bguitton
 *
 * Created on 4 mai 2021, 09:40
 */

#ifndef CONTROLEURRUCHE_H
#define CONTROLEURRUCHE_H
#include "Balance.h"
#include "Environnement.h"
#include "constante.h"
//#include "Menu.h"


//struct mesure{
//    float temperature;
//    float humidite;
//    float pression;
//    float eclairement;
//};


class ControleurRuche {
public:
    ControleurRuche();
    ControleurRuche(const ControleurRuche& orig);
    virtual ~ControleurRuche();

    void EnvoyerDonneesMesures();
    void EnvoyerDonneesBatterie();
    void RecupererDonnees();
    void RecupererDonneesBatterie();
    void AfficherConfig();
    void ConfiguerNom();
    void CommandeSaisie();
    void Retour();
    void ConfiguerBatterie();
    void ConfigurerBalance(); 
    void GestionMenu(int _choix);
    void GestionMenuSysteme(int _choix);
    void GestionMenuBatterie(int _choix);
    void GestionMenuBalance(int _choix);

    // Menu *leMenu;
 

private:
    mesure lesMesuresC;
    float masse;
    float tension;
    float intensite;
    float tauxDeCharge;
    float charge;
    Balance *laBalance;
    Environnement *unEnvironnement;

};