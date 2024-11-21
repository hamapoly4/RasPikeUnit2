#include "Tracer.h" // <1>
#include <stdio.h>

Tracer::Tracer():
  leftWheel(PORT_C), rightWheel(PORT_B), gyroSensor(PORT_4)
{ // <2>
    ;
}

void Tracer::terminate() {
  leftWheel.stop();  // <1>
  rightWheel.stop();
  printf("RasPike Stop!!\n");
}

bool Tracer::run() {
  const float pgain = 0.2;
  const int target = 90;
  int turn;
  int angle;

  angle = gyroSensor.getAngle();
  if (angle >= 90)
  {
    printf("RasPike Rotate %d degree(Measured Value)\n", angle);
    printf("RasPike Rotate 90 degree(Theoretical Value)\n");
    return true;
  }
  
  turn = (target - angle) * pgain;
  printf("turn : %d\n", turn);
  
  // RasPike run!!
  leftWheel.setPWM(pwm + turn);
  rightWheel.setPWM(-pwm - turn);

  return false;
}
