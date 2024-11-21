#ifndef EV3_APP_RUN_H_
#define EV3_APP_RUN_H_

#include "Runner.h"

class Run {
private:
	Runner* mRunner;
public:
	Run(Runner* runner);
	~Run();
	void run();
};

#endif  // EV3_APP_RUN_H_
