#pragma once
#include "NewStack.h"
#include <iostream>

using namespace std;

template <class T>
class TMStack 
{
protected:
	int size;
	T* mas;
	int n;
	TNewStack<T>** stackmas;
	int GetFreeMem();
	void Repack(int _n);
public:
	TMStack(int _n, int _size);
	TMStack(TMStack &A);
	int GetSize();
	void Set(int _n, T _elem);
	T Get(int _n); 
	bool isFull(int _n); 
	bool isEmpty(int _n);
};

template <class T>
TMStack<T> ::TMStack(int _n, int _size)
{
	if (_n <= 0 || _size <= 0)
		throw "Negative leight";

	n = _n; 
	size = _size;

	stackmas = new TNewStack<T>*[n];
	mas = new T[size]; 

	int* p = new int[n];

	p[0] = int(double(size) / n) + (size % n);

	for (int i = 1; i < n; i++)
		p[i] = int(double(size) / n); 

	stackmas[0] = new TNewStack<T>(p[0], &mas[0]); 
	for (int i = 1; i < n; i++)
		stackmas[i] = new TNewStack<T>(p[i], &mas[p[0] + (i - 1)*p[i]]);
}

template <class T>
TMStack<T> ::TMStack(TMStack &A)
{
	int sizeST = 0; 
	size = A.size;
	n = A.n;
	mas = new T[size];
	stackmas = new TNewStack<T>*[n];
	for (int i = 0; i < n; i++) 
		mas[i] = A.mas[i];

	int* p = new int[n]; 
	for (int i = 0; i < n; i++)
		p[i] = A.stackmas[i]->GetSize();
	stackmas[0] = new TNewStack<T>(*A.stackmas[0]);
	for (int i = 1; i < n; i++)
	{
		stackmas[i] = new TNewStack<T>(*A.stackmas[i]);
		stackmas[i]->SetMas(p[i], &mas[-p[0] + sizeST]);
		sizeST += p[i - 1];
	}
}

template <class T>
int TMStack<T>::GetSize() 
{
	return size; 
}

template<class T>
void TMStack<T>::Set(int _n, T _elem)
{
	if (_n < 0)
		throw "Negative index";
	if (GetFreeMem() == 0)
		throw "FULL";
	if (isFull(_n))
		Repack(_n);
	stackmas[_n]->Push(_elem);
}

template<class T>
T TMStack<T>::Get(int _n)
{
	if (_n < 0)
		throw "Negative index";
	if (isEmpty(_n)) 
	{
		throw "Empty";
	}
	return stackmas[_n]->Get();
}

template<class T>
bool TMStack<T>::isFull(int _n)
{
	return (stackmas[_n]->GetFreeMem() <= 0);
}

template<class T>
bool TMStack<T>::isEmpty(int _n)
{
	return (stackmas[_n]->GetFreeMem() == stackmas[_n]->GetSize());
}

template <class T>
int TMStack<T>::GetFreeMem()
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		count += stackmas[i]->GetFreeMem();
	}
	return count;
}

template <class T>
void TMStack<T>::Repack(int _n)
{
	int FM = GetFreeMem();
	int add_ev = FM / n;
	int add_full = FM % n;
	int* new_size = new int[n];
	T** new_start = new T*[n];
	T** old_start = new T*[n];

	for (int i = 0; i < n; i++)
		new_size[i] = add_ev + stackmas[i]->GetTop();
	new_size[_n] += add_full;
	new_start[0] = old_start[0] = mas;

	for (int i = 1; i < n; i++)
	{
		new_start[i] = new_start[i - 1] + new_size[i - 1];
		old_start[i] = old_start[i - 1] + stackmas[i - 1]->GetSize();
	}

	for (int i = 0; i < n; i++)
	{
		if (new_start[i] <= old_start[i])
			for (int j = 0; j < stackmas[i]->GetTop(); j++)
				new_start[i][j] = old_start[i][j];

		else
		{
			int s = i + 1;
			for (s; s < n; s++)
				if (new_start[s] <= old_start[s])
					break;

			for (int j = s - 1; j >= i; j--)
				for (int r = stackmas[j]->GetTop() - 1; r >= 0; r--)
					new_start[j][r] = old_start[j][r];

			i = s - 1;
		}
	}

	for (int i = 0; i < n; i++)
		stackmas[i]->SetMas(new_size[i], new_start[i]);

	delete[] new_size;
	delete[] new_start;
	delete[] old_start;
}