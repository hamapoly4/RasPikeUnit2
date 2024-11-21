#ifndef ___CLASS_ROTATERUN
#define ___CLASS_ROTATERUN	// インクルードカード

#include "abstract_run.h"

class RotateRun : public Run {
private:
	enum ROTA { RIGHT, LEFT, };
	unsigned char mdire;

public:
	RotateRun(unsigned char dire, int pwm = 35);

	void run();
};

#endif // ___CLASS_ROTATERUN
