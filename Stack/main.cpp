#include <iostream>
#include <locale.h>
#include "Stack.h"

using namespace std;

int  main (){
	TStack<int> st(10);
	cout << "IsEmpty:" << st.IsEmpty() << endl;
	st.Put(4);
	st.Put(5);
	cout <<"IsFull:"<< st.IsFull()<<endl;
	cout <<"Get1:"<< st.Get()<<endl;
	cout << "IsEmpty:" << st.IsEmpty() << endl;
	cout << "Get1:" << st.Get() << endl;
	cout << "IsEmpty:" << st.IsEmpty() << endl;

	return 0;
}