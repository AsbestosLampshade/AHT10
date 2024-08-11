#ifndef AHT10_H_INCLUDED
#define AHT_10_H
#include <Wire.h>
#define byte uint8_t
#define AHT10_ADDR 0x38

typedef struct {
  float humidity;
  float temperature;
}HumTemp_t;

class AHT10{
  public:
    void captureVal();
    HumTemp_t captured;
};
//HumTemp_t captureVal();

#endif
