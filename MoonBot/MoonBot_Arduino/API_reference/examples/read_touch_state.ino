#include <MoonBot.h>

// connect touch sensor 1 on port 1
uint8_t touch1 = moonbotPortToPin(kPort1, kPortPin1);
// connect touch sensor 2 on port 2
uint8_t touch2 = moonbotPortToPin(kPort2, kPortPin1);

void setup()
{
  // initialize touch sensor 1/2 as INPUT_PULLUP
  pinMode(touch1, INPUT);
  pinMode(touch2, INPUT);
}

void loop()
{
  Serial.println("=======================");
  Serial.print("touch sensor1: ");
  // read touch sensor 1 state
  if (digitalRead(touch1)) {
    Serial.println("on touch");
  } else {
    Serial.println("not touch");
  }
  Serial.print("touch sensor2: ");
  // read touch sensor 2 state
  if (digitalRead(touch2)) {
    Serial.println("on touch");
  } else {
    Serial.println("not touch");
  }
}
