#pragma once
#include <iostream>
#include "Monom.h"

using namespace std;

class TPolinom 
{
protected:
  TMonom *a;
  int n,
    size;
public:
  TPolinom(int _n = 10);
  TPolinom(const TPolinom &A);
	~TPolinom();
	int GetSize();
	TMonom* GetStart();
  TPolinom operator +(TPolinom &A);
  TPolinom operator *(TPolinom &A);
  TPolinom& operator =(const TPolinom &A);
  TPolinom& operator +=(TMonom &A);
	bool operator==(const TPolinom &A);
};
