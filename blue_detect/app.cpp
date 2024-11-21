#include "app.h" // <1>
#include "Tracer.h" // <2>
#include "Clock.h"  // <3>
#include "SonarSensor.h"

using namespace ev3api;

Tracer tracer;  // <4>
Clock clock;    // <5>
SonarSensor sonarSensor(PORT_3);

void tracer_task(intptr_t exinf) { // <1>
  tracer.run(); // <2>
  ext_tsk();
}

void main_task(intptr_t unused) { // <1>
  const uint32_t duration = 100*1000; // <2>
  static unsigned char flag = 0;
  
  while (1)
  {
    if (sonarSensor.listen() == true)
    {
      flag = 1;
    }
    
    if (flag == 1)
    {
      break;
    }
  }

  tracer.init(); // <3>
  sta_cyc(TRACER_CYC); // <4>
  
  while (!ev3_button_is_pressed(LEFT_BUTTON)) { // <1>
      clock.sleep(duration);   // <2>
  }

  stp_cyc(TRACER_CYC); // <3>
  tracer.terminate(); // <4>
  ext_tsk(); // <5>
}
