#include "Pid.hpp"

Pid::Pid(c_float dt, c_float pGain, c_float iGain, c_float dGain)
:_dt(dt)
,_pGain(pGain)
,_iGain(iGain)
,_dGain(dGain)
{
  _adjustment = 0.0;
  _integral   = 0.0;
  _diff[0]    = 0.0;
  _diff[1]    = 0.0;
}

float Pid::MakeAdjustment(c_float referenceForce ,c_float currentForce)
{
  _diff[0] = _diff[1];
  _diff[1] = referenceForce - currentForce;

  /* ----- e を見たい ----- */

  // Serial.print(_diff[1]);Serial.print(",");

  /* ----- /e を見たい ---- */ 

  _integral += ((_diff[1] + _diff[0]) / 2) *_dt;
  _adjustment = (_pGain*_diff[1]) + (_iGain*_integral) + (_dGain*(_diff[1] - _diff[0]) / _dt);

  /* ----- y を見たい ----- */

  // Serial.print(_adjustment);Serial.print(",");

  /* ----- /y を見たい ---- */ 

  return _adjustment;
}