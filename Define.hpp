#ifndef DEFINE
#define DEFINE

typedef const float  c_float;
typedef const long   c_long;
typedef const int    c_int;
typedef unsigned int u_int;

c_float DT    = 0.02;

c_float PGAIN = 15;// 1.5
c_float IGAIN = 0.0;// 0.26
c_float DGAIN = 0.0;// 0.03

/* 筋張力発生機構のパラメータ */
c_float springConstant  = 88150;//[N/m]
c_float pulleyDiameter  = 0.03;//[m]
c_int   gearRate        = 10;//[ ]
c_int   motorResolution = 1000;//[Hz]
c_long  MAXVellocity    = 50000;//[Hz] 50rpm

/* PIN SETTING*/
c_int PinForAnalogRead = 0;
/* For Motor Class */
c_int PinForCw = 12;
c_int PinForCcw = 10;
/* For ControlBranch Class */
#define I2CADDR          0x03
c_int Register = 1;
/** For CalcCurrentForce  */

/* y = a * x + b */
c_float A = 0.0056;
c_float B = -0.1038;

#endif