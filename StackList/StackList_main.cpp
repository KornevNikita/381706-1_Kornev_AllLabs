#include "StackList.h"

int main()
{
  TStackList<double> li(10);
  li.Put(1);
  li.Put(2);
  li.PutBegin(3);
  li.PutEnd(4);

  double a, b, c, d, e, f;
  a = li.Get;
  b = li.GetBegin;
  c = li.GetEnd;
  d = li.GetSize;
  e = li.IsEmpty();
  f = li.IsFull();

  return 0;
}