#include "Game.hpp"

Game::Game
(
    I2c*     i2c,
    Pid*     pid,
    Motor*   motor,
    LoadCel* loadc
)
:_i2c(i2c)
,_pid(pid)
,_motor(motor)
,_loadc(loadc)
{
    _currentForce = 0.0;
    _calcForce    = 0.0;
}

void Game::Step(c_float reff)
{
    _currentForce = _loadc->ReadCurrentForce();
    Serial.print("_currentForce = ");Serial.println(_currentForce);
    _calcForce    = _motor->GetForceOfOL();
    _motor->SetVellocity(_motor->MakePalseFrom(reff - _calcForce));

    Serial.print("refF, curentF, palse = ");
    Serial.print(reff);Serial.print(", ");
    Serial.print(_currentForce);Serial.print(", ");
    Serial.println(_motor->MakePalseFrom(reff - _calcForce));
}
