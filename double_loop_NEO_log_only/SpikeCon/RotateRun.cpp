#include "RotateRun.h"
#include <stdio.h>

RotateRun::RotateRun(unsigned char dire, int pwm)
	: mdire(dire), Run(pwm)
{
	;
}

void RotateRun::run()
{
	if (mdire == RIGHT)
	{
		printf("Right ");
	}
	else if (mdire == LEFT)
	{
		printf("Left ");
	}
	printf("Rotation Run!!\n");
	printf("pwm is %d\n", mfix_pwm);
}
