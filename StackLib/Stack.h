#pragma once
#include <iostream>
#include "MyException.h"

using namespace std;

template <class T>
class TStack
{
protected:
  int size; //Размер стека
  T* mas; //Элементы стека
  int top; //Верх

public:
  TStack(); //Конструктор по умолчанию
  TStack(int _Size); //Конструктор с параметром
  TStack(TStack &st); //Конструктор копирования
  ~TStack(); //Деструктор
  void Put(T st); //Положить в стек
  T Get(); // Взять из стека
  int GetSize(); // Получить размер
  bool IsFull(); // Проверка на полноту
  bool IsEmpty(); // Проверка на пустоту
	T Top();
	void Clean();
};

template <class T>
TStack<T>::TStack()
{
  size = 0;
  mas = NULL;
  top = 0;
}

template <class T>
TStack<T>::TStack(int _size)
{
  if (_size < 0)
	throw "Negative size";
  
  else 
	if (_size == 0)
	{
	  size = 0;
	  mas = NULL;
	  top = 0;
	}
  
	  else
	{
	  size = _size;
	  mas = new T[size];
	  top = 0; 
	}
}

template <class T>
TStack<T>::TStack(TStack<T> &st)
{
  size = st.size;
  top = st.top;
  
  if (size == 0)
	mas = NULL;
  
  else
  {
	  mas = new T[size];
	  for (int i = 0; i < size; i++)
		mas[i] = st.mas[i];

  }
}

template <class T>
TStack<T> :: ~TStack()
{
  top = size = 0;
  mas = 0;
}


template <class T>
void TStack<T>::Put(T st)
{
  if (IsFull())
	  throw "Full";
  else
  {
	mas[top] = st;
	top++;
  }
}

template <class T>
T TStack<T>::Get()
{
  if (IsEmpty())
	throw "Empty";
  
  else
  {
	top--;
	return mas[top];
  }
}

template <class T>
bool TStack<T>::IsEmpty()
{
  return (top == 0);
}

template <class T>
bool TStack<T>::IsFull()
{
  return (top >= size);
}

template <class T>
int TStack<T>::GetSize() 
{
  return size;
}

template <class T>
T TStack<T> ::Top() 
{
	if (IsEmpty())
		throw "Empty";
	else
	{
		return mas[top - 1];
	}
}

template<class T>
void TStack<T>::Clean()
{
	while (!this->IsEmpty())
		this->Get();
}