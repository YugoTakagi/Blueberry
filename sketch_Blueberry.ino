#include "Game.hpp"

// Init *****
Game gm(I2CADDR, DT, PGAIN, IGAIN, DGAIN);

void ReceiveEventForI2c(int inNumOfRecvBytes);
void RequestEventForI2c(void);
/* Main Loop  ***  Main Loop  ***  Maon Loop  ***  Main Loop  ***  Main Loop */
/* Main Loop  ***  Main Loop  ***  Maon Loop  ***  Main Loop  ***  Main Loop */
/* Main Loop  ***  Main Loop  ***  Maon Loop  ***  Main Loop  ***  Main Loop */

void setup(void)
{
  // put your setup code here, to run once:
//  checker.startFlag = false;

  Serial.begin(9600);
  Wire.begin(I2CADDR);
  Wire.onReceive(ReceiveEventForI2c); //割り込み関数(for i2c)
  Wire.onRequest(RequestEventForI2c); //割り込み関数(for i2c)

  delay(1000);
}

void loop(void)
{
  // put your main code here, to run repeatedly:
  gm.Step(150.0);
}
/* Main Loop  ***  Main Loop  ***  Maon Loop  ***  Main Loop  ***  Main Loop */
/* Main Loop  ***  Main Loop  ***  Maon Loop  ***  Main Loop  ***  Main Loop */
/* Main Loop  ***  Main Loop  ***  Maon Loop  ***  Main Loop  ***  Main Loop */

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
