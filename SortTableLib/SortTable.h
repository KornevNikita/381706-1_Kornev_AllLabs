#include "TRecord.h"
#include "TScanTable.h"
#include <iostream>
#include <locale>

typedef string TKey;

using namespace std;

template <class TValue>
class TSortTable :public TArrayTable<TValue>
{
public:
	TSortTable(int _size) : TArrayTable<TValue>(_size) {}

	bool Find(TKey k)
	{
		int left = 0, right = TTable<TValue>::DataCount - 1, middle;
		while (left <= right)
		{
			middle = (left + right) / 2;
			TTable<TValue>::eff++;
			if (TArrayTable<TValue>::arr[middle].GetKey() == k)
			{
				TArrayTable<TValue>::currNum = middle;
				return true;
			}

			if (TArrayTable<TValue>::arr[middle].GetKey() < k)
				left = middle + 1;
			else
				right = middle - 1;
		}

		TArrayTable<TValue>::currNum = left;
		return false;
	}

	void QuickSort(int left, int right)
	{
		int middle = (left + right) / 2;
		TKey mKey = TArrayTable<TValue>::arr[middle].GetKey();
		int i = left, j = right;

		while (i <= j)
		{
			while (TArrayTable<TValue>::arr[i].GetKey() < mKey)
			{
				i++;
				TTable<TValue>::eff++;
			}

			while (TArrayTable<TValue>::arr[j].GetKey() > mKey)
			{
				j--;
				TTable<TValue>::eff++;
			}

			if (i <= j)
				swap(TArrayTable<TValue>::arr[i], TArrayTable<TValue>::arr[j]);
			TTable<TValue>::eff++;
		}

		if (j > left)
			QuickSort(left, j);
		if (i < right)
			QuickSort(i, right);
	}



	bool Insert(TRecord<TValue> tr)
	{
		if (TArrayTable<TValue>::IsFull())
			throw "TableIsFull";
		if (!Find(tr.GetKey()))
		{
			for (int i = TTable<TValue>::DataCount; i > TArrayTable<TValue>::currNum; i--)
			{
				TArrayTable<TValue>::arr[i] = TArrayTable<TValue>::arr[i - 1];
				TTable<TValue>::eff++;
			}
			TTable<TValue>::DataCount++;
			TArrayTable<TValue>::arr[TArrayTable<TValue>::currNum] = tr;
			return true;
		}
		return false;
	}

	void Delete(TKey k)
	{
		if (TArrayTable<TValue>::IsEmpty())
			throw "TableIsEmpty";
		if (Find(k))
		{
			for (int i = TArrayTable<TValue>::currNum; i < TTable<TValue>::DataCount; i++)
			{
				TArrayTable<TValue>::arr[i] = TArrayTable<TValue>::arr[i + 1];
				TTable<TValue>::eff++;
			}
			TTable<TValue>::DataCount--;
		}
	}
};