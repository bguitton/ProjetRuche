//
//    FILE: HX_kitchen_scale.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
// PURPOSE: HX711 demo
//     URL: https://github.com/RobTillaart/HX711
//
// HISTORY:
// 0.1.0    2020-06-16 initial version
//

#include<Arduino.h>
#include <HX711.h>
//#define TAILLEMAX 11

HX711 scale;




void setup()
{
  Serial.begin(115200);
  
  Serial.print("LIBRARY VERSION: ");
  Serial.println(HX711_LIB_VERSION);
  Serial.println();
 
  scale.begin(26,25);

  Serial.print("UNITS: ");
  Serial.println(scale.get_units(10));
  scale.set_gain(64);
  Serial.println("\nEmpty the scale, press a key to continue");
  while(!Serial.available());
  while(Serial.available()) Serial.read();
  
  scale.tare();
  Serial.print("UNITS: ");
  Serial.println(scale.get_units(10));
  
  Serial.println("\nPut a 5kg in the scale, press a key to continue");
  while(!Serial.available());
  while(Serial.available()) Serial.read();


  scale.callibrate_scale(5000,5);
  Serial.print("UNITS: ");
  Serial.println(scale.get_units(10));
  
  Serial.println("\nScale is callibrated, press a key to continue");
  while(!Serial.available());
  while(Serial.available()) Serial.read();
}

void loop()
{
 Serial.print("UNITS: ");
  Serial.println(scale.read());
  delay(2000);
}

// END OF FILE
//
//    short tab[TAILLEMAX]={12,10,15,0,19,35,45,15,20,5,6};
//    short reserve;
//
//    for (int n = 0; n < TAILLEMAX; n++) {
//        for (int  p = 0; p < TAILLEMAX; p++) {
//            if (tab[n] < tab[p]) {
//                reserve = tab[n];
//                tab[n] = tab[p];
//                tab[p] = reserve;
//            }
//        }
//    }
//
//    for(int n=0;n<TAILLEMAX;n++){
//        cout<<tab[n]<<" ";
//    }
//    cout<<endl;