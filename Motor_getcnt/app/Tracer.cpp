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
  static unsigned char flag = false;
  int32_t leftwheel_count;
  int32_t rightwheel_count;
  int16_t dist;
  dist = sonarSensor.getDistance();
  
  if (flag == false)
  {
    if (-1 < dist && dist < 5)
    {
      flag = true;
    }
    return;
  }
  
  leftwheel_count = leftWheel.getCount();
  rightwheel_count = rightWheel.getCount();
  if (leftwheel_count >= 360)
  {
    leftWheel.setCount(0);
  }
  
  if (rightwheel_count >= 360)
  {
    rightWheel.setCount(0);
  }
  
  printf("leftWheel.getCount : %d\n", leftwheel_count);
  printf("rightWheel.getCount : %d\n", rightwheel_count);
  
/*  const float Kp = 0.50;
  const float Ki = 0.03;
  const float Kd = 2;
  const int target = 38;
  const int bias = 0;
  static int old_diff = 0;
  static int i = 0;
  static int sum = 0;
  int diff = 0;
  int D_value = 0;
  int I_value = 0;
  int P_value = 0;
  int turn = 0;

  // P control
  diff = colorSensor.getBrightness() - target;
  P_value = Kp * diff;
  
  // I control
  sum += diff;
  I_value = sum * Ki;
  
  // D control
  D_value = (diff - old_diff) * Kd;
  
  // control sum
  turn = P_value + I_value + D_value;
  
  // RasPike run!!
  leftWheel.setPWM(pwm + turn);
  rightWheel.setPWM(pwm - turn);
  
  i++;
  if (i >= 10)
  {
    sum = 0;
    i = 0;
  }
  old_diff = diff;*/
}
