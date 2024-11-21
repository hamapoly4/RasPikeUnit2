#include "Tracer.h" // <1>
#include <stdio.h>

Tracer::Tracer():
  leftWheel(PORT_C), rightWheel(PORT_B), gyroSensor(PORT_4), gClock() { // <2>
}

void Tracer::terminate() {
  leftWheel.stop();  // <1>
  rightWheel.stop();
}

void Tracer::run() {
  FILE* fp = NULL;
  uint64_t time;
  int16_t angle;
  int16_t agl_vel;

  time = 4;
  angle = gyroSensor.getAngle();
  agl_vel = gyroSensor.getAnglerVelocity();
  
  printf("time    : %d\n", gClock.now());
  printf("angle   : %d\n", angle);
  printf("agl_vel : %d\n\n", agl_vel);

  fp = fopen("angle_check", "a");
  
  if (fp == NULL)
  {
    ;
  }
  else
  {
    if (agl_vel != 0)
    {
      fprintf(fp, "AnglerVelocity : %d, time : %d\n", agl_vel, time);
    }
  }
  
  fclose(fp);
}
