

#include "RemoteControl.h"
#include "Chassis.h"
#include "Arm.h"

extern RemoteControl remoteControl;
extern Chassis chassis;
extern Arm arm;

void setup() {
  Serial.begin(9600); // Communication with the computer
  // put your setup code here, to run once:
  remoteControl.Init();
  chassis.Init();
  arm.Init();
}

void loop() {
  // put your main code here, to run repeatedly:
  remoteControl.Handle();
  chassis.Handle();
  arm.Handle();
}
