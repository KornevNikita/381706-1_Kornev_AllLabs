#pragma once
#include <string>
#include "TRecord.h"

typedef string TKey;

using namespace std;

template <class TValue>
class TTreeNode
{
public:
	int bal;
	TRecord<TValue> rec;
	TTreeNode<TValue> *pLeft, *pRight;

	TTreeNode(TRecord<TValue> _record, 
		TTreeNode<TValue> *_pLeft = NULL, 
		TTreeNode<TValue> *_pRight = NULL) 
	{
		rec = _record;
		pLeft = _pLeft;
		pRight = _pRight;
	}

	TRecord<TValue> GetRec()
	{
		return rec;
	}
};