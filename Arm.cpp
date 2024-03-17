#include "FlexiTimer2.h"
#include "Arm.h"

Arm arm;
extern RemoteControl remoteControl;

void Arm::Init()
{
  /* begin your pinmode define here */
  pinMode(dir, OUTPUT);
  pinMode(pulse, OUTPUT);

}

void Arm::Handle()
{
  /* begin your circularly executed code here */
  direction = remoteControl.GetState().up - remoteControl.GetState().down;
  // Serial.println(direction);
  switch(direction){
    case UP: 
    digitalWrite(dir, HIGH);
    break;
    case DOWN: 
    digitalWrite(dir, LOW);
    break;
    default:
    break;
  }
}