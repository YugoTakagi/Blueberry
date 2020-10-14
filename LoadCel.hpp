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

    int   _num;
    float _voltage;
    float _force[2];

    float _sCut;
    float _a;

    float ReadCurrentVoltage(void);
    float RCFilter(float old, float sta);
public:
    LoadCel(c_float dt, float wCut);
    float ReadCurrentForce(void);
};

#endif
