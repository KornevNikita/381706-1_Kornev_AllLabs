#pragma once
#include "List.h"
#include "MyException.h"

template <class T>
class TStackList : public TList<T>
{
protected:
  int size; // размер

public:
  TStackList<T>(int _size = 1); // конструктор с параметром
  TStackList<T>(TStackList<T> &A); // конструктор копирования
  ~TStackList(); // деструктор
  void Put(T A); // положить элемент в стек
  T Get(); // взять элемент из стека
  int GetMaxSize(); // получить размер стека
  int GetSize(); // получить кол-во элементов стека на данный момент
  bool IsEmpty(); // проверка на пустоту
  bool IsFull(); // проверка на полноту
};

template <class T>
TStackList<T>::TStackList(int _size) : TList<T>()
{
  if (_size <= 0)
    throw MyException(1, "error");
  size = _size;
}

template <class T>
TStackList<T>::TStackList(TStackList<T> &A) : TList<T>(A)
{
  TList<T>::count = A.count;
}

template<class T>
TStackList<T>::~TStackList()
{}

template <class T>
void TStackList<T>::Put(T A)
{
  if (this->IsFull())
    throw MyException(1, "error");
  TList<T>::PutBegin(A);
}

template <class T>
T TStackList<T>::Get()
{
  if (this->IsEmpty())
    throw MyException(1, "error");
  return TList<T>::GetBegin();
}

template <class T>
int TStackList<T>::GetMaxSize()
{
  return size;
}

template<class T>
inline int TStackList<T>::GetSize()
{
  return TList<T>::count;
}

template <class T>
bool TStackList<T>::IsEmpty()
{
  if (TList<T>::count == 0)
    return true;
  return false;
}

template<class T>
bool TStackList<T>::IsFull()
{
  if (TList<T>::count == size)
    return true;
  return false;
}


