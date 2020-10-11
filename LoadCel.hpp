#ifndef LOADCEL
#define LOADCEL

#include <Arduino.h>
#include <Wire.h> // For I2C.
#include "Define.hpp"

class LoadCel
{
private:
    float _dt;
    float _wCut;

    long _num;
    float _voltage;
    float _force;

    float _sCut;
    float _a;
    float _yOfRc[2];

    float ReadCurrentVoltage(void);
    float RCFilter(void);
public:
    LoadCel(c_float dt, float wCut);
    float ReadCurrentForce(void);
};

#endif
