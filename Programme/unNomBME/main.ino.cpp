#include<Arduino.h>
#include<Wire.h>
#include<BME280I2C.h>
#include <BH1750.h>
#include <HX711.h>

#define SERIAL_BAUD 115200

void printBME280Data(Stream *);

 
BME280I2C::Settings settings(
        BME280::OSR_X1,
        BME280::OSR_X1,
        BME280::OSR_X1,
        BME280::Mode_Forced,
        BME280::StandbyTime_1000ms,
        BME280::Filter_Off,
        BME280::SpiEnable_False,
        BME280I2C::I2CAddr_0x77 // 0x77 I2C address pour BME 280 Adafruit.
        );
BME280I2C bme(settings);
BH1750 eclairement;
HX711 balance;

void setup()
{
  Serial.begin(SERIAL_BAUD);

  while(!Serial) {} // Wait

  Wire.begin();
  eclairement.begin();

  balance.tare();


 while(!bme.begin())
  {
    Serial.println("Could not find BME280 sensor!");
    delay(1000);
  }

  switch(bme.chipModel())
  {
     case BME280::ChipModel_BME280:
       Serial.println("Found BME280 sensor! Success.");
       break;
     case BME280::ChipModel_BMP280:
       Serial.println("Found BMP280 sensor! No Humidity available.");
       break;
     default:
       Serial.println("Found UNKNOWN sensor! Error!");
  }
}
void loop()
{
   printBME280Data(&Serial);
   delay(500);
}
void printBME280Data
(
   Stream* client
)
{
   float temp(NAN), hum(NAN), pres(NAN),ecl(NAN),poi(NAN);

   BME280::TempUnit tempUnit(BME280::TempUnit_Celsius);
   BME280::PresUnit presUnit(BME280::PresUnit_Pa);

   bme.read(pres, temp, hum, tempUnit, presUnit);
   ecl=eclairement.readLightLevel();
   poi=balance.read();

   

   client->print("Temp: ");
   client->print(temp);
   client->print("°C");
   client->print("Humidity: ");
   client->print(hum);
   client->print("% RH");
   client->print("Pressure: ");
   client->print(pres);
   client->print("Pa");
   client->print("eclairement: ");
   client->print(ecl);
   client->println("lux");
   client->print("Poids: ");
   client->print(poi);
   client->println("Kg");

   delay(1000);
}


