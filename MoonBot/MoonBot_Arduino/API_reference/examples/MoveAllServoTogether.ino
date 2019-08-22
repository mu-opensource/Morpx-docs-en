#include <MoonBot.h>

void setup() {
  for (int i = 0; i < kServoNum; ++i) {
    m_servo[i].attach((moonbot_servo_t)i);  // attaches servo
  }
}
void loop() {
  // in steps of 1 degree
  for (int i = 0; i < kServoNum; ++i) {
    m_servo[i].setTargetAngle(180, 1);      // set all servo to go to position in variable '180', speed 1 degree per pulse(20ms)
  }
  MoonBotServo::moveAllServoToTarget();     // move all servo to target angle
  for (int i = 0; i < kServoNum; ++i) {
    m_servo[i].setTargetAngle(0, 1);        // set all servo to go to position in variable '0', speed 1 degree per pulse(20ms)
  }
  MoonBotServo::moveAllServoToTarget();     // move all servo to target angle
}

