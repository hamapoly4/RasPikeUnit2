#include "Tracer.h" // <1>
#include <stdio.h>

Tracer::Tracer():
  leftWheel(PORT_C), rightWheel(PORT_B), gyroSensor(PORT_4), gyroSensor2(PORT_4) { // <2>
}

void Tracer::terminate() {
  leftWheel.stop();  // <1>
  rightWheel.stop();
}

void Tracer::run() {
  static bool flag = false;

  printf("angle : %d\n", gyroSensor.getAngle());

  if (ev3_button_is_pressed(ENTER_BUTTON)) {
      flag = true;
  }
  else {
      if (flag == true)
      {
        flag = false;
        gyroSensor2.reset();
        printf("reset!!\n");
      }
  }
}
