#include "Tracer.h" // <1>
#include <stdio.h>

Tracer::Tracer():
  leftWheel(PORT_C), rightWheel(PORT_B), colorSensor(PORT_2), sonarSensor(PORT_3) { // <2>
  }

void Tracer::terminate() {
  leftWheel.stop();  // <1>
  rightWheel.stop();
}

void Tracer::run() {
  static bool flag = false;
  int16_t dist;

  printf("leftWheel.getCount  : %d\n", leftWheel.getCount());
  printf("rightWheel.getCount : %d\n", rightWheel.getCount());
  
  if (ev3_button_is_pressed(ENTER_BUTTON))
  {
    flag = true;
  }
  else
  {
    if (flag == true)
    {
      flag = false;
      printf("reset!!!!!!!!!!!!!!!!!!!!!!!!\n");
      leftWheel.setCount(0);
      rightWheel.setCount(0);
    }
  }
}
