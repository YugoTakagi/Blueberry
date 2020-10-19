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

void Game::StepResponse(c_float reff)
{
    // 初期テンション
    _currentForce = _loadc->ReadCurrentForce();
    while(_currentForce <= 20.0) _currentForce = this->Go();
    _motor->Stop(); delay(1000);

    while(_currentForce <= reff)
    {
        // オープンループのステップ応答
        _calcForce = _motor->GetForceOfOL();
        _currentForce = _loadc->ReadCurrentForce();
        _motor->SetVellocity(_motor->MakePalseFrom(reff - _calcForce));
        delay(DT);

        // PID
        // _motor->SetVellocity(_motor->MakePalseFrom(_pid->MakeAdjustment(reff, _currentForce)));

        // plot : 目標値, 今の値, パルス
        Serial.print(reff);Serial.print(", ");Serial.print(_currentForce);Serial.print(", ");Serial.println(_motor->MakePalseFrom(reff - _calcForce));
    }
}

float Game::Go()
{
    _currentForce = _loadc->ReadCurrentForce();

    _motor->SetVellocity(50);
    Serial.print(_currentForce);Serial.println();
    return _currentForce;
}

void Game::TestLoadCel()
{
    _currentForce = _loadc->ReadCurrentForce();
    // Serial.print("_currentForce = ");
    Serial.println(_currentForce);
}