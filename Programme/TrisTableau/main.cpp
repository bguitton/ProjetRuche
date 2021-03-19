#include <iostream>
#define TAILLEMAX 11
using namespace std;



int main()
{
    short tab[TAILLEMAX]={12,10,15,0,19,35,45,15,20,5,6};
    short reserve;

    for (int n = 0; n < TAILLEMAX; n++) {
        for (int  p = 0; p < TAILLEMAX; p++) {
            if (tab[n] < tab[p]) {
                reserve = tab[n];
                tab[n] = tab[p];
                tab[p] = reserve;
            }
        }
    }

    for(int n=0;n<TAILLEMAX;n++){
        cout<<tab[n]<<" ";
    }
    cout<<endl;
}
