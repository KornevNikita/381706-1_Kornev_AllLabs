#pragma once
#include <iostream>
#include "Stack.h"

using namespace std;

template <class T>
class TQueue : public TStack <T> 
{
protected:
  int start; //Начало 
  int count; //Конец 

public:
  TQueue(); //Конструктор по умолчанию
  TQueue(int size); //Конструктор с параметром
  TQueue(TQueue <T> &A); //Конструктор копирования
  void Put(T A); //Положить в конец очереди
  T Get(); //Взять элемент
  bool IsFull(); //Проверка на полноту
  bool IsEmpty(); //Проверка на пустоту
};

template <class T>
TQueue<T>::TQueue() : TStack<T>()
{
  start = count = 0;
}

template <class T>
TQueue<T>::TQueue(int size) : TStack<T>(size) 
{
  start = count = 0;
}

template <class T>
TQueue<T>::TQueue(TQueue<T> &q) : TStack<T>(q) 
{
  start = q.start; 
  count = q.count;
}

template <class T>
void TQueue<T>::Put(T A)
{
  if (IsFull())
	throw "Queue is full";
  
  else 
  {
	TStack<T>::mas[start] = A;
	start = (start + 1) % TStack<T>::size;
	count++;
  }
}

template <class T>
T TQueue<T>::Get()
{
  /*if (IsEmpty())
	throw "Queue is empty";

  else
  {
	T temp = TStack<T>::mas[TStack<T>::top];
	TStack<T>::top = (TStack<T>::top + 1) % TStack<T>::size;;
	count--;

	return temp;
  }*/

  if (IsEmpty())
	throw "blabla";
  else
  {
	T temp = TStack<T>::mas[start];
	start = (start + 1) % TStack<T>::size;
	count--;
	return temp;
  }
}

template <class T>
bool TQueue<T>::IsFull() 
{
  return (count == TStack<T>::size);
}

template <class T>
bool TQueue<T>::IsEmpty() 
{
  if (count == 0)
	return 1;
  return 0;
}
