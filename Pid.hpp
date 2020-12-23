#ifndef PID
#define PID

#include "Arduino.h"
#include <Wire.h> // For I2C.
#include "Define.hpp"

class Pid
{
private:
    c_float _dt;

    /* For pid fb */
    c_float _pGain;
    c_float _iGain;
    c_float _dGain;
    float   _adjustment;
    float   _diff[2];
    float   _integral;
public:
    Pid
    (
        c_float dt, 
        c_float pGain, c_float iGain, c_float dGain
    );
    float MakeAdjustment(c_float referenceForce ,c_float currentForce);
};

#endif
