#include "Motor.hpp"

Motor::Motor(c_float dt)
:_dt(dt)
{
  // _mMove   = 0.0;
  // _xPps    = 0.0;
  // _pMpp    = 0.0;
  _pRef    = 0;
  _pInp    = 0;
  // _hz      = 0;
  _palse   = 0;
  // _dPalse  = 0;

  // _x = 0.0;
  // _forceOfOL = 0.0;
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
    noTone(PinForCcw);
  // tone(PinForCw, freq, MS);
    if (freq < 31)
    {
        this->Stop();
    }
    else
    {
        tone(PinForCw, freq);
    }  
}
void Motor::Ccw(const unsigned long freq) const
{
    noTone(PinForCw);
    // tone(PinForCcw, freq, MS);
    if (freq < 31)
    {
        this->Stop();
    }
    else
    {
        tone(PinForCcw, freq);
    }
}

long Motor::FilterVellocity(c_long freq) const
{
  if(abs(freq) > MAXVellocity)
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

// void Motor::miniTone(bool dir, const long freq)
// {
//   long t = 1000 / hz;
//   for
//   if(dir == true)
//   {
//     digitalWrite(PinForCw, HIGH);
//     delay(t/2);
//     digitalWrite(PinForCw, LOW);
//     delay(t/2);
//   }
//   else
//   {
//     digitalWrite(PinForCcw, HIGH);
//     delay(t/2);
//     digitalWrite(PinForCcw, LOW);
//     delay(t/2);
//   }
// }

long Motor::MakePalseFrom(c_float force)
{
  // 最小二乗法を用いた張力とパルスの関係式
  if(force >= 0) _pRef = (force)/(A_NP);
  else _pRef = (force)/(A_NPB);
  
  _pInp = (_pRef)/(_dt);
  _palse = FilterPalse((long) _pInp);

  return _palse;
}

// long Motor::MakePalseFrom(c_float force)
// {
//   // _mMove = (2.0*force)/(springConstant);//フックの法則 + 動滑車
//   _mMove = (4.0*force)/(springConstant);//フックの法則 + 動滑車
//   // Serial.print("_mMove = ");Serial.println(_mMove,6);
//   _xPps = (pulleyDiameter*M_PI)/(gearRate*motorResolution);
//   // Serial.print("_xPps = ");Serial.println(_xPps,8);
//   _pMpp = _mMove / _xPps;
//   // Serial.print("_pMpp = ");Serial.println(_pMpp,6);
//   float floatHz = _pMpp / _dt;
//   _hz = (long) floatHz;

//   // Serial.print("_hz = ");Serial.println(_hz);

//   _palse = FilterPalse(_hz);
//   _dPalse = Make20msPalse(_palse);
//   MakeX(_dPalse);
//   return _palse;
// }

long Motor::FilterPalse(long palse)
{
  if (MAXVellocity < abs(palse))
  {
    if (palse < 0) return -1 * MAXVellocity;
    else return MAXVellocity;
  }
  else return palse;
}

// long Motor::Make20msPalse(long palse)
// {
//   return palse * _dt;
// }

// void Motor::MakeX(long dPalse)
// {
//   _x += ( ((pulleyDiameter*M_PI) / (gearRate*motorResolution)) * dPalse ) / 2;// 動滑車
// }

// float Motor::GetForceOfOL()
// {
//   _forceOfOL = springConstant * _x;
//   return _forceOfOL;
// }
