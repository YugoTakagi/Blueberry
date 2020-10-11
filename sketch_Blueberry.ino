#include "Game.hpp"

/*
 * Init Class instance
 */
I2c     i2c(I2CADDR);
Pid     pid(DT, PGAIN, IGAIN, DGAIN);
Motor   motor(DT);
LoadCel loadc(DT, 5.0);

Game gm(&i2c, &pid, &motor, &loadc);


/*
 * I2c用の割り込み関数を定義
 */
void ReceiveEventForI2c(int inNumOfRecvBytes);
void RequestEventForI2c(void);


/*
 * 初期化関数
 */
void setup(void)
{
//  checker.startFlag = false;

  Serial.begin(9600);
  Wire.begin(I2CADDR);
  Wire.onReceive(ReceiveEventForI2c); //割り込み関数(for i2c)
  Wire.onRequest(RequestEventForI2c); //割り込み関数(for i2c)

  delay(1000);
}


/*
 * main関数
 */
void loop(void)
{
  /* この中にゲーム内容を書き込む */



  gm.Step(150.0);



  /* ********************** */
}







void ReceiveEventForI2c(int inNumOfRecvBytes)
{  
//  dataPack.data = i2c.Read();
//  Game(dataPack.bytes);
//  Serial.println(dataPack.bytes);
//  hz = data;
//  Serial.println(data, 6);
  
//  float adj = branch1.PidController(data, branch1.CalcCurrentForce());//[N]
//  long hz = branch1.CalcPalseFromForce(adj);
//  motor.SetVellocity(hz);
//  hz = branch1.CalcPalseFromForce(adj);
}
void RequestEventForI2c(void)
{
//  i2c.Write(hz);
}
