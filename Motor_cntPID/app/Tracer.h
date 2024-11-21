#include "Motor.h"       // <1>
#include "SonarSensor.h"

using namespace ev3api;  // <4>

class Tracer {  // <1>
public:
  Tracer();
  bool run();       // <2>
  void terminate();

private:
  Motor leftWheel;
  Motor rightWheel;
  SonarSensor sonarSensor;
  const int8_t pwm = 35;
};
