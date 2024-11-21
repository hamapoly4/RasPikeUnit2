#ifndef ___CLASS_ROTATEANGLEJUDGEMENT
#define ___CLASS_ROTATEANGLEJUDGEMENT

#include "JudgeMent.h"
#include "GyroSensor.h"

class RotateAngleJudgeMent : public JudgeMent {
private:
	enum { RIGHT, LEFT, };
	int mtarget_angle;
	int mcurrent_angle;
	unsigned char mrota;

	static GyroSensor* mGyroSensor;
public:
	RotateAngleJudgeMent(unsigned char rota, int angle);
	~RotateAngleJudgeMent();
	bool judge();
};

#endif // ___CLASS_ROTATEANGLEJUDGEMENT
