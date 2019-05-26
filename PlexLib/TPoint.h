#pragma once
#include <iostream>

using namespace std;


class TPoint
{
protected:
	double x, y;

public:
	void SetX(double _x);
	void SetY(double _y);
	double GetX();
	double GetY();

	TPoint(double _x = 0, double _y = 0);
	TPoint(TPoint &A);
	virtual void show();

	bool operator == (TPoint &A);
	TPoint& operator = (TPoint &A);
};