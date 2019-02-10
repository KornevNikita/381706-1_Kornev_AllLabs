#include "Field.h"
#include "MyException.h"

template <class T>
class TList {
protected:
	TField<T>* begin;
public:
	TList() : begin(0) {};
	TList(TList &A);
	~TList();
	void PutBegin(T _field);
	void PutEnd(T _field);
	bool IsEmpty() { return (begin == 0); }
	T GetBegin();
	T GetEnd();

};

template <class T>
TList<T>::TList(TList<T> &other)
{
	TField<T>* fieldCopy = other.begin;
	TField<T>* copyNext;
	if (other.begin == 0)
		begin = 0;
	else
	{
		begin = new TField<T>(*other.begin);
		copyNext = begin;
		while (fieldCopy->TField<T>::GetNext() != 0)
		{
			copyNext->TField<T>::SetNext(new TField<T>(*(fieldCopy->TField<T>::GetNext())));
			fieldCopy = fieldCopy->TField<T>::GetNext();
			copyNext = copyNext->TField<T>::GetNext();
		}
	}
}

template <class T>
TList<T> :: ~TList()
{
	while (begin != 0)
	{
		TField<T>* temp = begin->TField<T>::GetNext();
		delete begin;
		begin = temp;
	}
}

template <class T>
T TList<T> ::GetBegin()
{
	if (IsEmpty())
	{
		MyException ex(7, "Список пуст");
		throw ex;
	}
	T tempField = begin->GetField();
	begin = begin->GetNext();
	return tempField;
}

template <class T>
T TList<T> :: GetEnd()
{
	if (IsEmpty())
	{
		MyException ex(7, "Список пуст");
		throw ex;
	}
	TField<T>* temp = begin;
	while ((temp->GetNext())->GetNext() != 0)
		temp = temp->GetNext();
	T tempField = (temp->GetNext())->GetField();
	temp->SetNext(0);
	return tempField;
}

template <class T>
void TList<T> :: PutBegin(T _field)
{
	TField<T>* temp = new TField<T>(_field, begin);
	begin = temp;
}

template <class T>
void TList<T> ::PutEnd(T _field)
{
	if (IsEmpty())
		begin = new TField<T>(_field, 0);
	else {
		TField<T>* temp = begin;
		while (temp->GetNext() != 0)
			temp = temp->GetNext();
		temp->SetNext(new TField<T>(_field, 0));
	}
}