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

// Wireライブラリを拡張し, I2C通信(送受信)をfloat(4byte)の単位でおこないます.
// Example:
//      I2c xxx(addr); /* addrはi2cアドレス */
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
