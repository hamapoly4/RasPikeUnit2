#include "Tracer.h" // <1>
#include <stdio.h>

Tracer::Tracer():
  leftWheel(PORT_C), rightWheel(PORT_B), colorSensor(PORT_2) { // <2>
}

void Tracer::terminate() {
  leftWheel.stop();  // <1>
  rightWheel.stop();
}

void Tracer::run() {
  colorSensor.getRawColor(rgb);
  
  printf("red   : %d\n", rgb.r);
  printf("green : %d\n", rgb.b);
  printf("blue  : %d\n", rgb.g);
  printf("\n");
}
