#ifndef I2C
#define I2C

#include "Arduino.h"
#include <Wire.h> // For I2C.
#include "Define.hpp"

union Packet
{
    float data;
    char  bytes[4 * 1];
};

class I2c
{
private:
    Packet dataPack;
public:
    I2c(const uint8_t addr);
    float Read(void);
    void  Write(c_float data);
};

#endif
