#ifndef ___CLASS_SCENE
#define ___CLASS_SCENE

#include "abstract_run.h"	// 抽象クラスのヘッダ（走行）
#include "RotateRun.h"		//
#include "StraRun.h"		//
#include "LineSearchRun.h"	//
#include "LineTraceRun.h"	// 派生クラス

#include "JudgeMent.h"				// 抽象クラスのヘッダ（判定）
#include "RotateAngleJudgeMent.h"	//
#include "RunDistJudgeMent.h"		//
#include "ColorJudgeMent.h"			// 派生クラス

class Scene {
private:
	enum eRun {
		ROTATE_R,   ROTATE_L,    STRAIGHT,
		LINESEARCH, LINETRACE_R, LINETRACE_L,
	};

	enum eWhich { RIGHT, LEFT, BOTH, };

	enum eColor { BLACK, BLUE, };

	static Run* mRun[6];
	static JudgeMent* mJudgeMent[16];

	unsigned char mcurrent_scene_no;
	unsigned char index_run;

public:
	Scene(unsigned char scene_no);
	~Scene();
	void run();
	bool fin_judge();
};

#endif // ___CLASS_SCENE