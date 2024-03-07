#ifndef ARM_H
#define ARM_H

#include "Device.h"
#include "RemoteControl.h"

#define dir 4
#define pulse 7
#define UP 1
#define DOWN -1
#define HOLD 0

class Arm : public Device{
  private:
    /* begin your private prototypes here */
    byte direction;
  public:
    void Init() override;
    void Handle() override;

    /* begin your public prototypes here */

};

#endif