#include <iostream>
#include "controleur.h"
using namespace std;

int main()
{

     Controleur unControleur;
     unControleur.leMenu->AfficherMenu();
     while (1) {
        unControleur.GestionMenu();
     }


    return 0;
}
