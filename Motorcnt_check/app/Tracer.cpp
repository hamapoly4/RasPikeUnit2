#include "Tracer.h" // <1>
#include <stdio.h>

Tracer::Tracer():
  leftWheel(PORT_C), rightWheel(PORT_B), gyroSensor(PORT_4) { // <2>
}

void Tracer::terminate() {
  leftWheel.stop();  // <1>
  rightWheel.stop();
}

void Tracer::run() {
  printf("leftWheel_cnt  : %d\n", leftWheel.getCount());
  printf("rightWheel_cnt : %d\n", rightWheel.getCount());
  printf("\n");
}
