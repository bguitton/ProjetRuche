#include "menu.h"

Menu::Menu()
{

}

void Menu::AfficherMenu()
{
    cout<<" configuer Syteme    1"<<endl;
    cout<<" configurer batterie 2 "<<endl;
    cout<<" configurer balance  3"<<endl;
}

void Menu::AfficherMenuSysteme()
{
    cout<<" changer le nom    1 "<<endl;
    cout<<" afficher configue 2 "<<endl;
    cout<<" retour            3 "<<endl;
}

void Menu::AfficherMenuBalance()
{
    cout<<"tarer 1"<<endl;
    cout<<"etalonner 2"<<endl;
    cout<<"peser 3"<<endl;
    cout<<"retour 4"<<endl;

}

void Menu::AfficherMenuBatterie()
{clearenv();
    cout<<"1 configuer capacité "<<endl;
    cout<<"2 retour "<<endl;

}
