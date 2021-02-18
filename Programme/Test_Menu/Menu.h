/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.h
 * Author: bguitton
 *
 * Created on 18 février 2021, 16:41
 */

#ifndef MENU_H
#define MENU_H

class Menu {
public:
    Menu();
    Menu(const Menu& orig);
    virtual ~Menu();
    void AfficherMenu();
    void AfficherMenuSysteme();
    void AfficherMenuBalance();
    void AfficherMenuBatterie();
    
private:

};

#endif /* MENU_H */

