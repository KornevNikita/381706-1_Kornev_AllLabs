#pragma once
#include "Monom.h"

class TPolinom
{
protected:
	TMonom *a;
	int n,
		size;
public:
	TPolinom(int _n = 1);
	TPolinom(const TPolinom &A);
	~TPolinom();
	int GetSize();
	TMonom* GetStart();
	TPolinom operator +(TPolinom &A);
	TPolinom operator *(TPolinom &A);
	TPolinom& operator =(const TPolinom &A);
	TPolinom& operator +=(TMonom &A);
	bool operator==(const TPolinom &A);
	friend ostream& operator<<(ostream& ostr, TPolinom& A);
};

