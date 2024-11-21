#ifndef ___CLASS_LINESEARCHRUN
#define ___CLASS_LINESEARCHRUN	// インクルードカード

#include "abstract_run.h"

class LineSearchRun : public Run {
public:
	LineSearchRun(int pwm = 35);

	void run();
};

#endif // ___CLASS_LINESEARCHRUN
