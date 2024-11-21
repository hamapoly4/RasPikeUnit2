#include "ColorJudgeMent.h"
#include <stdio.h>

ColorJudgeMent::ColorJudgeMent(unsigned char color)
	: mtarget_color(color)
{
	;
}

bool ColorJudgeMent::judge()
{
	mcurrent_color = mtarget_color;

	if (mcurrent_color == mtarget_color)
	{
		return true;
	}

	return false;
}
