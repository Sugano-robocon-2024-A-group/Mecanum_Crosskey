#include <Arduino.h>
#include <PS4Controller.h>

// モーターとエンコーダのピン設定 （左前　左後　右前　右後）
const int motor_pwm[4] = {21, 13, 16, 4}; // PWM出力ピン
const int motor_dir1[4] = {18, 27, 22, 32}; // 方向ピン1
const int motor_dir2[4] = {19, 14, 23, 33}; // 方向ピン2

const int LEDC_TIMER_BIT = 8;   // PWMの範囲(8bitなら0〜255、10bitなら0〜1023)
const int LEDC_BASE_FREQ = 490; // 周波数(Hz)

void init_pwm_setup()
{
  for (int i = 0; i < 4; i++)
  {
    // モーターピンを出力に設定
    pinMode(motor_pwm[i], OUTPUT);
    pinMode(motor_dir1[i], OUTPUT);
    pinMode(motor_dir2[i], OUTPUT);
    ledcAttach(motor_pwm[i], LEDC_BASE_FREQ, LEDC_TIMER_BIT); // PWM出力ピン、周波数490Hz、8ビット解像度
  }
}

// モーターの駆動方向を制御
void driveMotor(int index, float controlSignal)
{
  if (controlSignal >= 0)
  {
    digitalWrite(motor_dir1[index], HIGH);
    digitalWrite(motor_dir2[index], LOW);
  }
  else
  {
    digitalWrite(motor_dir1[index], LOW);
    digitalWrite(motor_dir2[index], HIGH);
    controlSignal = -controlSignal;
  }
  ledcWrite(motor_pwm[index], (int)controlSignal);
}

// モーターを停止
void stopMotors()
{
  for (int i = 0; i < 4; i++)
  {
    ledcWrite(motor_pwm[i], 0);
    digitalWrite(motor_dir1[i], LOW);
    digitalWrite(motor_dir2[i], LOW);
  }
}

void setup()
{
  init_pwm_setup();
  
  stopMotors();

  Serial.begin(115200);
  PS4.begin("1c:69:20:e6:20:d2");
  Serial.println("Ready.");
}

void loop()
{
  if (PS4.isConnected())
  {
    if (PS4.Right())
    {
      Serial.println("Right");
      driveMotor(0, 200);
      driveMotor(1, -200);
      driveMotor(2, -200);
      driveMotor(3, 200);
    }
    if (PS4.Down())
    {
      Serial.println("Down");
      driveMotor(0, -200);
      driveMotor(1, -200);
      driveMotor(2, -200);
      driveMotor(3, -200);
    }
    if (PS4.Up())
    {
      Serial.println("Up");
      driveMotor(0, 200);
      driveMotor(1, 200);
      driveMotor(2, 200);
      driveMotor(3, 200);
    }
    if (PS4.Left())
    {
      Serial.println("Left");
      driveMotor(0, -200);
      driveMotor(1, 200);
      driveMotor(2, 200);
      driveMotor(3, -200);
    }

    if (PS4.UpRight())
    {
      Serial.println("Up Right");
      driveMotor(0, 200);
      driveMotor(1, 0);
      driveMotor(2, 0);
      driveMotor(3, 200);
    }
    if (PS4.DownRight())
    {
      Serial.println("Down Right");
      driveMotor(0, 0);
      driveMotor(1, -200);
      driveMotor(2, -200);
      driveMotor(3, 0);
    }
    if (PS4.UpLeft())
    {
      Serial.println("Up Left");
      driveMotor(0, 0);
      driveMotor(1, 200);
      driveMotor(2, 200);
      driveMotor(3, 0);
    }
    if (PS4.DownLeft())
    {
      Serial.println("Down Left");
      driveMotor(0, -200);
      driveMotor(1, 0);
      driveMotor(2, 0);
      driveMotor(3, -200);
    }
    delay(100);
    stopMotors();
  }
}
