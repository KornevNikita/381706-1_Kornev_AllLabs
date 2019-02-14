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
	T Pow();
	T GetTopElem();
};

template <class T>
TStack<T>::TStack()
{
  size = 0;
  mas = 0;
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
	  mas = 0;
	  top = 0;
	}
  
	  else
	{
	  mas = new T[_size];
	  size = _size;
	  top = 0; 
	}
}

template <class T>
TStack<T>::TStack(TStack<T> &st){
  size = st.size;
  top = st.top;
  
  if (size == 0)
	mas = 0;
  
  else
  {
	  mas = new T[size];
	  for (int i = 0; i < size; i++)
		mas[i] = st.mas[i];

  }
}
template <class T>
TStack<T> :: ~TStack(){
  if (mas != 0)
	delete[] mas;

  top = 0;
  size = 0;
}


template <class T>
void TStack<T>::Put(T st){
  if (IsFull())
	  throw "Full";
  else
  {
	mas[top] = st;
	top++;
  }
}

template <class T>
T TStack<T>::Get(){
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
T TStack<T> ::Pow()
 {
	if (IsEmpty()) 
	{
		MyException ex(3, "Стек пуст");
		throw ex;
	}
	top--;
	return top;
}

template <class T>
T TStack<T> ::GetTopElem() 
{
	if (IsEmpty()) 
	{
		MyException ex(3, "Стек пуст");
		throw ex;
	}
	top--;
	return top;
	top++;
}