#pragma once
#include "MyException.h"
#include "Queue.h"

template <class T>
class TArrList
{
private:
  T* mas;                    
	int *nextInd;              
	int *predInd;              
	int size;                  
	int count;                 
	int start;                 
	int end;                   
	TQueue <int> freeElem;
	
public:
	TArrList(int _size = 1);  
	TArrList(TArrList<T> &A);  
	~TArrList();               
	void Put(int n, T elem);   
	T Get(int n);               
	void PutStart(T elem);     
	void PutEnd(T elem);       
	T GetStart();              
	T GetEnd();                
	bool IsFull();             
	bool IsEmpty();                  
};

template <class T>
TArrList<T>::TArrList(int _size) : freeElem(_size)
{
	if (_size <= 0)
	{
		MyException ex(3, "Некорректный размер списка");
		throw ex;
	}
	size = _size;
	count = 0;
	start = -1;
	end = -1;
	mas = new T[size];
	nextInd = new int[size];
	predInd = new int[size];
	for (int i = 0; i < size; i++)
	{
		nextInd[i] = -2;
		predInd[i] = -2;
		freeElem.Put(i);
	}
}

template <class T>
TArrList<T>::TArrList(TArrList<T> &A)
{
	start = A.start;
	end = A.end;
	size = A.size;
	count = A.count;
	mas = new T[size];
	nextInd = new int[size];
	predInd = new int[size];
	freeElem = A.freeElem;
	for (int i = 0; i < size; i++)
	{
		mas[i] = A.mas[i];
		nextInd[i] = A.nextInd[i];
		predInd[i] = A.predInd[i];
	}
}

template<class T>
inline TArrList<T>::~TArrList()
{
	delete[] mas;
	delete[] nextInd;
	delete[] predInd;
}

template<class T>
void TArrList<T>::Put(int n, T elem)
{
	if (IsFull())
	{
		MyException ex(4, "Список полон");
		throw ex;
	}
	if (n < 1 || n > count - 1)
	{
		MyException ex(6, "Элемента не существует");
		throw ex;
	}
	int ifree = freeElem.Get();
	mas[ifree] = elem;
	int one = start;
	int two = nextInd[start];
	for (int i = 0; i < n - 1; i++)
	{
		one = two;
		two = nextInd[two];
	}
	nextInd[ifree] = two;
	nextInd[one] = ifree;

	predInd[ifree] = one;
	predInd[two] = ifree;
	count++;
}

template<class T>
T TArrList<T>::Get(int n)
{
	if (IsEmpty())
	{
		MyException ex(4, "Список пуст");
		throw ex;
	}
	if (n < 1 || n > count - 1)
	{
		MyException ex(6, "Элемента не существует");
		throw ex;
	}
	int ind = start;
	for (int i = 0; i < n; i++)
		ind = nextInd[ind];
	nextInd[predInd[ind]] = nextInd[ind];
	predInd[nextInd[ind]] = predInd[ind];
	T temp = mas[ind];
	freeElem.Put(ind);
	count--;
	return temp;
}

template <class T>
void TArrList<T>::PutStart(T elem)
{
	if (IsFull()) // проверяем список на наличие свободного места
	{
		MyException ex(4, "Список полон");
		throw ex;
	}
	int ifree = freeElem.Get(); // берем первую свободную ячейку i
	mas[ifree] = elem; // в mas записываем значение, которое хотим положить в список
	nextInd[ifree] = start; // Определяем, что следующим для этого элемента, будет элемент с текущим индексом start
	if (start != -1) // предыдущим для первого элемента списка делаем только что добавленный элемент
		predInd[start] = ifree;
	else
		end = ifree; // определяем, что добавленный элемент является и последним элементом в списке
	start = ifree; // индекс start переопределяем на только что добавленный элемент: start = i. 
	count++; // Увеличиваем количество элементов в списке 
}

template <class T>
void TArrList<T>::PutEnd(T elem)
{
	if (IsFull()) // проверяем список на наличие свободного места
	{
		MyException ex(4, "Список полон");
		throw ex;
	}
	int ifree = freeElem.Get(); // берем первую свободную ячейку i
	mas[ifree] = elem; // в mas записываем значение, которое хотим положить в список
	if (end != -1) 
		nextInd[end] = ifree; // следующим для последнего элемента списка делаем только что добавленный элемент
	else
	{
		start = ifree; // определяем, что добавленный элемент является первым элементом в списке
		predInd[ifree] = -1;
	}
	predInd[ifree] = end; // определяем, что добавленный элемент является следующим после конца
	end = ifree; 
	count++; // Увеличиваем количество элементов в списке 
}

template <class T>
T TArrList<T>::GetStart()
{
	if (IsEmpty())
	{
		MyException ex(4, "Список пуст");
		throw ex;
	}
	T elem = mas[start];
	freeElem.Put(start);
	int newstart = nextInd[start];
	nextInd[start] = predInd[start] = -2;
	if (newstart != -1)
		predInd[newstart] = -1;
	count--;
	start = newstart;
	return elem;
}

template <class T>
T TArrList<T>::GetEnd()
{
	if (IsEmpty())
	{
		MyException ex(4, "Список пуст");
		throw ex;
	}
	T elem = mas[end];
	int newFinish = predInd[end];
	predInd[end] = nextInd[end] = -2;
	freeElem.Put(end);
	end = newFinish;
	if (newFinish != -1)
		nextInd[newFinish] = -1;
	else
		start = -1;
	count--;
	return elem;
}

template <class T>
bool TArrList<T>::IsFull()
{
	if (count == size)
		return true;
	return false;
}

template <class T>
bool TArrList<T>::IsEmpty()
{
	if (count == 0)
		return true;
	return false;
}

