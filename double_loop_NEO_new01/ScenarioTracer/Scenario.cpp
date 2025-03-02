﻿#include "Scenario.h"
#include <stdio.h>

using namespace ev3api;

Scenario::Scenario(Scene* scene[])
	: state(INITIAL)
{
	int8_t i;
	for (i = 0; i < SIZE; i++)
	{
		mScene[i] = scene[i];
	}
}

Scenario::eState Scenario::getState()
{
	return state;
}

void Scenario::execute()
{
	switch (state)
	{
		case INITIAL:
			exeInitial();
			break;
		case EXE_SCENE:
			exeScene();
			break;
		case SWITCH_SCENE:
			switchScene();
			break;
		default:
			break;
	}
}

void Scenario::exeInitial()
{
	scene_no = 0;
	state = EXE_SCENE;
}

void Scenario::exeScene()
{
	bool flag;
	
	printf("execute Scene %d!!\n", scene_no + 1);
	mScene[scene_no]->run();

	flag = mScene[scene_no]->judge();

	if (flag == true)
	{
		printf("flag %d\n", flag);
		state = SWITCH_SCENE;
	}
}

void Scenario::switchScene()
{
	printf("Scene %d finish!\n\n", scene_no + 1);
	scene_no++;

	if (scene_no >= SIZE)
	{
		state = INITIAL;
	}
	else
	{
		state = EXE_SCENE;
	}
}
