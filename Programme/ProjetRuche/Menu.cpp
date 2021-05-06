/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.cpp
 * Author: bguitton
 * 
 * Created on 6 mai 2021, 16:58
 */

#include "Menu.h"

Menu::Menu() {
}

Menu::Menu(const Menu& orig) {
}

Menu::~Menu() {
}

void Menu::AfficherMenu() {

}

void Menu::AfficherMenuBatterie() {

}

void Menu::AfficherMenuBalance() {
    
    Serial.println("1 - pour Tarer ");

    Serial.println("2 - pour Etalonner ");

    Serial.println("3 - pour Peser ");

}

void Menu::AfficherMenuSysteme() {

}