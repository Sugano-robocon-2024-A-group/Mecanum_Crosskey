#include <PS4Controller.h>
#include "PS4cross.hpp"

// 移動距離の目標設定（mm単位）
float targetDistance[4] = {0, 0, 0, 0}; // 各ホイールの移動距離目標

void PS4Cross(int speed)
{
  if (PS4.isConnected())
  {
    if (PS4.Left())
    {
      Serial.println("Left");
      targetDistance[0] = -speed;
      targetDistance[1] = speed;
      targetDistance[2] = speed;
      targetDistance[3] = -speed;
    }
    if (PS4.Up())
    {
      Serial.println("Up");
      targetDistance[0] = speed;
      targetDistance[1] = speed;
      targetDistance[2] = speed;
      targetDistance[3] = speed;
    }
    if (PS4.Right())
    {
      Serial.println("Right");
      targetDistance[0] = speed;
      targetDistance[1] = -speed;
      targetDistance[2] = -speed;
      targetDistance[3] = speed;
    }
    if (PS4.Down())
    {
      Serial.println("Down");
      targetDistance[0] = -speed;
      targetDistance[1] = -speed;
      targetDistance[2] = -speed;
      targetDistance[3] = -speed;
    }
    
    if (PS4.UpLeft())
    {
      Serial.println("Up Left");
      targetDistance[0] = 0;
      targetDistance[1] = speed;
      targetDistance[2] = speed;
      targetDistance[3] = 0;
    }
    if (PS4.UpRight())
    {
      Serial.println("Up Right");
      targetDistance[0] = speed;
      targetDistance[1] = 0;
      targetDistance[2] = 0;
      targetDistance[3] = speed;
    }
    if (PS4.DownRight())
    {
      Serial.println("Down Right");
      targetDistance[0] = 0;
      targetDistance[1] = -speed;
      targetDistance[2] = -speed;
      targetDistance[3] = 0;
    }
    if (PS4.DownLeft())
    {
      Serial.println("Down Left");
      targetDistance[0] = -speed;
      targetDistance[1] = 0;
      targetDistance[2] = 0;
      targetDistance[3] = -speed;
    }
  }
  else
  {
    targetDistance[0] = 0;
    targetDistance[1] = 0;
    targetDistance[2] = 0;
    targetDistance[3] = 0;
  }
}
