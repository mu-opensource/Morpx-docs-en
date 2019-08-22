#include <MoonBot.h>

// connect ir sensor 1 on port 1
uint8_t ir1[2] = {
    moonbotPortToPin(kPort1, kPortPin1),
    moonbotPortToPin(kPort1, kPortPin2)
};
// connect ir sensor 1 on port 1
uint8_t ir2[2] = {
    moonbotPortToPin(kPort2, kPortPin1),
    moonbotPortToPin(kPort2, kPortPin2)
};

void setup()
{
  // initialize ir sensor 1/2 as INPUT_PULLUP
  pinMode(ir1[0], INPUT);
  pinMode(ir1[1], INPUT);
  pinMode(ir2[0], INPUT);
  pinMode(ir2[1], INPUT);
}

void loop()
{
  Serial.println("=======================");
  Serial.print("ir sensor1: ");
  // read ir sensor 1 state
  if (!digitalRead(ir1[0]) || !digitalRead(ir1[1])) {
    Serial.println("triggered");
  } else {
    Serial.println("not triggered");
  }
  Serial.print("ir sensor2: ");
  // read ir sensor 2 state
  if (!digitalRead(ir2[0]) || !digitalRead(ir2[1])) {
    Serial.println("triggered");
  } else {
    Serial.println("not triggered");
  }
}
