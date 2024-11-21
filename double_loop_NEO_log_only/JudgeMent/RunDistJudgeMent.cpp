#include "RunDistJudgeMent.h"
#include <stdio.h>

RunDistJudgeMent::RunDistJudgeMent(unsigned char tire, float dist)
	: mtire(tire), mtarget_dist(dist)
{
	;
}

bool RunDistJudgeMent::judge()
{
	mcurrent_dist = mtarget_dist;

	if (mcurrent_dist >= mtarget_dist)
	{
		printf("%fmm走った！！\n", mcurrent_dist);
		return true;
	}

	return false;
}
