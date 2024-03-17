#ifndef ARM_H
#define ARM_H

#include "Device.h"
#include "RemoteControl.h"
#include <Stepper.h>
#include "FlexiTimer2.h"

#define dir 12
#define pulse 13
#define UP 1
#define DOWN -1
#define HOLD 0

void setPwmFrequency(int pin,int precision);

class Arm : public Device{
  private:
    /* begin your private prototypes here */

  public:
    void Init() override;
    void Handle() override;
    int direction;
    /* begin your public prototypes here */
};



#endif