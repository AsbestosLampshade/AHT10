#include "AHT10.h"

byte b[]={0xAC,0x33,0x00};

HumTem captureVal(){
  unsigned long humidity=0;
  unsigned long temperature=0;
  HumTem out;
  //Request Data
  Wire.beginTransmission(0x38);
  Wire.write(b,3);
  Wire.endTransmission(true);
  //delay(100);
  Wire.requestFrom(0x38,7,true);

  //Capture Data
  byte i= Wire.read();// State Value, can ignore

  i= Wire.read();
  humidity=((humidity|i)<<8);
  i= Wire.read();
  humidity=((humidity|i)<<4);
  i= Wire.read();
  humidity=((humidity|(i>>4)));
  temperature=((temperature|(i&0x0F))<<8);
  i= Wire.read();
  temperature=((temperature|i)<<8);
  i= Wire.read();
  temperature=((temperature|i));

  //Convert Data
  out.humidity=humidity;
  out.humidity=(out.humidity/1048576)*100;
  out.temperature=temperature;
  out.temperature=((out.temperature/1048576)*200)-50;
  // Serial.println(out.humidity);
  // Serial.println(out.temperature);
  return out;
}