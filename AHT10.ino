#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  Wire.begin();
}


byte b[]={0xAC,0x33,0x00};
void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(0x38);
  Wire.write(b,3);
  Serial.print(Wire.endTransmission(true));
  Serial.println("@@@");
  delay(100);
  Wire.requestFrom(0x38,7,true);
  delay(100);
  Serial.println(Wire.available());
  Serial.println();

  unsigned long humidity=0;
  unsigned long temperature=0;

  byte i= Wire.read(); 
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
  Serial.println(temperature);
  
  float absHumidity=humidity;
  absHumidity=(absHumidity/1048576)*100;
  float absTemp=temperature;
  absTemp=((absTemp/1048576)*200)-50;
  Serial.println(absHumidity);
  Serial.println(absTemp);
}
