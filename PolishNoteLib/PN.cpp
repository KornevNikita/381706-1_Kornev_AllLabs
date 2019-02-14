#include "PN.h"

PN::PN()
{
	size = 0;
	mas = 0;
}

PN::PN(int _size, char* _mas)
{
	if (_size < 0)
	{
		MyException ex(9, "отрицательная длина");
		throw ex;
	}
	size = _size;
	mas = new char[size];
	for (int i = 0; i < size; i++)
		mas[i] = _mas[i];
}

PN::PN(PN& other)
{
	size = other.size;
	mas = new char[size];
	for (int i = 0; i < size; i++)
		mas[i] = other.mas[i];
}

char& PN::operator[](int i)
{
	if (i < 0 || i >= size)
	{
		MyException ex(4, "Элемента не существует");
		throw ex;
	}
	return mas[i];
}

void PN::Print()
{
	for (int i = 0; i < size; i++)
		cout << mas[i];
	cout << endl;
}

int PN::GetSize()
{
	return size;
}

int PN::Getprior(const char a)
{
	switch (a)
	{
	case '(':
		return 0;
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
		return -1;
	}
}

bool PN::IsOperation(char a)
{
	return (a == '+' || a == '-' || a == '*' || a == '/' || a == '(' || a == ')');
}

double PN::Result()
{
	TQueue<char> Queue(size);
	TStack<char> st(size);
	for (int i = 0; i < size; i++)
	{
		if (!IsOperation((*this)[i]))
			Queue.Put((*this)[i]);
		else
		{
			if ((*this)[i] == ')')
			{
				while (st.GetTopElem() != '(')
					Queue.Put(st.Pow());
				st.Pow();
			}
			else
				if (st.IsEmpty())
					st.Put((*this)[i]);
				else
					if (Getprior((*this)[i]) >= Getprior(st.GetTopElem()))
						st.Put((*this)[i]);
					else
					{
						while (Getprior((*this)[i]) < Getprior(st.GetTopElem()))
							Queue.Put(st.Pow());
					}
		}
	}
	while (!st.IsEmpty())
		Queue.Put(st.Pow());
	TStack<double> st2(Queue.GetSize());
	while (!Queue.IsEmpty())
	{
		char A = Queue.Pow();
		if (!IsOperation(A))
			st2.Put(A - '0');
		else
		{
			double y = st2.Pow();
			double x = st2.Pow();
			double z = 0;
			if (A == '+') z = x + y;
			if (A == '-') z = x - y;
			if (A == '*') z = x * y;
			if (A == '/') z = x / y;
			st2.Put(z);
		}
	}
	double result = st2.Pow();
	return result;
}