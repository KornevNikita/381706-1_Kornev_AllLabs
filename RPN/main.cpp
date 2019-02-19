#include "RPN.h"

int  main()
{
  try
  {
    TString s;
    cin >> s;
    TQueue<char> B;
    B = ToRPN(s);
    cout << " = " << Result(B) << endl;
  }
  
  catch (MyException exp)
  {
    exp.Print();
  }
  return 0;
}
