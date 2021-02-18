#include "controleur.h"

Controleur::Controleur()
{
    leMenu=new Menu();
    laBatterie=new Batterie();


}

void Controleur::GestionMenu()
{
    int commande=0;
    while(commande != 1 && commande != 2 && commande != 3){
    cin>>commande;
    }
    switch (commande) {
    case 1:

        leMenu->AfficherMenuSysteme();
        GestionMenuSyteme();
        break;
    case 2:
        leMenu->AfficherMenuBatterie();
        GestionMenuBatterie();
        break;
    case 3:
        leMenu->AfficherMenuBalance();

        GestionMenuBalance();
        break;

    }
}

void Controleur::GestionMenuSyteme()
{
    int commande=0;
    while(commande != 1 && commande != 2 && commande != 3){
    cin>>commande;
    }
    switch (commande) {
    case 1:

        cout<<"Configuer nom"<<endl;

        break;
    case 2:
        cout<<"Afficher information"<<endl;
        cout<<"la capacité est de :"<<laBatterie->capacite<<endl;
        break;
    case 3:
        leMenu->AfficherMenu();
        GestionMenu();
        break;

    }
}

void Controleur::GestionMenuBalance()
{
    int commande=0;
    while(commande != 1 && commande != 2 && commande != 3){
    cin>>commande;
    }
    switch (commande) {
    case 1:

        cout<<"Tarer"<<endl;


        break;
    case 2:
        leMenu->AfficherMenuBatterie();

        break;
    case 3:
        leMenu->AfficherMenuBalance();

        break;

    }
}

void Controleur::GestionMenuBatterie()
{
    int commande=0;
    float lacapacite;
    while(commande != 1 && commande != 2){
    cin>>commande;
    }
    switch (commande) {
    case 1:

        cout<<"Changement de la capaciter"<<endl;
        cin>>lacapacite;
        laBatterie->capacite=lacapacite;
        leMenu->AfficherMenu();
        GestionMenu();

        break;
    case 2:
        leMenu->AfficherMenu();
        GestionMenu();
        break;


    }
}
