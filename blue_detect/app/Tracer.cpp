#include "Tracer.h" // <1>

Tracer::Tracer():
  leftWheel(PORT_C), rightWheel(PORT_B), colorSensor(PORT_2) { // <2>
}

void Tracer::init() {
  init_f("Tracer");
}

void Tracer::terminate() {
  msg_f("Stopped.", 1);
  leftWheel.stop();  // <1>
  rightWheel.stop();
}

void Tracer::run() {        // right edge
  msg_f("running...", 1);
  if(colorSensor.getBrightness() >= mThreshold) { // <1>
    // white
    leftWheel.setPWM(0);
    rightWheel.setPWM(pwm);   // counterclockwise
  } else {   // <2>
    // black
    leftWheel.setPWM(pwm);
    rightWheel.setPWM(0);     //        clockwise
  }
}
