#ifndef CHASSIS_H
#define CHASSIS_H

#include "Device.h"

class Chassis : public Device{
  private:
    /* begin your private prototypes here */

  public:
    void Init() override;
    void Handle() override;
    
    /* begin your public prototypes here */

};

#endif