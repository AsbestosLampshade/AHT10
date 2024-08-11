#include <Wire.h>
#include "AHT10.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  Wire.begin();
  AHT10 sample;
  sample.captureVal();
  Serial.println(sample.captured.temperature);
  Serial.println(sample.captured.humidity);
}



void loop() {
  // put your main code here, to run repeatedly:

}
