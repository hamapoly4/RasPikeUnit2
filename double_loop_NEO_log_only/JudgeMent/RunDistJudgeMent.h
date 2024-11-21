#ifndef ___CLASS_RUNDISTJUDGEMENT
#define ___CLASS_RUNDISTJUDGEMENT

#include "JudgeMent.h"

class RunDistJudgeMent : public JudgeMent {
private:
	enum TIRE { RIGHT, LEFT, BOTH, };
	float mtarget_dist;
	float mcurrent_dist;
	unsigned char mtire;
public:
	RunDistJudgeMent(unsigned char tire, float dist);
	bool judge();
};

#endif // ___CLASS_RUNDISTJUDGEMENT