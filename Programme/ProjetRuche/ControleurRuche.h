/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
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
class ControleurRuche {
public:
    ControleurRuche();
    ControleurRuche(const ControleurRuche& orig);
    virtual ~ControleurRuche();
private:
    float temperature;
    float pression;
    float eclairement;
    float masse;
    float tension;
    float intensite;
    float tauxDeCharge;
    float charge;
    Balance *laBalance;
    Environnement *unEnvironement;
    
public:   
    
    void EnvoyerDonneesMesures();//float _humidite,float _pression,float _temperature,float _masse,float _eclairement
    void EnvoyerDonneesBatterie();
    void RecupererDonnees();
    void RecupererDonneesBatterie();
    void AfficherConfig();
    void ConfiguerNom();
    void CommandeSaisie();
    void Retour();
    void ConfiguerBatterie();
    void ConfigurerBalance();
    void AfficherMenu();
    void AfficherMenuBatterie();
    void AfficherMenuBalance();
    void AfficherMenuSysteme();
    void GestionMenu();
    void GestionMenuSysteme();
    void GestionMenuBatterie();
    void GestionMenuBalance();

    

};

#endif /* CONTROLEURRUCHE_H */

