#include "LoadCel.hpp"

LoadCel::LoadCel(c_float dt, float wCut)
:_dt(dt)
,_wCut(wCut)
{
    _num        = 0;
    _voltage    = 0.0;
    _force[0]   = 0.0;
    _force[1]   = 0.0;

    _sCut       = 0.0;
    _a          = 0.0;
}

// float LoadCel::RCFilter(void)
// {
//     _sCut = 1.0/_wCut;
//     _a = (_sCut)/(_sCut + _dt);
//     _yOfRc[1] = _yOfRc[0];
//     _yOfRc[0] = (1.0 - _a)*_voltage + _a*_yOfRc[1];
//     return _yOfRc[0];
// }

float LoadCel::RCFilter(float old, float sta)
{
    _sCut = 1.0/_wCut;
    _a = (_sCut)/(_sCut + _dt);
    return (1.0 - _a)*sta + _a*old;
}

float LoadCel::ReadCurrentVoltage(void)
{
    _num = analogRead(PinForAnalogRead);
    _voltage = _num * (5.0 / 1023.0);
    // Serial.print(_voltage,3);Serial.print(",");
    return _voltage;
}

float LoadCel::ReadCurrentForce(void)
{
    ReadCurrentVoltage();
    // _voltage = RCFilter();
    _force[1] = _force[0];
    _force[0] = A * _voltage + B;
    // Serial.print(_force[0]);Serial.print(",");

    _force[0] = RCFilter(_force[1], _force[0]);
    return _force[0];
}
