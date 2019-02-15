#include"RPN.h"
#include <iostream>

int main() 
{
  string str = "1+1+1+1+1+1";
  TQueue<char> q1(str.size());
  q1 = ToRPN(str);
  for (int i = 0; i < (str.size() - 3); i++)
	cout << "i =" <<i<< " " << q1.Get()<< endl;
  return 0;
}