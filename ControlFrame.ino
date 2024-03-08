

#include "RemoteControl.h"
#include "Chassis.h"
#include "Arm.h"
#include "Jaw.h"

extern RemoteControl remoteControl;
extern Chassis chassis;
extern Arm arm;
extern Jaw jaw;

void setup() {
  Serial.begin(115200); // Communication with the computer
  // put your setup code here, to run once:
  remoteControl.Init();
  chassis.Init();
  arm.Init();
  jaw.Init();
}

void loop() {
  // put your main code here, to run repeatedly:
  remoteControl.Handle();
  // remoteControl.PrintButtons();
  chassis.Handle();
  arm.Handle();
  jaw.Handle();
}
