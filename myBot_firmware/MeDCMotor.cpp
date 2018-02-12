#include "MeDCMotor.h"

MeDCMotor::MeDCMotor(): MePort(0)
{
   speedport = MePort(PORT_8);
   speedport.dWrite1(LOW);
   speedport.dWrite2(LOW);
}

MeDCMotor::MeDCMotor(uint8_t port): MePort(port)
{
   speedport = MePort(PORT_8);
   speedport.dWrite1(LOW);
   speedport.dWrite2(LOW);   
}
void MeDCMotor::run(int speed)
{
    speed = speed > 255 ? 255 : speed;
    speed = speed < -255 ? -255 : speed;

   
    
    if (_port == M1) {
      speed = -speed;
    }

    int sigdir = HIGH;
    if (speed == 0) {
      sigdir = LOW;
    }
    
    if(speed >= 0) {
        MePort::dWrite2(LOW);
        MePort::dWrite1(sigdir);
    } else {
        MePort::dWrite1(LOW);
        MePort::dWrite2(sigdir);
        speed = - speed;
    }

    if (_port == M1) {
      speedport.aWrite1(speed);
    } else {
      speedport.aWrite2(speed);
    }
    

}
void MeDCMotor::stop()
{
    MeDCMotor::run(0);
}
