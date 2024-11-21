#include "Tracer.h" // <1>
#include <stdio.h>

Tracer::Tracer():
  leftWheel(PORT_C), rightWheel(PORT_B), colorSensor(PORT_2),
  sonarSensor(PORT_3), gyroSensor(PORT_4) { // <2>
  }

void Tracer::terminate() {
  leftWheel.stop();  // <1>
  rightWheel.stop();
  printf("RasPike Stop!!\n");
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
  
/* 左右のモータの角位置に関する変数 */
  const float run_dist1 = 0.87266;
  int32_t leftwheel_count;
  int32_t rightwheel_count;
  static int32_t old_leftwheel_count;
  static int32_t old_rightwheel_count;
  static float l_sum;
  static float r_sum;
  float run_dist;

  leftwheel_count = leftWheel.getCount();     // 左モータの角位置を取得
  rightwheel_count = rightWheel.getCount();   // 右モータの角位置を取得
  l_sum += leftwheel_count - old_leftwheel_count;
  r_sum += rightwheel_count - old_rightwheel_count;
  run_dist = (l_sum + r_sum) * run_dist1 / 2.0;
  
  if (run_dist >= 1070)
  {
    printf("run_dist : %f\n", run_dist);
    terminate(); // 左右のモータの停止
    // leftWheel.setCount(leftwheel_count);
    // rightWheel.setCount(rightwheel_count);
    printf("leftwheel_count : %d\n", leftwheel_count);    //
    printf("rightwheel_count : %d\n", rightwheel_count);  // 角位置の観測値

    printf("leftWheel.getCount : %d\n", leftWheel.getCount());    //
    printf("rightWheel.getCount : %d\n", rightWheel.getCount());  // 角位置の実測値
    
    return true;
  }

  old_leftwheel_count = leftwheel_count;
  old_rightwheel_count = rightwheel_count;
  
  // RasPike run!!
  leftWheel.setPWM(pwm);
  rightWheel.setPWM(pwm);
  
  return false;
}
