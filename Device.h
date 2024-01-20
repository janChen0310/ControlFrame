#ifndef DEVICE_H
#define DEVICE_H

#include "HardwareSerial.h"
#include "Arduino.h"

class Device{
  public:
    virtual void Init() = 0;
    virtual void Handle() = 0;
    inline void print() // override the function to print messages you want
    {
      Serial.println("A device has been created!");
    }
};

#endif