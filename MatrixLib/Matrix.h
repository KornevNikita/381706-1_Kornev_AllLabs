#pragma once
#include "Vector.h"

template <class T>
class TMatrix : public TVector<TVector<T> > {
public:
	explicit TMatrix(int _n = 0);
	TMatrix(const TMatrix &other) : TVector<TVector<T> >(other) {}
	TMatrix(const TVector<TVector<T> > &other) : TVector<TVector<T> >(other) {}
	~TMatrix() {}
	TMatrix& operator=(const TMatrix &other);
	TMatrix  operator+(const TMatrix &other);
	TMatrix  operator-(const TMatrix &other);
	TMatrix operator*(const TMatrix &other);
	bool operator==(const TMatrix &other);
	bool operator!=(const TMatrix &other);
	friend ostream &operator<<(ostream &os, const TMatrix<T> other)
	{
		for (int i = 0; i < other.n; i++) {
			for (int j = 1; j <= i; j++)
				os << "\t";
			os << other.v[i] << endl;
		}
		return os;
	}
};

template <class T>
TMatrix<T> :: TMatrix(int _n) : TVector<TVector<T> >(_n)
{
	for (int i = 0; i < _n; i++)
		TMatrix<T>::v[i] = TVector<T>(_n - i);
}

template <class T>
TMatrix<T> & TMatrix<T> ::operator=(const TMatrix &other)
{
	TVector<TVector<T> >::operator=(other);
	return *this;
}

template <class T>
TMatrix<T> TMatrix<T> :: operator+(const TMatrix &other)
{
	return TVector<TVector<T> >::operator+(other);
}

template <class T>
TMatrix<T> TMatrix<T> :: operator-(const TMatrix &other)
{
	return TVector<TVector<T> >::operator-(other);
}

template <class T>
TMatrix<T> TMatrix<T> :: operator*(const TMatrix &other)
{
	if (TMatrix<T>::n != other.n)
	{
		MyException ex(5, "Невозможно выполнить операцию для матриц разной размерности");
		throw ex;
	}
	TMatrix<T> result(TMatrix<T>::n);
	for (int i = 0; i < TMatrix<T>::n; i++)
		for (int j = i; j < TMatrix<T>::n; j++)
			for (int k = i; k <= j; k++)
				result.v[i][j - i] += TMatrix<T>::v[i][k - i] * other.v[k][j - k];
	return result;
}

template <class T>
bool TMatrix<T>:: operator==(const TMatrix &other)
{
	return TVector<TVector<T> >::operator==(other);
}

template <class T>
bool TMatrix<T>:: operator!=(const TMatrix &other)
{
	return TVector<TVector<T> >::operator!=(other);
}
