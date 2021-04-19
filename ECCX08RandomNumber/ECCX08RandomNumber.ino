/*
  ECCX08 Random Number

  This sketch uses the ECC508 or ECC608 to generate a random number 
  every second and print it to the Serial monitor

  Circuit:
   - MKR board with ECC508 or ECC608 on board

  created 19 July 2018
  by Sandeep Mistry
*/

#include <ArduinoECCX08.h>
#include <utility/ECCX08SelfSignedCert.h>
#include <utility/ECCX08DefaultTLSConfig.h>


void setup() {
  Serial.begin(9600);
  while (!Serial);

 if (!ECCX08.begin()) {
    Serial.println("No ECCX08 present!");
    while (1);
  }

  String serialNumber = ECCX08.serialNumber();

  if (!ECCX08.locked()) {
    Serial.println("The ECC508/ECC608 is not locked!");
    while (1);
  }

  String cert = ECCX08SelfSignedCert.endStorage();

  if (!cert) {
    Serial.println("Error generating self signed cert!");
    while (1);
  }

  Serial.println("Here's your self signed cert, enjoy!");
  Serial.println();
  Serial.println(cert);
  Serial.println();

  Serial.print("SHA1: ");
  Serial.println(ECCX08SelfSignedCert.sha1());
}

void loop() {
  Serial.print("Random number = ");
  Serial.println(ECCX08.random(65535));

  delay(1000);
}

