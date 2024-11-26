#include <Arduino.h>
#include <PS4Controller.h>

// 使うピンの定義
// 左前車輪
const int LEFT_FRONT_IN1 = 18;
const int LEFT_FRONT_IN2 = 19;
const int LEFT_FRONT_PWM = 21;

// 左後車輪
const int LEFT_BACK_IN1 = 27;
const int LEFT_BACK_IN2 = 14;
const int LEFT_BACK_PWM = 13;

// 右前車輪
const int RIGHT_FRONT_IN1 = 22;
const int RIGHT_FRONT_IN2 = 23;
const int RIGHT_FRONT_PWM = 16;

// 右後車輪
const int RIGHT_BACK_IN1 = 32;
const int RIGHT_BACK_IN2 = 33;
const int RIGHT_BACK_PWM = 4;

const int LEDC_TIMER_BIT = 8;   // PWMの範囲(8bitなら0〜255、10bitなら0〜1023)
const int LEDC_BASE_FREQ = 490; // 周波数(Hz)

void init_pwm_setup()
{
  // 各ピンを出力モードに設定
  pinMode(LEFT_FRONT_IN1, OUTPUT);
  pinMode(LEFT_FRONT_IN2, OUTPUT);
  pinMode(LEFT_BACK_IN1, OUTPUT);
  pinMode(LEFT_BACK_IN2, OUTPUT);
  pinMode(RIGHT_FRONT_IN1, OUTPUT);
  pinMode(RIGHT_FRONT_IN2, OUTPUT);
  pinMode(RIGHT_BACK_IN1, OUTPUT);
  pinMode(RIGHT_BACK_IN2, OUTPUT);

  // 各PWMピンをアタッチ
  ledcAttach(LEFT_FRONT_PWM, LEDC_BASE_FREQ, LEDC_TIMER_BIT);
  ledcAttach(LEFT_BACK_PWM, LEDC_BASE_FREQ, LEDC_TIMER_BIT);
  ledcAttach(RIGHT_FRONT_PWM, LEDC_BASE_FREQ, LEDC_TIMER_BIT);
  ledcAttach(RIGHT_BACK_PWM, LEDC_BASE_FREQ, LEDC_TIMER_BIT);
}

// 左前車輪の制御
void frontLeftMotor(double pwm)
{
  if (pwm >= 0)
  {
    digitalWrite(LEFT_FRONT_IN1, HIGH);
    digitalWrite(LEFT_FRONT_IN2, LOW);
  }
  else
  {
    digitalWrite(LEFT_FRONT_IN1, LOW);
    digitalWrite(LEFT_FRONT_IN2, HIGH);
    pwm = -pwm;
  }
  ledcWrite(LEFT_FRONT_PWM, pwm);
}

// 左後車輪の制御
void backLeftMotor(double pwm)
{
  if (pwm >= 0)
  {
    digitalWrite(LEFT_BACK_IN1, HIGH);
    digitalWrite(LEFT_BACK_IN2, LOW);
  }
  else
  {
    digitalWrite(LEFT_BACK_IN1, LOW);
    digitalWrite(LEFT_BACK_IN2, HIGH);
    pwm = -pwm;
  }
  ledcWrite(LEFT_BACK_PWM, pwm);
}

// 右前車輪の制御
void frontRightMotor(double pwm)
{
  if (pwm >= 0)
  {
    digitalWrite(RIGHT_FRONT_IN1, HIGH);
    digitalWrite(RIGHT_FRONT_IN2, LOW);
  }
  else
  {
    digitalWrite(RIGHT_FRONT_IN1, LOW);
    digitalWrite(RIGHT_FRONT_IN2, HIGH);
    pwm = -pwm;
  }
  ledcWrite(RIGHT_FRONT_PWM, pwm);
}

// 右後車輪の制御
void backRightMotor(double pwm)
{
  if (pwm >= 0)
  {
    digitalWrite(RIGHT_BACK_IN1, HIGH);
    digitalWrite(RIGHT_BACK_IN2, LOW);
  }
  else
  {
    digitalWrite(RIGHT_BACK_IN1, LOW);
    digitalWrite(RIGHT_BACK_IN2, HIGH);
    pwm = -pwm;
  }
  ledcWrite(RIGHT_BACK_PWM, pwm);
}

void setup()
{
  init_pwm_setup();
  
  frontLeftMotor(0);
  backLeftMotor(0);
  frontRightMotor(0);
  backRightMotor(0);

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
      frontLeftMotor(200);
      backLeftMotor(-200);
      frontRightMotor(-200);
      backRightMotor(200);
      delay(100);
    }
    if (PS4.Down())
    {
      Serial.println("Down");
      frontLeftMotor(-200);
      backLeftMotor(-200);
      frontRightMotor(-200);
      backRightMotor(-200);
      delay(100);
    }
    if (PS4.Up())
    {
      Serial.println("Up");
      frontLeftMotor(200);
      backLeftMotor(200);
      frontRightMotor(200);
      backRightMotor(200);
      delay(100);
    }
    if (PS4.Left())
    {
      Serial.println("Left");
      frontLeftMotor(-200);
      backLeftMotor(200);
      frontRightMotor(200);
      backRightMotor(-200);
      delay(100);
    }

    if (PS4.UpRight())
    {
      Serial.println("Up Right");
      frontLeftMotor(200);
      backLeftMotor(0);
      frontRightMotor(0);
      backRightMotor(200);
      delay(100);
    }
    if (PS4.DownRight())
    {
      Serial.println("Down Right");
      frontLeftMotor(0);
      backLeftMotor(-200);
      frontRightMotor(-200);
      backRightMotor(0);
      delay(100);
    }
    if (PS4.UpLeft())
    {
      Serial.println("Up Left");
      frontLeftMotor(0);
      backLeftMotor(200);
      frontRightMotor(200);
      backRightMotor(0);
      delay(100);
    }
    if (PS4.DownLeft())
    {
      Serial.println("Down Left");
      frontLeftMotor(-200);
      backLeftMotor(0);
      frontRightMotor(0);
      backRightMotor(-200);
      delay(100);
    }

    frontLeftMotor(0);
    backLeftMotor(0);
    frontRightMotor(0);
    backRightMotor(0);
  }
}
