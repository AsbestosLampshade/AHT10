#include <Wire.h>
#ifndef AHT10_H_INCLUDED
#define AHT_10_H_INCLUDED
#define byte uint8_t
#define addr 0x38

struct HumTem{
  float humidity;
  float temperature;
};

typedef struct HumTem HumTem;

HumTem captureVal();

#endif
