#include "RotateAngleJudgeMent.h"
#include <stdio.h>

GyroSensor* RotateAngleJudgeMent::mGyroSensor = new GyroSensor(0);

RotateAngleJudgeMent::RotateAngleJudgeMent(unsigned char rota, int angle)
	: mrota(rota), mtarget_angle(angle)
{
	;
}

RotateAngleJudgeMent::~RotateAngleJudgeMent()
{
	static unsigned char i = 1;
	if (i >= 7)
	{
		delete mGyroSensor;
	}
	
	i++;
}

bool RotateAngleJudgeMent::judge()
{
	mcurrent_angle = mGyroSensor->getAngle();

	if (mrota == RIGHT)
	{
		printf("右旋回角度：%d度\n", mcurrent_angle);
		printf("　旋回角度：%d度\n", mtarget_angle);
		return true;
	}
	else if (mrota == LEFT)
	{
		printf("左旋回角度：%d度\n", mcurrent_angle);
		printf("　旋回角度：%d度\n", mtarget_angle);
		return true;
	}

	return false;
}
