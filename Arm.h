#ifndef ARM_H
#define ARM_H

#include "Device.h"

class Arm : public Device{
  private:
    /* begin your private prototypes here */

  public:
    void Init() override;
    void Handle() override;

    /* begin your public prototypes here */

};

#endif