#include "LineSearchRun.h"
#include <stdio.h>

LineSearchRun::LineSearchRun(int pwm)
	: Run(pwm)
{
	;
}

void LineSearchRun::run()
{
	printf("LineSearch Run!!\n");
	printf("pwm is %d\n", mfix_pwm);
}
