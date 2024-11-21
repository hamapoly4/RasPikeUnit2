#include "Scene.h"
#include <stdio.h>

Run* Scene::mRun[6] = {
	new RotateRun(RIGHT), new RotateRun(LEFT), new StraRun,
	new LineSearchRun, new LineTraceRun(RIGHT), new LineTraceRun(LEFT),
};

JudgeMent* Scene::mJudgeMent[16] = {
	new RotateAngleJudgeMent(RIGHT, 30), new RunDistJudgeMent(BOTH, 260),
	new ColorJudgeMent(BLACK), new RotateAngleJudgeMent(RIGHT, 13),
	new RunDistJudgeMent(RIGHT, 700), new RotateAngleJudgeMent(RIGHT, 26),
	new RunDistJudgeMent(BOTH, 1120), new ColorJudgeMent(BLACK),
	new RotateAngleJudgeMent(LEFT, 35), new RunDistJudgeMent(LEFT, 1500),
	new RotateAngleJudgeMent(LEFT, 15), new RunDistJudgeMent(BOTH, 560),
	new ColorJudgeMent(BLUE), new RotateAngleJudgeMent(RIGHT, 10),
	new ColorJudgeMent(BLACK), new RotateAngleJudgeMent(RIGHT, 50)
};

Scene::Scene(unsigned char scene_no)
	: mcurrent_scene_no(scene_no)
{
	printf("scene object is catch!!\n\n");
	// 各シーンに応じた走行オブジェクトをアクセスするための添字を設定
	switch (mcurrent_scene_no)
	{
		case  0:
		case  3:
		case  5:
		case 13:
		case 15:
			index_run = ROTATE_R;
			break;
		case  1:
		case  6:
		case 11:
			index_run = STRAIGHT;
			break;
		case  2:
		case  7:
		case 12:
		case 14:
			index_run = LINESEARCH;
			break;
		case  4:
			index_run = LINETRACE_R;
			break;
		case  8:
		case 10:
			index_run = ROTATE_L;
			break;
		case  9:
			index_run = LINETRACE_L;
			break;
		default:
			break;
	}
}

Scene::~Scene()
{
	static unsigned char s = 0;
	unsigned char i;
	if (s >= 15)
	{
		for (i = 0; i < 6; i++)
		{
			delete mRun[i];
		}
		
		for (i = 0; i < 16; i++)
		{
			delete mJudgeMent[i];
		}
	}
	s++;

	printf("シーン番号：%d シーンオブジェクトの解放！！\n\n", mcurrent_scene_no + 1);
}

void Scene::run()
{
	mRun[index_run]->run();
}

bool Scene::fin_judge()
{
	return mJudgeMent[mcurrent_scene_no]->judge();
}
