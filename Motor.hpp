#ifndef MOTOR
#define MOTOR

#include "Arduino.h"
#include <Wire.h> // For I2C.
#include "Define.hpp"

class Motor
{
private:
    c_float _dt;
    long FilterVellocity(c_long freq) const;
    // long MakePalseFrom(c_float force);
    long FilterPalse(long palse);
    long Make20msPalse(long palse);
    void MakeX(long palseDt);

    float _x;
    float _forceOfOL;

    float _mMove;
    float _xPps;
    float _pMpp;
    long  _hz;
    long  _palse;
    long  _dPalse;
public:
    Motor(c_float dt);
    void Stop(void) const;
    void Cw(const unsigned long freq) const;
    void Ccw(const unsigned long freq) const;

    void SetVellocity(c_long freq) const;
    float GetForceOfOL(void);
    long MakePalseFrom(c_float force);
};

#endif
