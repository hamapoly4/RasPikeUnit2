#ifndef ___CLASS_STRARUN
#define ___CLASS_STRARUN	// インクルードカード

#include "abstract_run.h"

class StraRun : public Run {
public:
	StraRun(int pwm = 70);

	void run();
};

#endif // ___CLASS_STRARUN
