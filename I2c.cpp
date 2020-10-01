#include "I2c.hpp"

I2c::I2c(const uint8_t addr)
{
    Wire.begin(addr);
}

float I2c::Read(void)
{
    int i = 0;
    dataPack.data = 0.0;
    while(Wire.available())
    {
        dataPack.bytes[i] = Wire.read();
        i++;
    }
//    Serial.println(dataPack.data, 6);
    return dataPack.data;
}

void I2c::Write(c_float data)
{
    dataPack.data = data;
    Wire.write(dataPack.bytes, 4 * 1);
}
