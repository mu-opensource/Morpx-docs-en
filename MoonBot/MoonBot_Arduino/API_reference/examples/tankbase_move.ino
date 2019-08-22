#include <MoonBot.h>

void setup()
{
  TankBase.begin();   // enable TankBase, use default setting
}

void loop()
{
  // forward 1s
  TankBase.write(100, 100);
  delay(1000);
  // backward 1s
  TankBase.write(-100, -100);
  delay(1000);
  // turn right 1s
  TankBase.write(100, -100);
  delay(1000);
  // turn left 1s
  TankBase.write(-100, 100);
  delay(1000);
}
