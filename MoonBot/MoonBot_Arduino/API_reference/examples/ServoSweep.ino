#include <MoonBot.h>

int pos;

void setup() {
    m_servo[kServo1].attach(kServo1, true);          // attaches servo on servo port 1, and reverse directions
}
void loop() {
  for (pos = 0; pos <= 180; pos += 1) {     // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    m_servo[kServo1].write(pos);                     // tell servo to go to position in variable 'pos'
    delay(15);                              // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) {     // goes from 180 degrees to 0 degrees
    m_servo[kServo1].write(pos);                     // tell servo to go to position in variable 'pos'
    delay(15);                              // waits 15ms for the servo to reach the position
  }
}

