#ifndef AHT10_H_INCLUDED
#define AHT_10_H_INCLUDED
#include <Wire.h>

#define byte uint8_t
#define AHT10_ADDR 0x38

struct HumTem{
  float humidity;
  float temperature;
}HumTem;

HumTem captureVal();

#endif
