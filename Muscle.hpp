#ifndef MUSCLE
#define MUSCLE

#include "Define.hpp"
#include "Pid.hpp"
#include "I2c.hpp"
#include "Motor.hpp"
#include "LoadCel.hpp"

class Muscle
{
private:
    I2c*     _i2c;
    Pid*     _pid;
    Motor*   _motor;
    LoadCel* _loadc;

    float _currentForce;
    float _calcForce;
    
    long  _palse;
public:
    Muscle(
            I2c*     i2c,
            Pid*     pid,
            Motor*   motor,
            LoadCel* loadc
        );
    void  StepResponse(c_float reff);
    float OutOnePalse();
    void  Debug_init50N_to_Step(const float N);
    void  Debug_init50N_to_Step_With_PID(const float N);
};

#endif
