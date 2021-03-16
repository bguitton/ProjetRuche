#include<Arduino.h>
#include<Wire.h>
#include <HX711.h>
//
//
//
//#define SERIAL_BAUD 115200
//
//void printBME280Data(Stream *);
//
//HX711 balance;
//uint8_t dataPin = 6;
//uint8_t clockPin = 7;
//float w1, w2, previous = 0;
//
//void setup()
//{
//  Serial.begin(SERIAL_BAUD);
//
//  while(!Serial) {} // Wait
//
//  
//  balance.begin(dataPin, clockPin);
//
//  Serial.print("UNITS: ");
//  Serial.println(balance.get_units(10));
//
//  // loadcell factor 20 KG
//  // scale.set_scale(127.15);
//  // loadcell factor 5 KG
//  balance.set_scale(420.0983);
//  balance.tare();
//
//  Serial.print("UNITS: ");
//  Serial.println(balance.get_units(10));
//  
//}
//void loop()
//{
//   printBME280Data(&Serial);
//   delay(500);
//}
//void printBME280Data
//(
//   Stream* client
//)
//{
//   float poi(NAN);
//
// 
//  Serial.print(balance.get_units(5));
//   
//   poi=balance.read();
//
//   
//   client->print("Poids: ");
//   client->print(poi);
//   client->println("Kg");
//
//   delay(1000);
//}
//
//
HX711 scale;

uint8_t dataPin = 6;
uint8_t clockPin = 7;


void setup()
{
    
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("LIBRARY VERSION: ");
  Serial.println(HX711_LIB_VERSION);
  Serial.println();
  Wire.begin();

  scale.begin(dataPin, clockPin);

  Serial.print("UNITS: ");
  Serial.println(scale.get_units(10));
  
  Serial.println("\nEmpty the scale, press a key to continue");
  while(!Serial.available());
  while(Serial.available()) Serial.read();
  
  scale.tare();
  Serial.print("UNITS: ");
  Serial.println(scale.get_units(10));


  Serial.println("\nPut a 1 kg in the scale, press a key to continue");
  while(!Serial.available());
  while(Serial.available()) Serial.read();

  scale.callibrate_scale(1000, 5);
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
  delay(2000);
}
