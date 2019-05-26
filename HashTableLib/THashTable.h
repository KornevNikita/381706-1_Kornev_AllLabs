#pragma once
#include <string>
#include <iostream>
#include "TScanTable.h"
#include "TRecord.h"

typedef string TKey;

using namespace std;

template<class TValue>
class THashTable : public TTable<TValue>
{
protected:
	int HashFunc(TKey k)
	{
		int pos = 0;
		for (int i = 0; i < k.length(); i++)
			pos += k[i] << i;
		return pos;
	}
};


template<class TValue>
class TArrayHash :public THashTable<TValue>
{
protected:
	int size, step, currNum;
	TRecord<TValue> *arr;

public:
	TArrayHash(int _size = 100)
	{
		if (_size <= 0)
			throw "WrongSize";
		size = _size;
		arr = new TRecord<TValue>[size];
		step = 17;
		for (int i = 0; i < size; i++)
			arr[i].GetKey() = " ";
		currNum = 0;
	}

	~TArrayHash()
	{
		delete[] arr;
	}

	int GetCurrNum()
	{
		return currNum;
	}

	bool Find(TKey k)
	{
		currNum = THashTable<TValue>::HashFunc(k) % size;
		int freepos = -1;
		for (int i = 0; i < size; i++)
		{
			TTable<TValue>::eff++;
			if (arr[currNum].GetKey() == " ")
				if (freepos == -1)
					return false;
				else
				{
					currNum = freepos;
					return freepos;
				}
			if (arr[currNum].GetKey() == k)
				return true;
			if ((freepos == -1) && (arr[currNum].GetKey() == "&"))
				freepos = currNum;
			currNum += step;
			currNum %= size;
		}
		return false;
	}

	void Delete(TKey k)
	{
		if (IsEmpty())
			throw "Empty";
		if (Find(k))
		{
			TTable<TValue>::DataCount--;
			arr[currNum].GetKey() = "&";
		}
	}

	void Reset()
	{
		currNum = 0;
		while ((arr[currNum].GetKey() == " " || arr[currNum].GetKey() == "&") && (currNum < size))
			currNum++;
	}

	bool isEnd()
	{
		return currNum >= size;
	}

	void GoNext()
	{
		while ((++currNum < size))
		{
			if (((arr[currNum].GetKey() != "&") && (arr[currNum].GetKey() != " ")))
				break;
		}
	}

	bool Insert(TRecord<TValue> record)
	{
		if (!Find(record.GetKey()))
		{
			arr[currNum] = record;
			TTable<TValue>::DataCount++;
			return true;
		}
		return false;
	}

	bool IsFull()
	{
		return TTable<TValue>::DataCount == size;
	}

	bool IsEmpty()
	{
		return TTable<TValue>::DataCount == 0;
	}

	bool IsEnd()
	{
		return currNum >= size;
	}

	TRecord<TValue> GetCurrent()
	{
		return arr[currNum];
	}

	void SetCurrentValue(TValue val)
	{
		arr[currNum].SetData(val);
	}

	void SetRowNum(int row)
	{
		arr[currNum].numRow = row;
	}

};
