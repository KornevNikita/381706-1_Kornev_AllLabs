#include <iostream>
#include"Queue.h"
using namespace std;

int main ()
{  
	TQueue<int> test1(10);
	test1.Put(43);
	test1.Put(42);
	test1.Put(41);
	double a = test1.GetSize();
	cout << "Get1:" << test1.Get() << endl;
	cout << "Get2:" << test1.Get() << endl;

	return 0;
}