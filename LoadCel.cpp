#include "LoadCel.hpp"

LoadCel::LoadCel(c_float dt)
:_dt(dt)
{
    _num     = 0;
    _voltage = 0.0;
}

float LoadCel::ReadCurrentForce(void)
{
    _num = analogRead(PinForAnalogRead);
    Serial.print(analogRead(PinForAnalogRead));Serial.println(", ");
    _voltage = 5*(_num / 1023);
    return (_voltage - B) / A;
}
