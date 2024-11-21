#include "Scenario.h"
#include <stdio.h>

Scene* Scenario::mScene[16] = {
	new Scene(0), new Scene(1), new Scene(2), new Scene(3), 
	new Scene(4), new Scene(5), new Scene(6), new Scene(7), 
	new Scene(8), new Scene(9), new Scene(10), new Scene(11), 
	new Scene(12), new Scene(13), new Scene(14), new Scene(15), 
};

Scenario::Scenario()
	: mscene_no(TOP), mscene_switch_flag(false), mscenario_fin_flag(false)
{
	;
}

Scenario::~Scenario()
{
	unsigned char i;
	for (i = 0; i < 16; i++)
	{
		delete mScene[i];
		printf("%d番のシーンオブジェクトを解放した！！！！！！！！！！！！！！！！！！！\n", i + 1);
	}

	printf("シナリオオブジェクトの解放！！\n");
}

void Scenario::run()
{
	mScene[mscene_no]->run();
	mscene_switch_flag = mScene[mscene_no]->fin_judge();
	switch_scene();
}

void Scenario::switch_scene()
{
	if (mscene_no >= LAST)
	{
		mscenario_fin_flag = true;
	}
	else if (mscene_switch_flag == true)
	{
		mscene_no++;
		mscene_switch_flag = false;
	}
}

bool Scenario::finish()
{
	return mscenario_fin_flag;
}
