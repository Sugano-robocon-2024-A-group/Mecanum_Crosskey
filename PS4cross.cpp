#include <PS4Controller.h>
#include "PS4cross.hpp"

// 移動距離の目標設定（mm単位）
float targetDistance[4] = {0, 0, 0, 0}; // 各ホイールの移動距離目標

void PS4Cross(int speed, int Ashimawari_Command)
{
  //if (PS4.isConnected())
  //{
  if (Ashimawari_Command==0){
    targetDistance[0] = 0;
      targetDistance[1] =0;
      targetDistance[2] = 0;
      targetDistance[3] = 0;
    }
    if (Ashimawari_Command==4)
    {
      Serial.println("Left");
      targetDistance[0] = -speed;
      targetDistance[1] = speed;
      targetDistance[2] = speed;
      targetDistance[3] = -speed;
    }
    if (Ashimawari_Command==1)
    {
      Serial.println("Up");
      targetDistance[0] = speed;
      targetDistance[1] = speed;
      targetDistance[2] = speed;
      targetDistance[3] = speed;
    }
    if (Ashimawari_Command==3)
    {
      Serial.println("Right");
      targetDistance[0] = speed;
      targetDistance[1] = -speed;
      targetDistance[2] = -speed;
      targetDistance[3] = speed;
    }
    
    if (Ashimawari_Command==2)
    {
      Serial.println("Down");
      targetDistance[0] = -speed;
      targetDistance[1] = -speed;
      targetDistance[2] = -speed;
      targetDistance[3] = -speed;
    }
    if (Ashimawari_Command==6)
    {
      Serial.println("Up Left");
      targetDistance[0] = 0;
      targetDistance[1] = speed;
      targetDistance[2] = speed;
      targetDistance[3] = 0;
    }
    if (Ashimawari_Command==5)
    {
      Serial.println("Up Right");
      targetDistance[0] = speed;
      targetDistance[1] = 0;
      targetDistance[2] = 0;
      targetDistance[3] = speed;
    }
    if (Ashimawari_Command==7)
    {
      Serial.println("Down Right");
      targetDistance[0] = 0;
      targetDistance[1] = -speed;
      targetDistance[2] = -speed;
      targetDistance[3] = 0;
    }
    if (Ashimawari_Command==8)
    {
      Serial.println("Down Left");
      targetDistance[0] = -speed;
      targetDistance[1] = 0;
      targetDistance[2] = 0;
      targetDistance[3] = -speed;
    }
  //}
}
