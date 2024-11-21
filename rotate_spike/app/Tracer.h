#include "Motor.h"       // <1>
#include "GyroSensor.h"

using namespace ev3api;  // <4>

class Tracer {  // <1>
public:
  Tracer();
  bool run();       // <2>
  void terminate();

private:
  Motor leftWheel;
  Motor rightWheel;
  GyroSensor gyroSensor;
  const int pwm = 35;

};
