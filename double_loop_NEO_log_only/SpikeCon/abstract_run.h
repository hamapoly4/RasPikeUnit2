/*--------------------------------------------
 *	FILE NAME : abstract_run
 *	FILE TYPE : Header File
 *	AUTHOR    : Yuta Kondo
 * 	SUMMARY   : Abstract Class &
 *		    Sub Class
 *--------------------------------------------*/

#ifndef ___ABSTRACT_CLASS
#define ___ABSTRACT_CLASS	// インクルードカード

#include <stdio.h>

class Run {
protected:
	int mfix_pwm;
	Run(int pwm);
public:
	virtual void run() = 0;
};

#endif // ___ABSTRACT_CLASS
