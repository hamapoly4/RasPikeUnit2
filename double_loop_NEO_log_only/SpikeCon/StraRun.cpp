#include "StraRun.h"
#include <stdio.h>

StraRun::StraRun(int pwm)
	: Run(pwm)
{
	;
}

void StraRun::run()
{
	printf("Straight Run!!\n");
	printf("pwm is %d\n", mfix_pwm);
}
