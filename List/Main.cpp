#include <iostream>
#include <locale.h>
#include "List.h"

using namespace std;

int  main (){	

  TElem<int> test0(0,0);

  TList<int> test1;

  test0.Set(43);

  test1.PutBegin(41);
  test1.PutBegin(42);
  test1.PutBegin(43);
  test1.PutEnd(44);
  test1.PutEnd(45);
  test1.PutEnd(46);
  TList<int> test2(test1);

  cout << "Begin:" << test1.GetBegin() << endl;
  cout << "Begin:" << test1.GetBegin() << endl;
  cout << "End:" << test1.GetEnd() << endl;
  cout << "End:" << test1.GetEnd() << endl;

  cout << "Begin:" << test2.GetBegin() << endl;
  cout << "Begin:" << test2.GetBegin() << endl;
  cout << "End:" << test2.GetEnd() << endl;
  cout << "End:" << test2.GetEnd() << endl;

  return 0;
}