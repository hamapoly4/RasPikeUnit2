#include "Tracer.h" // <1>
#include <stdio.h>

Tracer::Tracer()
  : mGyroSensor(PORT_4)
{
  ;
}

void Tracer::run()
{
  static float angle = 0;
  static int num = 0;
  static int i = 0;
  int raw;

  raw = mGyroSensor.getAngle();
  printf("angle : %d\n", raw);
  //angle += raw * 0.01;

  i++;
  if (i >= 100)
  {
    mGyroSensor.reset();
    num++;
    printf("%d gyro is reset!!\n\n\n", num);
    i = 0;
  }
}
