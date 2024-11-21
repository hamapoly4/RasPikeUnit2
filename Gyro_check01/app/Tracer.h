#include "Motor.h"       // <1>
#include "GyroSensor.h"
#include "Clock.h"
#include "ev3api.h"

class Tracer {  // <1>
public:
  Tracer();
  void run();       // <2>
  void terminate();

private:
  ev3api::Motor leftWheel;
  ev3api::Motor rightWheel;
  ev3api::GyroSensor gyroSensor;
  ev3api::Clock gClock;
  const int8_t mThreshold = 20;  // <4>
  const int8_t pwm = 45;

  rgb_raw_t rgb;
};
