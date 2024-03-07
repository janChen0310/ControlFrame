#ifndef DEVICE_H
#define DEVICE_H

#include "HardwareSerial.h"
#include "Arduino.h"

class Device{
  public:
    virtual void Init() = 0;
    virtual void Handle() = 0;
};

#endif