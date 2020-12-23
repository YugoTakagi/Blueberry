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
float fRef  = 0.0;
float fY    = 0.0;
float fInit = 0.0;
long  palse = 0.0;
void ReceiveEventForI2c(int inNumOfRecvBytes)
{ 
  // motor.Stop();
  fRef  = i2c.Read();
  // Serial.println(fRef);


  // palse = motor.MakePalseFrom(data);
  // motor.SetVellocity(palse);


//  motor.Stop();
  // motor.SetVellocity(fRef);
//    delay(20);
  // ----- ここに, 筋張力 [N]のPID制御を書く. ------
  // fY = loadc.ReadCurrentForce();
//  // Serial.print(_loadc->ReadCurrentForce()); Serial.print(",");
//
//  palse = motor.MakePalseFrom( pid.MakeAdjustment(fRef, (fY - fInit)) );
//  // Serial.print(_palse); Serial.println(",");
//  motor.SetVellocity(palse);
//  // delay(20);
//  // motor->Stop();


  // /----- ここに, 筋張力 [N]のPID制御を書く. ------
//
//  motor.SetVellocity(fY);
//  delay(20);
//  motor.Stop();


  // Serial.print("palse, ");Serial.println(_palse);
//  Muscle(dataPack.bytes);
//  Serial.println(data, 6);
//  hz = data;
//  Serial.println(data, 6);
  
//  float adj = branch1.PidController(data, branch1.CalcCurrentForce());//[N]
//  long hz = branch1.CalcPalseFromForce(adj);
//  motor.SetVellocity(hz);
//  hz = branch1.CalcPalseFromForce(adj);
};


void RequestEventForI2c(void)
{
// i2c.Write((float) palse);
  i2c.Write((float) fY);
}






unsigned long time_data = 0;
unsigned long time_data2 = 0;
void setup(void)
{
//  checker.startFlag = false;
  /* ----------------- この中に初期設定を書き込む ------------------ */



  Serial.begin(9600);
  Wire.begin(I2CADDR);
  Wire.onReceive(ReceiveEventForI2c); //割り込み関数(for i2c)
  Wire.onRequest(RequestEventForI2c); //割り込み関数(for i2c)
  delay(1000);


  // while (true)
  // {
  //   float v = analogRead(2) * (5.0 / 1023.0);
  //   if(v > 4) break;
  // }
  
  Serial.println("I'm ready");

  /* ----- cw&ccw test -----*/

  // motor.SetVellocity(50);
  // delay(1000*10);
  // motor.Stop();
  // while (true)
  // {
  //   Serial.println("testing motor");
  // }

  /* /----- cw&ccw test -----*/



  /* ----- testing loadcel reader ----- */

  // while (true)
  // {
  //   // Serial.println("testing motor");
  //   fY = loadc.ReadCurrentForce();
  //   Serial.print("fY : ");Serial.println(fY);
  //   delay(20);
  // }

  /* /----- testing loadcel reader ----- */

  




  /* ----------------- /この中に初期設定を書き込む ----------------- */



  // float currentForce = 0.0;
  // delay(1000);
  // while(currentForce < 20.0) currentForce = gm.OutOnePalse();
  // motor.Stop();
  // delay(1000);
  // while(currentForce < 150.0) currentForce = gm.OutOnePalse();
  // motor.Stop();

  // time_data = millis();




  // float currentForce = 0.0;
  // while(currentForce <= 70.0) currentForce = muscle.OutOnePalse();
  // motor.Stop();
  // // float currentForce = 0.0;
  // Serial.println(0);
  // while(currentForce >= 20.0) currentForce = muscle.OutOnePalse_ccw();
  // motor.Stop();
  // muscle.Debug_init50N_to_Step(50.0/*[N]*/);
  // muscle.Debug_init50N_to_Step_With_PID(50.0/*[N]*/);

  // muscle.Debug_cw_ccw();





  // time_data2 = millis();
  // Serial.print("dmillis: ");
  // Serial.println(time_data2-time_data);

  // long palse = motor.MakePalseFrom(150.0);
  // Serial.print(">");Serial.println(palse);
}


/*
 * mainループ
 */
int i = 0;
void loop(void)
{
  while(true)
  {
    if (i == 0)
    {
      fRef = loadc.ReadCurrentForce();
      // fRef += 10;
      muscle.Stretch(fRef);
    }
    else
    {
      fY = loadc.ReadCurrentForce();
      Serial.print("fRef, fY, ");Serial.print(fRef);Serial.print(",");Serial.println(fY);


      // ----- ここに, ただ回すプログラム ----- 

      // if(fRef > 0)
      // {
      //   if(fRef <= fY) motor.Stop();
      // }
      // else
      // {
      //   if(fRef >= fY) motor.Stop();
      // }

      // ----- ここに, PIDのプログラム -----
      muscle.Stretch(fRef);


    }
    i++;
    
  /* ----------------- この中にゲーム内容を書き込む ------------------ */
//    motor.SetVellocity(5000.0);
//    delay(20);
    

    // motor.SetVellocity(motor.MakePalseFrom(150.0));

    // N [N]のステップ関数を加える
    // palse = motor.MakePalseFrom(data);
    // motor.SetVellocity(palse);
    // // Serial.print("palse, ");Serial.println(_palse);
    // delay(20);
    // motor.Stop();
    // Serial.println(loadc.ReadCurrentForce());
    // gm.Step(150.0);
    // gm.TestLoadCel();



//    motor.SetVellocity(5000);
//    delay(20);
//    motor.Stop();
  /* ----------------- /この中にゲーム内容を書き込む ----------------- */
  }
}






// void ReceiveEventForI2c(int inNumOfRecvBytes)
// { 
//   motor.Stop();
//   data = i2c.Read();
//   palse = motor.MakePalseFrom(data);
//   motor.SetVellocity(palse);




//   // ----- ここに, 筋張力 [N]のPID制御を書く. ------


//   _currentForce = _loadc->ReadCurrentForce();       
//   Serial.print(_loadc->ReadCurrentForce()); Serial.print(",");

//   _palse = _motor->MakePalseFrom(_pid->MakeAdjustment(N, (_currentForce-init_force)));
//   Serial.print(_palse); Serial.println(",");
//   _motor->SetVellocity(_palse);
//   delay(20);
//   _motor->Stop();


//   // /----- ここに, 筋張力 [N]のPID制御を書く. ------




//   // Serial.print("palse, ");Serial.println(_palse);
// //  Muscle(dataPack.bytes);
// //  Serial.println(data, 6);
// //  hz = data;
// //  Serial.println(data, 6);
  
// //  float adj = branch1.PidController(data, branch1.CalcCurrentForce());//[N]
// //  long hz = branch1.CalcPalseFromForce(adj);
// //  motor.SetVellocity(hz);
// //  hz = branch1.CalcPalseFromForce(adj);
// };
// void RequestEventForI2c(void)
// {
//  i2c.Write((float) palse);
// }
