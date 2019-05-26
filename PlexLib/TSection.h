#pragma once
#include "TPoint.h"

class TSection
{
protected:
	TPoint A, B;

public:
	TSection(TPoint _A, TPoint _B);
	TSection(TSection &S);
	void SetA(TPoint _A);
	void SetB(TPoint _B);
	TPoint GetA();
	TPoint GetB();
	virtual void show();
};

