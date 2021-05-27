#include "Sigfox.h"
#include "Arduino.h"


typedef struct {
  int16_t temp;
  unsigned char compteur;
  unsigned char humidite;
} trame;

Sigfox mySigfox(27, 26, true);
int16_t temperature;

void setup() {
  Serial.begin(9600);
  Serial.println("Sigfox");
  mySigfox.begin();
  trame t;
  
  t.temp = mySigfox.obtenirTemp();
  t.compteur = 1;
  t.humidite = 50;
  delay(1000);
  Serial.println(mySigfox.obtenirPAC());
  Serial.println(mySigfox.obtenirID());
  bool statusSig = mySigfox.envoyer(&t, sizeof(t));

}

void loop() {
  // put your main code here, to run repeatedly:

}
