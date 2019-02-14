#include "PN.h"
int main()
{
	char* A = new char[3];
	A[0] = '3';
	A[1] = '+';
	A[2] = '3';
	PN B(3, A);
	B.Print();
	double temp = B.Result();
	cout << temp << endl << "Опа";
	return 0;
}
