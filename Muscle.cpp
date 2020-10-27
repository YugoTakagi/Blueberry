#include "Muscle.hpp"

Muscle::Muscle
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

    _palse        = 0;
}

void Muscle::StepResponse(c_float reff)
{
    // 初期テンション
    _currentForce = _loadc->ReadCurrentForce();
    while(_currentForce <= 20.0) _currentForce = this->OutOnePalse();
    _motor->Stop(); delay(1000);

    while(_currentForce <= reff)
    {
        // オープンループのステップ応答
        _calcForce = _motor->GetForceOfOL();
        _currentForce = _loadc->ReadCurrentForce();
        _palse = _motor->MakePalseFrom(reff - _calcForce);
        _motor->SetVellocity(_palse);
        delay(DT);

        // PID
        // _motor->SetVellocity(_motor->MakePalseFrom(_pid->MakeAdjustment(reff, _currentForce)));

        // plot : 目標値, 今の値, 入れたパルス
        Serial.print(reff);Serial.print(", ");Serial.print(_currentForce);Serial.print(", ");Serial.println(_palse);
    }
    _motor->Stop(); delay(1000);
}

float Muscle::OutOnePalse()
{
    _currentForce = _loadc->ReadCurrentForce();

    // 位置パルスを出力
    _motor->SetVellocity(50);
    Serial.print(_currentForce);Serial.println();
    return _currentForce;
}

// 20 [N]加えてから, N [N]のステップ関数を出力します.
void Muscle::Debug_init20N_to_Step(const float N)
{
    // 20 [N]を加える(ワイヤのたるみ防止)
    _currentForce = _loadc->ReadCurrentForce();
    while(_currentForce <= 20.0) _currentForce = this->OutOnePalse();
    _motor->Stop();

    // x [s]停止
    int deleyTime = 5;//[s] たるんでいたら5sはやめよう.
    for(int i=0; i < deleyTime*50; i++)
    {
        Serial.println(_loadc->ReadCurrentForce());
        delay(20);
    }

    // N [N]のステップ関数を加える
    _palse = _motor->MakePalseFrom(N);
    _motor->SetVellocity(_palse);
}
