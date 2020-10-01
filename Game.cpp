#include "Game.hpp"

Game::Game
(
    const uint8_t addr,
    c_float dt,
    c_float pGain, c_float iGain, c_float dGain
)
:_i2c(addr)
,_pid(dt, pGain, iGain, dGain)
,_motor(dt)
,_loadc(dt)
{
    _currentForce = 0.0;
    _calcForce    = 0.0;
}

void Game::Step(c_float reff)
{
    _currentForce = _loadc.ReadCurrentForce();
    _calcForce    = _motor.GetForceOfOL();
    _motor.SetVellocity(_motor.MakePalseFrom(reff - _calcForce));

    Serial.print("refF, curentF, palse = ");
    Serial.print(reff);Serial.print(", ");
    Serial.print(_currentForce);Serial.print(", ");
    Serial.println(_motor.MakePalseFrom(reff - _calcForce));
}
