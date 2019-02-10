#include <iostream>
#include "Monom.h"

using namespace std;

int  main ()
{
  int a[3] = { 1,2,3 };
  TMonom A(3, a, 3);
  cout << A << endl;
  return 0;
}