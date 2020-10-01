#include "Motor.hpp"

Motor::Motor(c_float dt)
:_dt(dt)
{
  _mMove   = 0.0;
  _xPps    = 0.0;
  _pMpp    = 0.0;
  _hz      = 0;
  _palse   = 0;
  _dPalse = 0;

  _x = 0.0;
  _forceOfOL = 0.0;
}
void Motor::SetVellocity(c_long freq) const
{
  if(freq > 0){
    Cw(FilterVellocity(freq));
  }
  else{
    Ccw(FilterVellocity(freq)*-1);
  }
}
void Motor::Cw(const unsigned long freq) const
{
//  noTone(PinForCw); noTone(PinForCcw);
  tone(PinForCw, freq);
}
void Motor::Ccw(const unsigned long freq) const
{
// noTone(PinForCw); noTone(PinForCcw);
  tone(PinForCcw, freq);
}

long Motor::FilterVellocity(c_long freq) const
{
  if(labs(freq) > MAXVellocity)
  {
    if(freq > 0) return MAXVellocity;
    else return -1* MAXVellocity;
  }
  else
  {
    return freq;
  }
}
void Motor::Stop(void) const
{
  noTone(PinForCw);
  noTone(PinForCcw);
}

long Motor::MakePalseFrom(c_float force)
{
  _mMove = force / springConstant;
  _xPps = (pulleyDiameter*M_PI) / (gearRate*motorResolution);
  _pMpp = _mMove / _xPps;
  float floatHz = _pMpp / _dt;
  _hz = (long) floatHz;

  _palse = FilterPalse(_hz);
  _dPalse = Make20msPalse(_palse);
  MakeX(_dPalse);
  return _palse;
}

long Motor::FilterPalse(long palse)
{
  if (MAXVellocity < abs(palse))
  {
    if (palse < 0) return -1 * MAXVellocity;
    else return MAXVellocity;
  }
  else return palse;
}

long Motor::Make20msPalse(long palse)
{
  return palse * _dt;
}

void Motor::MakeX(long dPalse)
{
  _x += ( ((pulleyDiameter*M_PI) / (gearRate*motorResolution)) * dPalse ) / 2;// 動滑車
}

float Motor::GetForceOfOL()
{
  _forceOfOL = springConstant * _x;
  return _forceOfOL;
}