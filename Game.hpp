#ifndef GAME
#define GAME

#include "Define.hpp"
#include "Pid.hpp"
#include "I2c.hpp"
#include "Motor.hpp"
#include "LoadCel.hpp"

class Game
{
private:
    I2c*     _i2c;
    Pid*     _pid;
    Motor*   _motor;
    LoadCel* _loadc;

    float _currentForce;
    float _calcForce;
public:
    Game(
            I2c*     i2c,
            Pid*     pid,
            Motor*   motor,
            LoadCel* loadc
        );
    void Step(c_float reff);
    void TestLoadCel();
};

#endif
