#include "Run.h"

#include "ColorSensor.h"
#include "SonarSensor.h"
#include "GyroSensor.h"
#include "Motor.h"
ColorSensor gColorSensor(PORT_2);
SonarSensor gSonarSensor(PORT_3);
GyroSensor  gGyroSensor(PORT_4);
Motor       gLeftWheel(PORT_C);
Motor       gRightWheel(PORT_B);

CalcPID gCalcPID(gColorSensor);
LineTracer gLineTracer(gLeftWheel, gRightWheel);

Run::Run(Runner* runner)
	: mRunner(runner)
{
	mRunner = Runner(gSonarSensor, gGyroSensor, gCalcPID, gLineTracer);
}

Run::~Run()
{
	delete mRunner;
}

void Run::run()
{
	mRunner->runL();
}
