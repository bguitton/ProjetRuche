/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ControleurRuche.cpp
 * Author: bguitton
 * 
 * Created on 4 mai 2021, 09:40
 */

#include "ControleurRuche.h"

ControleurRuche::ControleurRuche() {
    unEnvironnement = new Environnement();
    laBalance = new Balance();




    laBalance->ConfiguerOffset(EEPROM.readDouble(0)); // lire le coef offset à l'adresse 0 et configuration de offset
    laBalance->ConfiguerScale(EEPROM.readDouble(10)); // lire le coef scale à l'adresse 10 et configuration de scale

}

ControleurRuche::ControleurRuche(const ControleurRuche& orig) {
}

ControleurRuche::~ControleurRuche() {
}

void ControleurRuche::EnvoyerDonneesMesures() {

}

void ControleurRuche::EnvoyerDonneesBatterie() {

}

void ControleurRuche::RecupererDonnees() {

    lesMesuresC = unEnvironnement->ObtenirMesures();
    masse = laBalance->Peser();
    Serial.print("Temp: ");
    Serial.print(lesMesuresC.temperature);
    Serial.print("°C\t");
    Serial.print("Humidity: ");
    Serial.print(lesMesuresC.humidite);
    Serial.print("% RH\t");
    Serial.print("Pressure: ");
    Serial.print(lesMesuresC.pression);
    Serial.print("Pa\t");
    Serial.print("eclairement: ");
    Serial.print(lesMesuresC.eclairement);
    Serial.println("lux\t");



}

void ControleurRuche::RecupererDonneesBatterie() {

}

void ControleurRuche::AfficherConfig() {

}

void ControleurRuche::ConfiguerNom() {

}

void ControleurRuche::CommandeSaisie() {

}

void ControleurRuche::Retour() {

}

void ControleurRuche::ConfiguerBatterie() {

}

void ControleurRuche::ConfigurerBalance() {

}

void ControleurRuche::GestionMenu() {

}

void ControleurRuche::GestionMenuSysteme() {

}

void ControleurRuche::GestionMenuBatterie() {

}

void ControleurRuche::GestionMenuBalance(int _reponse) {
    switch (_reponse) {
        case '1': // l'utilisateur à choisi l'option Tarer
            Serial.println("vider le plateau et appuyer sur une touche pour tarer ");
            while (!Serial.available());
            while (Serial.available()) Serial.read();
            laBalance.TarerLaBalance();
            // Serial.println(laBalance.ObtenirOffset()); affichage de coef offset
            Serial.println("tarage effectuer: \t\t");
            EEPROM.writeDouble(0, laBalance.ObtenirOffset()); // sauvegarder le coef offset à l'adresse 0
            EEPROM.commit();
            Serial.print("masse = ");
            Serial.println(laBalance.Peser());
            break;
        case '2': // l'utilisateur à choisi l'option Tarer
            if (laBalance.TarageEffectuer()) {
                Serial.println("Poser le poids étalon puis donnez sa valeur en gramme (ex:400g= 400) et appuyez sur entrer ");
                while (!Serial.available());

                while (Serial.available() == 0) {
                }
                poidEtalon = Serial.parseFloat();


                while (!Serial.available());
                while (Serial.available()) Serial.read();
                Serial.println(poidEtalon); // affiche 4 si l'ont tape 4
                laBalance.EtalonnerLaBalance(poidEtalon);
                Serial.println(laBalance.ObtenirScale());
                EEPROM.writeDouble(10, laBalance.ObtenirScale()); // sauvegarder le coef scale à l'adresse 10
                EEPROM.commit();
            } else {
                Serial.println("Vous devez tarer la balance avant de faire un etalonnage ");
            }
            break;
        case '3':
            Serial.print("masse = ");
            Serial.println(laBalance.Peser()); // appel de la fonction peser qui renvoi la masse mesurée

            break;
        case '4':
            Serial.print(" offset: ");
            Serial.println(laBalance.ObtenirOffset());
            Serial.print(" sclae: ");
            Serial.println(laBalance.ObtenirScale());
            break;
        default:
            Serial.println("Veuiller saisir un chiffre entre 1 et 3  ");
            break;
    }
}





