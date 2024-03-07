#include "Jaw.h"

Jaw jaw;
extern RemoteControl remoteControl;

void Jaw::Init() {
  grab.attach(ServoGrab);
  rotate.attach(ServoRotate);
  // reset servos
  grab.write(0);
  rotate.write(90);
}

void Jaw::Handle() {
  angle_r = rotate.read();
  angle_g = grab.read();
  byte x = remoteControl.GetState().X;
  byte y = remoteControl.GetState().Y;
  byte a = remoteControl.GetState().A;
  byte b = remoteControl.GetState().B;
  if (x == 1) {
    if (state_x == 0) {
      state_x = 1;
      stop_x = angle_r / 45 + 1;
      stop_x *= 45;
    }
    if (state_x == 1) {
      state_x = 0;
    }
  } else {
    if (stop_x > 180) {
      state_x = 0;
    }
    if (state_x == 1) {
      if (angle_r < stop_x) {
        rotate.write(angle_r + 1);
      } else {
        state_x = 0;
      }
    }
  }
  if (y == 1) {
    if (state_y == 0) {
      state_y = 1;
      stop_y = (angle_r - 1) / 45;
      stop_y *= 45;
    }
    if (state_y == 1) {
      state_y = 0;
    }
  } else {
    if (stop_y < 0) {
      state_y = 0;
    }
    if (state_y == 1) {
      if (angle_r > stop_y) {
        rotate.write(angle_r - 1);
      } else {
        state_y = 0;
      }
    }
  }  //x,y for rotate, push one time then run, push another time or reach 45k degree then stop
  if (a == 1) {
    if (state_a == 0) {
      state_a = 1;
    } else {
      state_a = 0;
    }
  } else {
    if (angle_g >= 180) {
      state_a = 0;
    }
    if (state_a == 1) {
      grab.write(angle_g + 1);
    }
  }
  if (b == 1) {
    if (state_b == 0) {
      state_b = 1;
    } else {
      state_b = 0;
    }
  } else {
    if (angle_g <= 0) {
      state_b = 0;
    }
    if (state_b == 1) {
      grab.write(angle_g - 1);
    }
  }  //a,b for grab, push one time then run, push another time then stop
}