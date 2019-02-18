#include "Polinom.h"

int  main ()
{
	int a[] = { 1, 2, 3 };
	int b[] = { 4, 5, 6 };


	TMonom A(3, a, 7);
	TMonom B(3, b, 8);


	cout << A << endl;
	cout << B << endl;

	TPolinom P1(3);
	P1 += A;
	P1 += B;
	cout << "P1:" << P1 << endl;
	return 0;
}