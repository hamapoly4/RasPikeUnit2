#include "LineTraceRun.h"
#include <stdio.h>

LineTraceRun::LineTraceRun(unsigned char edge, int pwm)
	: medge(edge), Run(pwm)
{
	;
}

void LineTraceRun::run()
{
	if (medge == RIGHT)
	{
		printf("Right Edge ");
	}
	else if (medge == LEFT)
	{
		printf("Left Edge ");
	}
	printf("LineTrace Run!!\n");
	printf("pwm is %d\n", mfix_pwm);

}
