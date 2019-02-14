#pragma once
#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#include "MyException.h"

template <class T>
class TVector 
{
protected:
  int n;
  T *v;
public:
  TVector(int _n = 0);
  TVector(const TVector &other);
  virtual TVector& operator=(const TVector &other);
  int GetSize() const { return n; }
  T& operator[](int i);
  virtual TVector operator+()const;
  TVector operator++();
  virtual TVector operator++(int);
  virtual TVector operator-()const;
  virtual TVector operator--();
  virtual TVector operator--(int);
  virtual TVector operator+(const TVector &other);
  virtual TVector operator-(const TVector &other);
  virtual TVector operator*(const TVector &other);
  virtual TVector operator*(T ch);
  virtual bool operator==(const TVector &other);
  virtual bool operator!=(const TVector &other);
  virtual ~TVector();
  
  friend TVector<T> operator*(T ch, const TVector &other) 
  {
	TVector<T> temp(other.n);
	for (int i = 0;i < other.n;i++)
	  temp.v[i] = ch * other.v[i];
	return temp;
  }
  
  friend ostream &operator<<(ostream &os, const TVector other) 
  {
	for (int i = 0;i < other.n;i++)
	  os << other.v[i] << "\t";
	os << endl;
	return os;
  }
  friend istream &operator>>(istream &is, TVector &other) 
  {
	cout << "TVector(n=" << other.n << "):" << endl;
	for (int i = 0;i < other.n;i++) 
	{
	  cout << "[" << i << "]=";
	  is >> other.v[i];
	}
	return is;
  }
};

template <class T>
TVector<T>::TVector(int _n) : n(_n) 
{
  if (n < 0)
  {
	MyException ex(1, "Некорректный размер вектора");
	throw ex;
  }

  if (n == 0)
	v = NULL;
  
  else 
  {
	v = new T[n];
	for (int i = 0; i < n; i++)
	  v[i] = 0;
  }
}

template <class T>
TVector<T>::TVector(const TVector &other) : n(other.n) 
{
  v = new T[n];
  for (int i = 0; i < n; i++)
	v[i] = other.v[i];
}

template <class T>
T& TVector<T>::operator[](int i) 
{
  if (i < 0 || i >= n)
  {
	MyException ex(4, "Элемента не существует");
	throw ex;
  }
  return v[i];
}

template <class T>
TVector<T>& TVector<T>::operator=(const TVector &other) 
{
  if (this == &other)
	return *this;
  
  if (n != other.n)
  {
	delete[] v;
    n = other.n;
	v = new T[n];
  }

  for (int i = 0; i < n; i++)
	v[i] = other.v[i];
  
  return *this;
}

template <class T>
TVector<T> TVector<T>::operator+()const { return *this; }

template <class T>
TVector<T> TVector<T>::operator++() 
{
  for (int i = 0; i < n; i++)
	v[i]++;

  return *this;
}

template <class T>
TVector<T> TVector<T>::operator++(int) 
{
  TVector<T> temp(*this);
  for (int i = 0; i < n; i++)
	++v[i];

  return temp;
}

template <class T>
TVector<T> TVector<T>::operator-()const 
{
  TVector<T> temp(n);
  for (int i = 0; i < n; i++)
	temp.v[i] = -v[i];

  return temp;
}

template <class T>
TVector<T> TVector<T>::operator--() 
{
  for (int i = 0; i < n; i++)
	v[i]--;

  return *this;
}

template <class T>
TVector<T> TVector<T>::operator--(int) 
{
  TVector<T> temp(*this);
  for (int i = 0;i < n;i++)
	 --v[i];

  return temp;
}

template <class T>
TVector<T> TVector<T>::operator+(const TVector &other) 
{
  if (n != other.n)
  {
	  MyException ex(5, "Невозможно выполнить операцию для векторов разной размерности");
	  throw ex;
  }

  TVector<T> temp(n);
  for (int i = 0; i < n; i++)
	temp.v[i] = v[i] + other.v[i];

  return temp;
}

template <class T>
TVector<T> TVector<T>::operator-(const TVector &other) 
{
  if (n != other.n)
  {
	  MyException ex(5, "Невозможно выполнить операцию для векторов разной размерности");
	  throw ex;
  }

  TVector<T> temp(n);
  for (int i = 0; i < n; i++)
	temp.v[i] = v[i] - other.v[i];

  return temp;
}

template <class T>
TVector<T> TVector<T>::operator*(const TVector &other) 
{
  if (n != other.n)
  {
	  MyException ex(5, "Невозможно выполнить операцию для векторов разной размерности");
	  throw ex;
  }

  TVector<T> temp(n);
  for (int i = 0; i < n; i++)
	temp.v[i] = v[i] * other.v[i];

  return temp;
}

template <class T>
TVector<T> TVector<T>::operator*(T ch) 
{
  TVector<T> temp(n);
  for (int i = 0;i < n;i++)
	temp.v[i] = ch * v[i];

  return temp;
}

template <class T>
bool TVector<T>::operator==(const TVector &other) 
{
  if (n != other.n)
	  return 0;
  
  for (int i = 0; i < n;i++)
	if (v[i] != other.v[i])
		return 0;

  return 1;
}

template <class T>
bool TVector<T>::operator!=(const TVector &other) 
{
  if (n != other.n)
	return 1;

  for (int i = 0;i < n;i++)
	if (v[i] != other.v[i])
	  return 1;

  return 0;
}

template <class T>
TVector<T>::~TVector() 
{
  if (v != NULL) 
  {
	  delete[] v;
	  v = NULL;
  }

  n = 0;
}
