#include "RPN.h"


int Priority(const char op)
{
  switch (op)
  {
  case '(':
    return 1;
  case ')':
    return 1;
  case '+':
    return 2;
  case '-':
    return 2;
  case '*':
    return 3;
  case '/':
    return 3;
  default:
    throw MyException(1, "heh");
  }
} 

bool IsOperator(char a)
{
  return (a == '+' || a == '-' || a == '*' || a == '/' || a == '(' || a == ')');
} 

TQueue<char> ToRPN(TString s)
{
  int open = 0;
  int close = 0;
  TQueue<char> Q(s.Len() * 3);
  TStack<char> S(s.Len() * 3);
  for (int i = 0; i < s.Len(); i++)
  {
    if (i == 0)
    {
      if (s[0] == '-')
      {
        Q.Put('[');
        Q.Put('0');
        Q.Put(']');
      }
      else if (IsOperator(s[0]))
        if (Priority(s[0]) != 1)
          throw MyException(1, "heh");
    }
    if (isdigit(s[i]))
    {
      Q.Put('[');
      while ((i < s.Len()) && isdigit(s[i + 1]))
      {
        Q.Put(s[i]);
        i++;
      }
      Q.Put(s[i]);
      Q.Put(']');
    }
    else if (S.IsEmpty() && IsOperator(s[i]))
    {
      S.Put(s[i]);
      if (s[i] == '(')
        open++;
      if (s[i] == ')')
        throw MyException(1, "heh");
    }
    else if (IsOperator(s[i]))
    {
      if (s[i] == '(')
      {
        S.Put(s[i]);
        open++;
      }
      else if (s[i] == ')')
      {
        close++;
        while (S.Top() != '(')
          Q.Put(S.Get());
        S.Get();
      }
      else
      {
        int p = Priority(s[i]);
        if (p > Priority(S.Top()))
          S.Put(s[i]);
        else if (p <= Priority(S.Top()))
        {
          while (!S.IsEmpty() && p <= Priority(S.Top()))
            Q.Put(S.Get());
          S.Put(s[i]);
        }
      }
    }
    else if (s[i] != '\0')
      throw MyException(1, "heh");
  }
  while (!S.IsEmpty())
    Q.Put(S.Get());
  if (open != close)
    throw MyException(1, "heh");
  return Q;
} 

double Result(TQueue<char> q)
{
  double res = 0;
  TStack<double> S(q.GetSize());
  if (IsOperator(q.Top()))
    throw MyException(1, "heh");
  int i = 0;
  int dit = 0;
  int t = 0;
  while (!q.IsEmpty())
  {
    i++;
    char A = q.Get();
    if (A == '[')
    {
      dit++;
      A = q.Get();
      double tmp = std::atof(&A);
      while (q.Top() != ']' && !q.IsEmpty())
      {
        A = q.Get();
        tmp = tmp * 10 + std::atof(&A);
      }
      q.Get();
      S.Put(tmp);
    }
    else if (IsOperator(A))
    {
      double B = S.Get();
      double C = S.Get();
      double D = 0;
      if (A == '+')
        D = C + B;
      if (A == '-')
        D = C - B;
      if (A == '*')
        D = C * B;
      if (A == '/')
        D = C / B;
      S.Put(D);
    }
    else 
      throw MyException(1, "heh");
    if (i == 2 && dit != 2)
      throw MyException(1, "heh");
  }
  res = S.Get();
  if (!S.IsEmpty())
    throw MyException(1, "heh");
  return res;
} 
