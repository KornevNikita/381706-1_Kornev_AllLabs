#include "StackList.h"

int main()
{
  TStackList<double> li(10);
  li.Put(1);
  li.Put(2);
  li.Put(3);
  li.Put(4);

  double a, b, c, d, e, f;
  a = li.Get();
  d = li.GetSize();
  e = li.IsEmpty();
  f = li.IsFull();

  return 0;
}
