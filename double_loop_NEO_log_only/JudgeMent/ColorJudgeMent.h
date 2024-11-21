#ifndef ___CLASS_COLORJUDGEMENT
#define ___CLASS_COLORJUDGEMENT

#include "JudgeMent.h"

class ColorJudgeMent : public JudgeMent {
private:
	enum eColor { BLACK, BLUE };

	unsigned char mtarget_color;
	unsigned char mcurrent_color;
public:
	ColorJudgeMent(unsigned char color);
	bool judge();
};

#endif // ___CLASS_COLORJUDGEMENT