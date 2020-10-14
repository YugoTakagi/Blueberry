#include "LoadCel.hpp"

LoadCel::LoadCel(c_float dt, float wCut)
:_dt(dt)
,_wCut(wCut)
{
    _num        = 0;
    _voltage    = 0.0;
    _force      = 0.0;

    _sCut       = 0.0;
    _a          = 0.0;
    _yOfRc[0]   = 0.0;
    _yOfRc[1]   = 0.0;
}

float LoadCel::RCFilter(void)
{
    _sCut = 1.0/_wCut;
    _a = (_sCut)/(_sCut + _dt);
    _yOfRc[1] = _yOfRc[0];
    _yOfRc[0] = (1.0 - _a)*_voltage + _a*_yOfRc[1];
    return _yOfRc[0];
}

float LoadCel::ReadCurrentVoltage(void)
{
    _num = analogRead(PinForAnalogRead);
    _voltage = 5.0*(_num / 1023.0);
    return _voltage;
}

float LoadCel::ReadCurrentForce(void)
{
    ReadCurrentVoltage();
    _voltage = RCFilter();
    _force = (_voltage - B)/(A);
    return _force;
}
