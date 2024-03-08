#include "RemoteControl.h"
#include <stdio.h>

RemoteControl remoteControl;

byte error;
byte type;
byte vibrate;

void RemoteControl::PrintButtons()
{
  char message[5][128];
  sprintf(message[0], "up = %d;\t down = %d;\t left = %d;\t right = %d", buttonStates.up, buttonStates.down, buttonStates.left, buttonStates.right);
  sprintf(message[1], "R2 = %d;\t L2 = %d;\t R3 = %d;\t L3 = %d", buttonStates.R2, buttonStates.L2, buttonStates.R3, buttonStates.L3);
  sprintf(message[2], "X = %d;\t Y = %d;\t A = %d;\t B = %d", buttonStates.X, buttonStates.Y, buttonStates.A, buttonStates.B);
  sprintf(message[3], "lsX = %d;\t lsY = %d;\t rsX = %d;\t, rsY = %d", buttonStates.leftStickX, buttonStates.leftStickY, buttonStates.rightStickX, buttonStates.rightStickY);
  sprintf(message[4], "select = %d;\t start = %d;", buttonStates.select, buttonStates.start);

  Serial.println(message[0]);
  Serial.println(message[1]);
  Serial.println(message[2]);
  Serial.println(message[3]);
  Serial.println(message[4]);
}

void RemoteControl::Init()
{
  delay(500);  //added delay to give wireless ps2 module some time to startup, before configuring it

  error = PS2X::config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble); // controller self check
  
  if(error == 0){
    Serial.print("Found Controller, configured successful ");
    Serial.print("pressures = ");
	if (pressures)
	  Serial.println("true ");
	else
	  Serial.println("false");
	Serial.print("rumble = ");
	if (rumble)
	  Serial.println("true)");
	else
	  Serial.println("false");
    Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
    Serial.println("holding L1 or R1 will print out the analog stick values.");
    Serial.println("Note: Go to www.billporter.info for updates and to report bugs.");
  }  
  else if(error == 1)
    Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");
   
  else if(error == 2)
    Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");

  else if(error == 3)
    Serial.println("Controller refusing to enter Pressures mode, may not support it. ");
  
  type = PS2X::readType(); 
  switch(type) {
    case 0:
      Serial.println("Unknown Controller type found ");
      break;
    case 1:
      Serial.println("DualShock Controller found ");
      break;
    case 2:
      Serial.println("GuitarHero Controller found ");
      break;
	case 3:
      Serial.println("Wireless Sony DualShock Controller found ");
      break;
   }
}

void RemoteControl::Handle()
{
  /* begin your circularly executed code here */

  PS2X::read_gamepad(); // Read PS2 controller input

  // Read button states and pack them into the structure
  buttonStates.up = PS2X::Button(PSB_PAD_UP);
  buttonStates.right = PS2X::Button(PSB_PAD_RIGHT);
  buttonStates.down = PS2X::Button(PSB_PAD_DOWN);
  buttonStates.left = PS2X::Button(PSB_PAD_LEFT);
  buttonStates.start = PS2X::Button(PSB_START);
  buttonStates.select = PS2X::Button(PSB_SELECT);
  buttonStates.R2 = PS2X::Button(PSB_R2);
  buttonStates.L2 = PS2X::Button(PSB_L2);
  buttonStates.R3 = PS2X::Button(PSB_R3);
  buttonStates.L3 = PS2X::Button(PSB_L3);
  buttonStates.X = PS2X::Button(PSB_SQUARE); // Mapping X to Square
  buttonStates.A = PS2X::Button(PSB_CROSS);   // Mapping A to Cross
  buttonStates.Y = PS2X::Button(PSB_TRIANGLE); // Unchanged mapping for Y
  buttonStates.B = PS2X::Button(PSB_CIRCLE);   // Unchanged mapping for B
  
  // Read analog stick coordinates
  buttonStates.leftStickX = map(PS2X::Analog(PSS_LX), 0, 255, 0, 255);
  buttonStates.leftStickY = map(PS2X::Analog(PSS_LY), 0, 255, 0, 255);
  buttonStates.rightStickX = map(PS2X::Analog(PSS_RX), 0, 255, 0, 255);
  buttonStates.rightStickY = map(PS2X::Analog(PSS_RY), 0, 255, 0, 255);

  // Serial.print(int(buttonStates.rightStickX));
  // Serial.print('\t');
  // Serial.print(int(buttonStates.rightStickY));
  // Serial.print('\t');
  // Serial.print(int(buttonStates.leftStickX));
  // Serial.print('\t');
  // Serial.println();

  // Send the button states structure to the Arduino board
  Serial.write((byte*)&buttonStates, sizeof(buttonStates));
  delay(20);
}