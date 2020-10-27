#include "Muscle.hpp"

/*
 * Init Class instance
 */
I2c     i2c(I2CADDR);
Pid     pid(DT, PGAIN, IGAIN, DGAIN);
Motor   motor(DT);
LoadCel loadc(DT, 5.0);

Muscle muscle(&i2c, &pid, &motor, &loadc);


/*
 * I2c用の割り込み関数を定義
 */
void ReceiveEventForI2c(int inNumOfRecvBytes);
void RequestEventForI2c(void);


/*
 * 初期化関数
 */
unsigned long time_data = 0;
unsigned long time_data2 = 0;
void setup(void)
{
//  checker.startFlag = false;

  Serial.begin(9600);
  Wire.begin(I2CADDR);
  Wire.onReceive(ReceiveEventForI2c); //割り込み関数(for i2c)
  Wire.onRequest(RequestEventForI2c); //割り込み関数(for i2c)
  delay(1000);

  // float currentForce = 0.0;
  // delay(1000);
  // while(currentForce < 20.0) currentForce = gm.OutOnePalse();
  // motor.Stop();
  // delay(1000);
  // while(currentForce < 150.0) currentForce = gm.OutOnePalse();
  // motor.Stop();

  // time_data = millis();





  // while(_currentForce <= 150.0) _currentForce = this->OutOnePalse();
  muscle.Debug_init20N_to_Step(150.0/*[N]*/);





  // time_data2 = millis();
  // Serial.print("dmillis: ");
  // Serial.println(time_data2-time_data);

  // long palse = motor.MakePalseFrom(150.0);
  // Serial.print(">");Serial.println(palse);
}


/*
 * mainループ
 */
void loop(void)
{
  while(true)
  {
  /* ----------------- この中にゲーム内容を書き込む ------------------ */



  // delay(20);
  // Serial.println(loadc.ReadCurrentForce());
  // gm.Step(150.0);
  // gm.TestLoadCel();



  /* ----------------- この中にゲーム内容を書き込む ------------------ */
  }
}







void ReceiveEventForI2c(int inNumOfRecvBytes)
{  
//  dataPack.data = i2c.Read();
//  Muscle(dataPack.bytes);
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
