#ifndef LOADCEL
#define LOADCEL

#include "Arduino.h"
#include <Wire.h> // For I2C.
#include "Define.hpp"

class LoadCel
{
private:
    float _dt;
    u_int _num;
    float _voltage;
public:
    LoadCel(c_float dt);
    float ReadCurrentForce(void);
};

#endif
