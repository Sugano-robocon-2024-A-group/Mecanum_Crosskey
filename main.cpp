#include <Arduino.h>
#include <PS4Controller.h>
#include "motor.hpp"
#include "PS4cross.hpp"

int speed = 100;  // (0~255)

void setup()
{
  setupMotors();
  stopMotors();

  Serial.begin(115200);
  PS4.begin("1c:69:20:e6:20:d2");
  Serial.println("Ready.");
}

void loop()
{
  PS4Cross(speed);
  for (int i = 0; i < 4; i++)
  {
    driveMotor(i, targetDistance[i]);
  }
}
