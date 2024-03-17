#include "FlexiTimer2.h"
#include "RemoteControl.h"
#include "Chassis.h"
#include "Arm.h"
#include "Jaw.h"

extern RemoteControl remoteControl;
extern Chassis chassis;
extern Arm arm;
extern Jaw jaw;

void TIMHandle(); // timer handle

void setup() {
  Serial.begin(115200); // Communication with the computer
  // init all module
  remoteControl.Init();
  chassis.Init();
  arm.Init();
  jaw.Init();
  FlexiTimer2::set(20, 1.0/1000, TIMHandle); // set timer interrupt with time period 20 * (1.0/1000) s
  FlexiTimer2::start();
}

void loop() {
  // use main loop to generate pulse to drive the stepping motor
  if(arm.direction != 0)
    {
      for(int x = 0; x < 200; x++) {
      digitalWrite(13,HIGH); 
      delayMicroseconds(500); 
      digitalWrite(13,LOW); 
      delayMicroseconds(500); 
    }
  }
}

void TIMHandle()
{
  remoteControl.Handle();
  // remoteControl.PrintButtons();
  chassis.Handle();
  arm.Handle();
  jaw.Handle();
}
