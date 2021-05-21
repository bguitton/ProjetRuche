#include <iostream>
#include <cstdio>
using namespace std;


struct trameMesure{
    short temperature;
    unsigned char humidite;
    unsigned short masse;
    unsigned short eclairement;
    unsigned short pression;
    short pointDeRosee;
    char typeTrame=1;
};

struct mesure {
    float temperature;
    float humidite;
    float pression;
    float eclairement;
};


int main()
{
   mesure lesMesures;
   trameMesure laTrameMesures;

   lesMesures.temperature=35.46;
   lesMesures.humidite=49.0;
   lesMesures.eclairement=44898;
   lesMesures.pression=10132;


   laTrameMesures.temperature=short(lesMesures.temperature*100);
   laTrameMesures.humidite=lesMesures.humidite;





    cout << "temperature :"<<laTrameMesures.temperature << endl;
    cout << "temperature :"<<laTrameMesures.humidite << endl;
    return 0;
}
