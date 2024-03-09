#include "FlexiTimer2.h"
#include "Arm.h"

Arm arm;
extern RemoteControl remoteControl;

void PulseGen()
{
  if(arm.direction == 0)
  {
    digitalWrite(pulse, LOW);
    return;
  }
  static bool val = 1;
  digitalWrite(pulse, val);
  val = !val;
  Serial.println(val);
}

void Arm::Init()
{
  /* begin your pinmode define here */
  pinMode(dir, OUTPUT);
  pinMode(pulse, OUTPUT);

  FlexiTimer2::set(50, 1.0/100000, PulseGen); // 利用定时器中断产生脉冲信号 周期50*1/100000s
  FlexiTimer2::start();
}

void Arm::Handle()
{
  /* begin your circularly executed code here */
  direction = remoteControl.GetState().up - remoteControl.GetState().down;
  // Serial.println(direction);
  switch(direction){
    case UP: digitalWrite(dir, HIGH);
    break;
    case DOWN: digitalWrite(dir, LOW);
    break;
    default: break;
  }
}