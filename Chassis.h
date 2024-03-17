#ifndef CHASSIS_H
#define CHASSIS_H

#include "Device.h"
#include "RemoteControl.h"

#define L1_IN1 33
#define L1_IN2 31
#define L1_ENA 2
#define L2_IN1 30 //TODO:更换电机引脚
#define L2_IN2 32
#define L2_ENA 5
#define L3_IN1 26
#define L3_IN2 28
#define L3_ENA 4
#define L4_IN1 29
#define L4_IN2 27
#define L4_ENA 3

#define Half_Width 12.5
#define Half_Length 8.3

class Chassis : public Device{
  private:
    /* begin your private prototypes here */
    int Vx, Vy, W; // velocity of chassis 
    int V1, V2, V3, V4; // velocity of the wheels : right front, left front, left back, right back
    void DriveWheel(int pwm, int IN1, int IN2, int ENA);
  public:
    void Init() override;
    void Handle() override;
    
    /* begin your public prototypes here */

};

#endif