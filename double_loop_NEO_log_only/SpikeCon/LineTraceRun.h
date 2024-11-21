#ifndef ___CLASS_LINETRACERUN
#define ___CLASS_LINETRACERUN	// インクルードカード

#include "abstract_run.h"

class LineTraceRun : public Run {
private:
	enum EDGE { RIGHT, LEFT, };
	unsigned char medge;

public:
	LineTraceRun(unsigned char edge, int pwm = 40);

	void run();
};

#endif // ___CLASS_LINETRACERUN
