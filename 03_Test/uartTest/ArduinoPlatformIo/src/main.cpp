#include "pack.h"
#include <Arduino.h>
#include <MP_Serial.h>

using namespace EMP;

EMP::MP_Serial<packLinux2Ard, packArd2Linux, ArduinoMP_template(true)> mpSerial(Serial);

void setup() {
  // write your initialization code here
  pinMode(13,OUTPUT);
  mpSerial.begin(115200);
}

packArd2Linux pWrite {100, "Hi linux"};
packLinux2Ard pRead;

void loop() {
  //  mpSerial.updateState(); //

  pWrite.num = pRead.num * 2;
  mpSerial.packSend(&pWrite);

  //delay(1000);



  mpSerial.getData_wait(&pRead);

  //  Serial.print("Num = ");
  //  Serial.println(pRead.num);
  //  Serial.print("buf = ");
  //  Serial.println(pRead.buf);

  //delay(1000);


}