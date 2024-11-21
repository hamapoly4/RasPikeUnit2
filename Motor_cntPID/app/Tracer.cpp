#include "Tracer.h" // <1>
#include <stdio.h>

Tracer::Tracer():
  leftWheel(PORT_C), rightWheel(PORT_B), sonarSensor(PORT_3) { // <2>
}

bool Tracer::run() {
  static unsigned char flag = false;
  int16_t dist;
  dist = sonarSensor.getDistance();
  
  if (-1 < dist && dist < 5)
  {
    flag = true;
    return false;
  }
  
  if (flag == false)
  {
    return false;
  }
  
  const float Kp = 1.5;
  const float Ki = 0.05;
  const float Kd = 2;
  const int target = 0;
  static int old_diff = 0;
  static int i = 0;
  static int sum = 0;
  int diff = 0;
  int D_value = 0;
  int I_value = 0;
  int P_value = 0;
  int turn = 0;
  
  const int dist_target = 2800;
  const float KP = 0.0125;
  const float angle1dist = 0.87266;
  
  int run_dist = 0;
  int PWM = 0;
  
  /* Motor PID value */
  int left_cnt = 0;
  int right_cnt = 0;
  int cnt_diff = 0;
  
  left_cnt = leftWheel.getCount();
  right_cnt = rightWheel.getCount();
  cnt_diff = right_cnt - left_cnt;

  // P control
  diff = cnt_diff - target;
  P_value = Kp * diff;
  
  // I control
  sum += diff;
  I_value = sum * Ki;
  
  // D control
  D_value = (diff - old_diff) * Kd;
  
  // control sum
  turn = P_value + I_value + D_value;
  
  run_dist = (left_cnt + right_cnt) / 2 * angle1dist;
  if (run_dist >= dist_target)
  {
    return true;
  }
  
  PWM = pwm + KP * (dist_target - run_dist);
  
  // RasPike run!!
  leftWheel.setPWM(pwm + turn);
  rightWheel.setPWM(pwm - turn);
  
  i++;
  if (i >= 10)
  {
    sum = 0;
    i = 0;
  }
  old_diff = diff;
  
  return false;
}

void Tracer::terminate() {
  leftWheel.stop();  // <1>
  rightWheel.stop();
}
