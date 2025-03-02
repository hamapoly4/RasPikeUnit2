#include "Tracer.h" // <1>
#include <stdio.h>

Tracer::Tracer(HSVconv& hsvconv):
  leftWheel(PORT_C), rightWheel(PORT_B), gyroSensor(PORT_4), sonarSensor(PORT_3), mHSVconv(hsvconv) { // <2>
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
  const float Kd = 3;
  const int target = 0;
  static int old_diff = 0;
  int diff = 0;
  int D_value = 0;
  int P_value = 0;
  int turn = 0;
  
  int angle;
  
  int s;
  int v;

  // P control
  angle = gyroSensor.getAngle();
  diff = angle - target;
  P_value = Kp * diff;
  
  // D control
  D_value = (diff - old_diff) * Kd;
  
  // control sum
  turn = P_value + D_value;

  mHSVconv.calcHSV();
  s = mHSVconv.getS();
  if (60 <= s && s <= 87)
  {
    v = mHSVconv.getV();
    if (29 <= v && v <= 40)
    {
      printf("h : %d\n", mHSVconv.getH());
      printf("s : %d\n", s);
      printf("v : %d\n", v);
      return true;
    }
  }

  // RasPike run!!
  leftWheel.setPWM(pwm - turn);
  rightWheel.setPWM(pwm + turn);
  printf("turn : %d\n", turn);

  old_diff = diff;

  return false;
}

void Tracer::terminate() {
  leftWheel.stop();  // <1>
  rightWheel.stop();
}
