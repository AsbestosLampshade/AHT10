#include <Wire.h>
#include "AHT10.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  Wire.begin();
  AHT10.captureVal();
  Serial.println(AHT10.captured.temperature);
  Serial.println(AHT10.captured.humidity);
}



void loop() {
  // put your main code here, to run repeatedly:

}
