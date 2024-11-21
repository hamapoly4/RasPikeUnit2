#include "Motor.h"       // <1>
#include "GyroSensor.h"
#include "ev3api.h"

using namespace ev3api;  // <4>

class Tracer {  // <1>
public:
  Tracer();
  void run();       // <2>
  void terminate();

private:
  Motor leftWheel;
  Motor rightWheel;
  GyroSensor gyroSensor;
  GyroSensor gyroSensor2;
  const int8_t mThreshold = 20;  // <4>
#ifndef MAKE_RASPIKE
  const int8_t pwm = (Motor::PWM_MAX) / 6;
#else
  const int8_t pwm = 45;
#endif

  rgb_raw_t rgb;
};
