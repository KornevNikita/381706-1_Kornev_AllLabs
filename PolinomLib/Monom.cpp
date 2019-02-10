#include <iostream>
#include "Monom.h"

using namespace std;


TMonom::TMonom(int _n)
{
	if (_n < 0)
		throw "Negative";
	else if (_n == 0)
	{
		n = _n;
		next = 0;
		power = 0;
		c = 0;
	}
	if (_n > 0)
	{
		n = _n;
		next = 0;
		power = new int[n];
		c = 0;
	}
}

TMonom::TMonom(int _n, int* _power, double _c)
{
	if (_n < 0)
		throw - 1;
	else if (_n == 0)
	{
		power = 0;
		n = _n;
		c = _c;
		next = 0;
	}
	else
	{
		n = _n;
		c = _c;
		next = 0;
		power = new int[_n];
		for (int i = 0; i < _n; i++)
		{
			if (_power[i] >= 0)
				power[i] = _power[i];
			else
				throw "Negative";
		}
	}
}

TMonom::TMonom(const TMonom &A)
{
	n = A.n;
	c = A.c;
	next = A.next;
	power = new int[n];
	for (int i = 0; i < n; i++)
	{
		power[i] = A.power[i];
	}
}

TMonom::~TMonom()
{
	if (power != 0)
		delete[]power;
	n = 0;
	c = 0;
	next = 0;
}

TMonom* TMonom::GetNext()
{
	return next;
}

int* TMonom::GetPower()
{
	return power;
}

double TMonom::GetC()
{
	return c;
}
const int TMonom::GetN()
{
	return n;
}

void TMonom::SetNext(TMonom* _next)
{
	next = _next;
}

void TMonom::SetPower(int* _power)
{
	for (int i = 0; i < n; i++)
	{
		if (_power[i] >= 0)
			power[i] = _power[i];
		else
			throw "Negative";
	}
}


void TMonom::SetC(double _c)
{
	c = _c;
}

void TMonom::SetN(int _n)
{
	if (_n < 0)
		throw "Negative";
	else if (_n == 0)
	{
		if (power != 0)
			delete[] power;
		power = 0;
		n = 0;
	}
	else
	{
		int *tmp = new int[n];
		for (int i = 0; i < n; i++)
			tmp[i] = power[i];
		delete[]power;
		power = new int[_n];
		if (n < _n)
		{
			for (int i = 0; i < n; i++)
				power[i] = tmp[i];
			for (int i = n; i < _n; i++)
				power[i] = 0;
		}
		if (_n < n)
			for (int i = n; i < _n; i++)
				power[i] = tmp[i];
		n = _n;
	}
}


TMonom& TMonom::operator =(const TMonom& A)
{
	if (n != A.n)
		throw "Different n";
	c = A.c;
	n = A.n;
	next = A.next;
	delete[] power;
	power = new int[n];
	for (int i = 0; i < n; i++)
		power[i] = A.power[i];
	return *this;
}

TMonom TMonom::operator +(TMonom& A)
{
	TMonom tmp(A);
	if (n != A.n)
		throw "Different n";
	else
	{
		for (int i = 0; i < n; i++)
			if (power[i] != A.power[i])
				throw "Different power";
		tmp.c = c + A.c;
		return tmp;
	}
}

TMonom TMonom::operator -(TMonom& A)
{
	TMonom tmp(A);
	if (n != A.n)
		throw "Different n";
	else
	{
		for (int i = 0; i < n; i++)
			if (power[i] != A.power[i])
				throw "Different power";
		tmp.c = c - A.c;
		return tmp;
	}
}

TMonom TMonom::operator *(TMonom& A)
{
	if (n != A.n)
		throw "NE";
	TMonom tmp(A);
	tmp.c = c * A.c;
	for (int i = 0; i < n; i++)
		tmp.power[i] = power[i] + A.power[i];
	return tmp;
}

bool TMonom::operator ==(const TMonom& A)
{
	if (n != A.n)
	{
		throw "Different size";
	}
	for (int i = 0; i < n; i++)
	{
		if (power[i] != A.power[i])
			return false;
	}
	if (c != A.c)
		return false;
	return true;
}

bool TMonom::operator >(TMonom& A)
{
	if (n != A.n)
		throw "Different n";
	for (int i = 0; i < n; i++)
	{
		if (power[i] == A.power[i])
			continue;
		else if (power[i] > A.power[i])
			return true;
		else
			return false;
		if (c < A.c)
			return false;
	}
	return true;
}

bool TMonom::operator <(TMonom& A)
{
	if (n != A.n)
		throw "Different n";
	for (int i = 0; i < n; i++)
	{
		if (power[i] == A.power[i])
			continue;
		else if (power[i] < A.power[i])
			return true;
		else
			return false;
		if (c > A.c)
			return false;
	}
	return true;
}

istream& operator >> (istream& istr, TMonom& A)
{
	cout << "input c:\n" << endl;
	istr >> A.c;
	cout << "input power: \n" << endl;
	for (int i = 0; i < A.n; i++)
		istr >> A.power[i];

	return istr;
}

ostream& operator << (ostream& ostr, TMonom& A)
{
	ostr << A.c;
	if (A.c != 0)
	{
		for (int i = 0; i < A.n; i++)
			if (A.power[i] != 0)
			{
				ostr << "x" << i;
				if (A.power[i] != 1)
					ostr << "^" << A.power[i] << " ";
			}
	}
	return ostr;
}