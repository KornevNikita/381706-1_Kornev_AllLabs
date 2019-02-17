#include"RPN.h"
#include <iostream>

int main() 
{
  string str = "8/4";
  TQueue<char> q1(str.size());
  q1 = ToRPN(str);
  double a = Res(q1);
  cout << a;
  return 0;
}