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

HX711 scale;




void setup()
{
  Serial.begin(115200);
  
  Serial.print("LIBRARY VERSION: ");
  Serial.println(HX711_LIB_VERSION);
  Serial.println();
 
  scale.begin(26, 25);

  Serial.print("UNITS: ");
  Serial.println(scale.get_units(10));
  
  Serial.println("\nEmpty the scale, press a key to continue");
  while(!Serial.available());
  while(Serial.available()) Serial.read();
  
  scale.tare();
  Serial.print("UNITS: ");
  Serial.println(scale.get_units(10));
  
  Serial.println("\nPut a 400 g in the scale, press a key to continue");
  while(!Serial.available());
  while(Serial.available()) Serial.read();


  scale.callibrate_scale(400, 5);
  Serial.print("UNITS: ");
  Serial.println(scale.get_units(10));
  
  Serial.println("\nScale is callibrated, press a key to continue");
  while(!Serial.available());
  while(Serial.available()) Serial.read();
}

void loop()
{
 Serial.print("UNITS: ");
  Serial.println(scale.get_units(10));
  delay(250);
}

// END OF FILE