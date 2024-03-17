#include "Chassis.h"  

Chassis chassis;
extern RemoteControl remoteControl;

void Chassis::DriveWheel(int pwm, int IN1, int IN2, int ENA)
{
  if(pwm >= 5)
  {
    if(pwm > 255) pwm = 255;
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, pwm);
  }
  else if(pwm <= -5)
  {
    if(pwm < -255) pwm = -255;
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, -pwm);
  }
  else
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, 0);
  }
}

void Chassis::Init()
{
  /* begin your pinmode define here */
  pinMode(L1_IN1, OUTPUT);
  pinMode(L1_IN2, OUTPUT);
  pinMode(L1_ENA, OUTPUT);
  pinMode(L2_IN1, OUTPUT);
  pinMode(L2_IN2, OUTPUT);
  pinMode(L2_ENA, OUTPUT);
  pinMode(L3_IN1, OUTPUT);
  pinMode(L3_IN2, OUTPUT);
  pinMode(L3_ENA, OUTPUT);
  pinMode(L4_IN1, OUTPUT);
  pinMode(L4_IN2, OUTPUT);
  pinMode(L4_ENA, OUTPUT);
}

void Chassis::Handle()
{
  /* begin your circularly executed code here */
  // Get chassis velocity from remote controller
  Vx = remoteControl.GetState().rightStickX - 128;
  Vy = remoteControl.GetState().rightStickY - 128;
  W = remoteControl.GetState().leftStickX - 128;

  if(Vx > -5 && Vx < 5)Vx = 0;
  if(Vy > -5 && Vy < 5)Vy = 0;
  if(W > -5 && W < 5)W = 0;

  // Serial.print("W = ");
  // Serial.print(W);

  //calculate velocity of each wheel
  V1 = (Vy - Vx + W*(Half_Width + Half_Length)/20)*2;
  V2 = (Vy + Vx - W*(Half_Width + Half_Length)/20)*2;
  V3 = (Vy - Vx - W*(Half_Width + Half_Length)/20)*2;
  V4 = (Vy + Vx + W*(Half_Width + Half_Length)/20)*2;

  // Serial.print("V1 = ");
  // Serial.print(V1);
  // Serial.print("\t");
  // Serial.print("V2 = ");
  // Serial.print(V2);
  // Serial.print("\t");
  // Serial.print("V3 = ");
  // Serial.print(V3);
  // Serial.print("\t");
  // Serial.print("V4 = ");
  // Serial.print(V4);
  // Serial.print("\t");
  // Serial.print("\n");

  DriveWheel(V2, L2_IN1, L2_IN2, L2_ENA);
  DriveWheel(-V3, L3_IN1, L3_IN2, L3_ENA);
  DriveWheel(V1, L1_IN1, L1_IN2, L1_ENA);
  DriveWheel(V4, L4_IN1, L4_IN2, L4_ENA);
}