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

    // ONEパルスを出力
    _motor->SetVellocity(50);
    delay(20);
    _motor->Stop();
    Serial.print(_currentForce);Serial.println();
    return _currentForce;
}

float Muscle::OutOnePalse_ccw()
{
    _currentForce = _loadc->ReadCurrentForce();

    // ONEパルスを出力
    _motor->SetVellocity(-50);
    delay(20);
    _motor->Stop();
    Serial.print(_currentForce);Serial.println();
    return _currentForce;
}

// 50 [N]加えてから, N [N]のステップ関数を出力します.
void Muscle::Debug_init50N_to_Step(const float N)
{
    // 50 [N]を加える(ワイヤのたるみ防止)
    _currentForce = _loadc->ReadCurrentForce();
    while(_currentForce <= 50.0) _currentForce = this->OutOnePalse();
    // while(_currentForce <= 20.0) _currentForce = this->OutOnePalse();
    _motor->Stop();

    // x [s]停止
    int deleyTime = 2;//[s] たるんできたら2sはやめよう.
    for(int i=0; i < deleyTime*50; i++)
    {
        Serial.println(_loadc->ReadCurrentForce());
        delay(20);
    }

    Serial.println("x");
    // N [N]のステップ関数を加える
    _palse = _motor->MakePalseFrom(N);
    _motor->SetVellocity(_palse);
    // Serial.print("palse, ");Serial.println(_palse);

    // _motor->SetVellocity(33757);// 30 [N]
    // _motor->SetVellocity(32911);// 40 [N] 49034
    // _motor->SetVellocity(45010);// 40 [N]
    // _motor->SetVellocity(56263);// 50 [N] 46476
    // _motor->SetVellocity(60041);// 60 [N]
    // Serial.println(_palse);
    delay(20);
    _motor->Stop();
}

// x [N]加えてから, N [N]のステップ関数を出力します(With PID).
void Muscle::Debug_init50N_to_Step_With_PID(const float N)
{
    // 50 [N]を加える(ワイヤのたるみ防止)
    float init_force = 50.0;
    // float init_force = 100.0;
    _currentForce = _loadc->ReadCurrentForce();
    while(_currentForce <= init_force) _currentForce = this->OutOnePalse();
    _motor->Stop();

    // 2 [s]停止
    int deleyTime = 2;//[s]
    for(int i=0; i < deleyTime*50; i++)
    {
        Serial.println(_loadc->ReadCurrentForce());
        delay(20);
    }

    Serial.println("x");
    // N [N]のステップ関数を加える
    while(true)
    {
        _currentForce = _loadc->ReadCurrentForce();       
        Serial.print(_loadc->ReadCurrentForce()); Serial.print(",");

        _palse = _motor->MakePalseFrom(_pid->MakeAdjustment(N, (_currentForce-init_force)));
        Serial.print(_palse); Serial.println(",");
        _motor->SetVellocity(_palse);
        delay(20);
        _motor->Stop();
    }
    _motor->Stop();
}

void Muscle::Debug_cw_ccw()
{
    int c = 1;
    for(int i=0; i<20; i++)
    {
        _palse =  c *MAXVellocity;
        Serial.print(_palse); Serial.println(",");
        _motor->SetVellocity(_palse);
        delay(20);
        _motor->Stop();
        c *= -1;
    }
    _motor->Stop();
}


// forceを目標値として, PID制御を行います. Loop内で使用して下さい.
void Muscle::Stretch(const float force)
{
    _currentForce = _loadc->ReadCurrentForce();       
    // Serial.print(_loadc->ReadCurrentForce()); Serial.print(",");

    _palse = _motor->MakePalseFrom(_pid->MakeAdjustment(force, _currentForce));
    // Serial.print(_palse); Serial.println(",");
    _motor->SetVellocity(_palse);
    delay(20);
    _motor->Stop();
}