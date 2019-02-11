#pragma once
#include <iostream>

using namespace std;

template <class T>
class TElem{
private:
	T elem;//Значение
	TElem<T>* next;//Указатель на след элемент
public:
	TElem(T _e = 0, TElem<T>* _n = 0);//Конструктор с параметрами :1 - Значение элемента 2 - указатель на следующий элемент
	TElem(TElem<T> &A);//Конструктор копирования
	T Get();//Получить эначение элемента
	TElem* GetNext();//Получить указатель на следующий 
	void Set(T e);//Установить значение
	void SetNext(TElem<T>* n);//Установить указатель
};

template <class T>
TElem<T>::TElem(T _e, TElem<T>* _n){
	elem = _e;
	if (_n == 0)
		next = 0;
	else
		next = _n;
}

template <class T>
TElem<T>::TElem(TElem<T> &A){
	elem = A.elem;
	next = A.next;
}

template <class T>
T TElem<T>::Get(){
	return elem;
}

template <class T>
TElem<T>* TElem<T>::GetNext(){
	return next;
}
template <class T>
void TElem<T>::Set(T _e){
	elem = _e;
}

template <class T>
void TElem<T>::SetNext(TElem<T>* _n){
	next = _n;
}


