#include"RPN.h"

bool isnumber(char ch)
{
  for (int i = 0; i < 10; i++)
  {
	if(ch - '0' == i)
	return 1;
  }
  return 0;
}

int Priority(const char ch)
{
  switch (ch)
  {
  default:
	return 0;
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
  }
}

TQueue<char> ToRPN (string str)
{
	TQueue<char> res(str.size()*3);
	TStack<char> st(str.size()*3);
	
	for(int i=0; i < str.size(); i++)
	{
		if (isnumber(str[i]))
			res.Put(str[i]);
		else 
		{
			if (str[i]==')')
			{
				while (st.GetTop() != '(')
					res.Put(st.Get());
				st.Get();
			}
			
			else 
			  if (st.IsEmpty())
			  {
				st.Put(str[i]);
			  }
			 
			  else 
				if (Priority(str[i])>Priority(st.GetTop()))
				st.Put(str[i]);
				
				else
			    {
				while ((Priority(str[i])<=Priority(st.GetTop())))
					res.Put(st.Get());
			    }
		}
	}
	while (!st.IsEmpty())
		res.Put(st.Get());
	return res;
}

double Res (TQueue<char> q)
{
	double res;
	TStack<double> st2(q.GetSize());
	while (!q.IsEmpty())
	{
		char A = q.Get();
		if (isnumber(A))
		  st2.Put(atof(&A));

		else
		{
			double y = st2.Get();
			double x = st2.Get();
			double z = 0;
			if (A == '+') z = x + y;
			if (A == '-') z = x - y;
			if (A == '*') z = x * y;
			if (A == '/') z = x / y;
			st2.Put(z);				
		}
	}
	res = st2.Get();
	return res;
}