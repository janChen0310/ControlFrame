#ifndef ARM_H
#define ARM_H

#include "Device.h"
#include "RemoteControl.h"
#include "FlexiTimer2.h"

#define dir 4
#define pulse 7
#define UP 1
#define DOWN -1
#define HOLD 0

void PulseGen();

class Arm : public Device{
  private:
    /* begin your private prototypes here */
    int direction;
  public:
    void Init() override;
    void Handle() override;

    /* begin your public prototypes here */
    friend void PulseGen();
};

#endif