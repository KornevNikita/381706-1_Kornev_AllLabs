#include"ArrayList.h"

int main()
{
	TArrList<double> al1(5), al2(5);

	al1.PutStart(1);
	al1.PutEnd(5);
	al1.Put(1, 5);
	al1.Put(2, 5);
	al1.Put(3, 5);
	double a = al1.Get(1);
	cout << a;
	TArrList<double> al3(al1);
	al2.PutEnd(1);
	al2.PutStart(2);
	al2.Put(1, 5);
	double b = al2.GetEnd();
	cout << b;
	double c = al2.GetStart();
	return 0;
}