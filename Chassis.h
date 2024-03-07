#ifndef CHASSIS_H
#define CHASSIS_H

#include "Device.h"
#include "RemoteControl.h"

#define L1_IN1 9
#define L1_IN2 10
#define L1_ENA 8
#define L2_IN1 4
#define L2_IN2 3
#define L2_ENA 2
#define L3_IN1 6
#define L3_IN2 5
#define L3_ENA 7
#define L4_IN1 11
#define L4_IN2 12
#define L4_ENA 13

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