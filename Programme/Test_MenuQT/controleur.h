#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include "menu.h"
#include "batterie.h"
class Controleur
{
public:
    Controleur();
    Menu *leMenu;
    Batterie *laBatterie;
    void GestionMenu();
    void GestionMenuSyteme();
    void GestionMenuBalance();
    void GestionMenuBatterie();
};

#endif // CONTROLEUR_H
