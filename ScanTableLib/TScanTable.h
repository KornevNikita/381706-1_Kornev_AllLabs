#pragma once
#include <iostream>
#include "TRecord.h"

using namespace std;

template <class TValue>
class TTable 
{
protected:
	int DataCount;
	int eff;

public:
	TTable() 
	{
		DataCount = 0;
		eff = 0;
	}

	~TTable() {}

	bool IsEmpty()
	{
		return DataCount == 0;
	}


	virtual bool IsFull() = 0;
	virtual bool Find(string key) = 0;
	virtual bool Insert(TRecord<TValue> record) = 0;
	virtual void Delete(string key) = 0;
	virtual void GoNext() = 0;
	virtual bool IsEnd() = 0;
	virtual void Reset() = 0;
	virtual TRecord<TValue> GetCurrent() = 0;
	virtual void SetCurrentValue(TValue value) = 0;


	void Print()
	{
		TRecord<TValue> tmp;

		for (Reset(); !IsEnd(); GoNext())
		{
			tmp = GetCurrent();
			cout << tmp.GetData() << endl;
		}
	}

	int GetEff()
	{
		return eff;
	}

	void ClrEff()
	{
		eff = 0;
	}

	int GetDataCount()
	{
		return DataCount;
	}

};



template <class TValue>
class TArrayTable : public TTable<TValue>
{
protected:
	TRecord<TValue> *arr;
	int size;
	int currNum;

public:

	TArrayTable(int _size = 10)
	{
		size = _size;
		arr = new TRecord<TValue>[size];
		currNum = 0;
	}

	~TArrayTable()
	{
		delete[] arr;
	}

	TArrayTable(const TRecord<TValue>& recArr)
	{
		size = recArr.size;
		currNum = recArr.currNum;
		arr = new TRecord<TValue>[size];
		for (int i = 0; i < size; i++)
			arr[i] = recArr[i];
	}

	TRecord<TValue>*& operator=(const TRecord<TValue>& recArr)
	{
		if (size != recArr.size)
		{
			delete[] arr;
			size = recArr.size;
			arr = new TRecord<TValue>[size];
		}

		for (int i = 0; i < size; i++)
			arr[i] = recArr[i];
		return *this;
	}

	TRecord<TValue> GetCurrent()
	{
		return arr[currNum];
	}

	void Reset()
	{
		currNum = 0;
	}

	void GoNext()
	{
		currNum++;
	}

	bool IsEnd()
	{
		return currNum == TTable<TValue>::DataCount;
	}

	bool IsFull()
	{
		return size == TTable<TValue>::DataCount;
	}

	bool IsEmpty()
	{
		return TTable<TValue>::DataCount == 0;
	}

	void SetCurrentValue(TValue val)
	{
		arr[currNum].SetData(val);
	}

	int GetCurrNum()
	{
		return currNum;
	}

};

template <class TValue>
class TScanTable :public TArrayTable<TValue>
{
public:

	TScanTable(int _size = 10) : TArrayTable<TValue>(_size) {}

	bool Find(string k)
	{
		for (int i = 0; i < TTable<TValue>::DataCount; i++)
		{
			TTable<TValue>::eff++;
			if (TArrayTable<TValue>::arr[i].GetKey() == k)
			{
				TArrayTable<TValue>::currNum = i;
				return true;
			}
		}
		TArrayTable<TValue>::currNum = TTable<TValue>::DataCount;
		return false;
	}

	bool Insert(TRecord<TValue> tr)
	{
		if (TArrayTable<TValue>::IsFull())
			throw "TableIsFull";
		if (!Find(tr.GetKey()))
		{
			TArrayTable<TValue>::arr[TArrayTable<TValue>::currNum] = tr;
			TTable<TValue>::DataCount++;
			return true;
		}
		return false;
	}

	void Delete(string k)
	{
		if (TArrayTable<TValue>::IsEmpty())
			throw "TableIsEmpty";
		if (Find(k))
		{
			TArrayTable<TValue>::arr[TArrayTable<TValue>::currNum] = TArrayTable<TValue>::arr[TTable<TValue>::DataCount - 1];
			TTable<TValue>::DataCount--;
		}		
	}
};