#ifndef JAW_H
#define JAW_H

#include "Device.h"
#include "RemoteControl.h"
#include <Servo.h>

#define ServoGrab 50
#define ServoRotate 9

class Jaw : public Device{
  public:
    void Init() override;
    void Handle() override;
  private:
  Servo rotate, grab;
  int angle_r,angle_g;
  int state_x,state_y,state_a,state_b;
  int stop_x,stop_y;
};


#endif