#ifndef REMOTE_CONTROL_H
#define REMOTE_CONTROL_H

#include "Device.h"

class RemoteControl : public Device{
  private:
    /* begin your private prototypes here */

  public:
    void Init() override;
    void Handle() override;

    /* begin your public prototypes here */

};

#endif