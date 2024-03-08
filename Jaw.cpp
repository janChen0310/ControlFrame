#include "Jaw.h"

Jaw jaw;
extern RemoteControl remoteControl;

void Jaw::Init() {
  grab.attach(ServoGrab);
  rotate.attach(ServoRotate);
  // reset servos
  grab.write(0);
  rotate.write(90);
}

void Jaw::Handle() {
  angle_r += remoteControl.GetState().X; // 夹爪旋转
  angle_r -= remoteControl.GetState().Y;
  angle_g += remoteControl.GetState().A; // 夹爪张开/闭合
  angle_g -= remoteControl.GetState().B;

  if(angle_r > 180)angle_r = 180;
  else if(angle_r < 0)angle_r = 0;

  if(angle_g > 180)angle_g = 180;
  else if(angle_g < 0)angle_g = 0;

  
  if(grab.read() != angle_g)grab.write(angle_g);
  if(rotate.read() != angle_r)rotate.write(angle_r);
}