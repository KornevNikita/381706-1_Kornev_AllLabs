#pragma once
#include "List.h"
#include "MyException.h"

template <class T>
class TStackList : public TList<T>
{
protected:
  int size; // ������

public:
  TStackList<T>(int _size = 1); // ����������� � ����������
  TStackList<T>(TStackList<T> &A); // ����������� �����������
  ~TStackList(); // ����������
  void Put(T A); // �������� ������� � ����
  T Get(); // ����� ������� �� �����
  int GetMaxSize(); // �������� ������ �����
  int GetSize(); // �������� ���-�� ��������� ����� �� ������ ������
  bool IsEmpty(); // �������� �� �������
  bool IsFull(); // �������� �� �������
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


