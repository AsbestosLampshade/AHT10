#include "AHT10.h"

byte b[]={0xAC,0x33,0x00};

void AHT10_t::captureVal(){
  unsigned long humidity=0;
  unsigned long temperature=0;
  HumTemp_t out;
  //Request Data from AHT10
  Wire.beginTransmission(AHT10_ADDR);
  Wire.write(b,3);
  Wire.endTransmission(true);
  Wire.requestFrom(AHT10_ADDR,7,true);

  //Capture Data
  byte inData= Wire.read();// State Value, can ignore
  Serial.println(inData);
  inData= Wire.read();
  Serial.println(inData);
  humidity=((humidity|inData)<<8);
  inData= Wire.read();
  Serial.println(inData);
  humidity=((humidity|inData)<<4);
  inData= Wire.read();
  Serial.println(inData);
  humidity=((humidity|(inData>>4)));
  temperature=((temperature|(inData&0x0F))<<8);
  inData= Wire.read();
  Serial.println(inData);
  temperature=((temperature|inData)<<8);
  inData= Wire.read();
  Serial.println(inData);
  temperature=((temperature|inData));

  //Convert Data
  //out.humidity=humidity;
  captured.humidity=((double)humidity/1048576)*100;
  //out.temperature=temperature;
  captured.temperature=(((double)temperature/1048576)*200)-50;
}

AHT10_t AHT10;