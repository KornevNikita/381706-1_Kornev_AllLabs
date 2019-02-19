#include "RPN.h"

int  main()
{
  try
  {
    TString s("1+2+3+4+5+6+7+8+9+10");
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
