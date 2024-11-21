#include "app.h" // <1>
#include "Tracer.h" // <2>
#include "Clock.h"  // <3>
#include "SonarSensor.h"

#include <stdio.h>

using namespace ev3api;

Tracer tracer;  // <4>
Clock clock;    // <5>
SonarSensor son(PORT_3);


void tracer_task(intptr_t exinf) { // <1
  FILE *fp;
  int16_t dist;
  static unsigned short i = 0;
    fp = fopen("Sonar_dt", "a");
    if (fp == NULL)
    {
      printf("Faile to open this file.\n");
    }
    else
    {
      if (i < 500)
      {
        i++;
      }
      else
      {
        i = 0;
        printf("Can detect.\n");
        dist = son.getDistance();
        fprintf(fp, "%d\n", dist);
      }
      fclose(fp);
    }

  ext_tsk();
}

void main_task(intptr_t unused) { // <1>
  const uint32_t duration = 100*1000; // <2>

  sta_cyc(TRACER_CYC); // <4>
  
  while (!ev3_button_is_pressed(LEFT_BUTTON)) { // <1>
      clock.sleep(duration);   // <2>
  }

  stp_cyc(TRACER_CYC); // <3>
  tracer.terminate(); // <4>
  ext_tsk(); // <5>
}
