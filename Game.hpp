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
    I2c     _i2c;
    Pid     _pid;
    Motor   _motor;
    LoadCel _loadc;

    float _currentForce;
    float _calcForce;
public:
    Game(
            const uint8_t addr,
            c_float dt,
            c_float pGain, c_float iGain, c_float dGain
        );
    void Step(c_float reff);
};

#endif
