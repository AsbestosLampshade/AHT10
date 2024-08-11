#include "AHT10.h"

void AHT10_t::captureVal(){
  unsigned long humidity=0;
  unsigned long temperature=0;
  HumTemp_t out;
  //Request Data from AHT10
  Wire.beginTransmission(AHT10_ADDR);
  Wire.write(0xAC);
  Wire.write(0x33);
  Wire.write(0x00);
  Wire.endTransmission(true);
  Wire.requestFrom(AHT10_ADDR,7,true);

  //Capture Data
  byte inData= Wire.read();// State Value, can ignore

  inData= Wire.read();
  humidity=((humidity|inData)<<8);
  inData= Wire.read();
  humidity=((humidity|inData)<<4);
  inData= Wire.read();
  humidity=((humidity|(inData>>4)));
  temperature=((temperature|(inData&0x0F))<<8);
  inData= Wire.read();
  temperature=((temperature|inData)<<8);
  inData= Wire.read();
  temperature=((temperature|inData));

  //Convert Data
  captured.humidity=((double)humidity/1048576)*100;
  captured.temperature=(((double)temperature/1048576)*200)-50;
}

AHT10_t AHT10;
