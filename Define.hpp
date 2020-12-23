#ifndef DEFINE
#define DEFINE

typedef const float  c_float;
typedef const long   c_long;
typedef const int    c_int;
typedef unsigned int u_int;

/* ---------------------------------------------- １ループの時間 */
c_float DT = 0.02;//[s]
const unsigned long MS = 20;//[ms]


/* ---------------------------------------------- PIDゲイン */
// 限界感度法(Kc = 0.2, Tc = 0.82)
// c_float PGAIN = 0.12;//
// c_float IGAIN = 0.292682;//
// c_float DGAIN = 0.0123;//

// 0.18 0.13846153846153844 0.058499999999999996
c_float PGAIN = 0.15;//0.17
c_float IGAIN = 0.11;//0.1
c_float DGAIN = 0.01;//0.0585

/* ---------------------------------------------- 筋張力発生機構のパラメータ */
const unsigned long springConstant  = 88150;//[N/m]
c_float pulleyDiameter  = 0.03;//[m]
c_int   gearRate        = 10;//[-]
c_int   motorResolution = 1000;//[Hz]
// c_long  MAXVellocity    = 50000;//[Hz] 50rpm
c_long  MAXVellocity    = 65534;//[Hz]
// c_int   MINVellocity    = 31; //[Hz]

// 最小二乗法を用いた張力とパルスの関係式
// c_float A_NP            = 0.04443402;//[N/palse]

// 7
// c_float A_NP            = 0.10145333;//[N/palse]
// c_float A_NPB           = 0.28255414;//[N/palse]

// 3
c_float A_NP            = 0.07665082;//[N/palse]
c_float A_NPB           = 0.1880764;//[N/palse]

/* ---------------------------------------------- ピンセット */
#define PinForAnalogRead 2
/* For Motor Class */
c_int PinForCw = 12;
c_int PinForCcw = 10;
/* For ControlBranch Class */
#define I2CADDR          0x19
//c_int Register = 1;
/** For CalcCurrentForce  */

/* ---------------------------------------------- 最小二乗法の係数 */
/* y = a * x + b */
// c_float A = 0.0056;
// c_float B = -0.1038;
// 1回目 良くなかった.
// const float A = 496.17;
// const float B = -4.88;
const float A = 537.976; //6桁にした
const float B = 3.46380; //6桁にした

#endif
