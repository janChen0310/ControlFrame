#ifndef REMOTE_CONTROL_H
#define REMOTE_CONTROL_H

#include "Device.h"
#include "PS2X_lib.h"

// define pins connected to the PS2 controller
#define PS2_DAT         25    
#define PS2_CMD         23 
#define PS2_SEL         24 
#define PS2_CLK         22 
#define PS2X_DEBUG


// select modes of PS2 controller
#define pressures   true // analog reading of push buttons true
#define rumble      true // motor rumbling true

class RemoteControl : public Device, private PS2X{
  public:
      struct ButtonStates {
      byte up;
      byte right;
      byte down;
      byte left;
      byte start;
      byte select;
      byte R2;
      byte L2;
      byte R3;
      byte L3;
      byte X;
      byte A;
      byte Y;
      byte B;
      byte leftStickX;   // X coordinate of left stick
      byte leftStickY;   // Y coordinate of left stick
      byte rightStickX;  // X coordinate of right stick
      byte rightStickY;  // Y coordinate of right stick
    };

    void PrintButtons();
  private:
    /* begin your private prototypes here */
    ButtonStates buttonStates;
  public:
    /* begin your public prototypes here */
    void Init() override;
    void Handle() override;
    inline RemoteControl::ButtonStates GetState(){
      return buttonStates;
    }
};

#endif