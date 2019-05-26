#pragma once
#include <string>
#include "TScanTable.h"
#include "TTreeNode.h"
#include <stack>
#include <cstddef>

typedef string TKey;

using namespace std;

template<class TValue>
class TTreeTable : public TTable<TValue>
{
private:

	TTreeNode<TValue> *pRoot;
	TTreeNode<TValue> *pCurr;
	stack<TTreeNode<TValue>*> st;
	TTreeNode<TValue> **pRes;
	int pos;

public:

	TTreeTable()
	{
		pRoot = NULL;
		pCurr = NULL;
		pRes = NULL;
	}

	bool Find(TKey k)
	{
		pRes = &pRoot;
		while (*pRes != NULL)
		{
			TTable<TValue>::eff++;
			if ((*pRes)->rec.GetKey() == k)
			{
				return true;
			}
			else
			{
				if ((*pRes)->rec.GetKey() < k)
					pRes = &((*pRes)->pRight);
				else
					pRes = &((*pRes)->pLeft);
			}
		}
		return false;
	}

	bool Insert(TRecord<TValue> r)
	{
		if (!Find(r.GetKey()))
		{
			*pRes = new TTreeNode<TValue>(r);
			TTable<TValue>::DataCount++;
			return true;
		}
		else
			return false;
	}

	void Delete(TKey k)
	{
		if (Find(k))
		{
			TTreeNode<TValue> *tmp = *pRes;
			if (tmp->pLeft == NULL)
				*pRes = tmp->pRight;
			else
				if (tmp->pRight == NULL)
					*pRes = tmp->pLeft;
				else
				{
					TTreeNode<TValue> *p = tmp->pLeft;
					TTreeNode<TValue> **pPrev = &tmp->pLeft;
					while (p->pRight != NULL)
					{
						TTable<TValue>::eff++;
						pPrev = &(p->pRight);
						p = p->pRight;
					}
					tmp->rec = p->rec;
					tmp = p;
					*pPrev = p->pLeft;
				}
			delete tmp;
			TTable<TValue>::DataCount--;
		}
	}

	void Reset()
	{
		pos = 0;
		while (!st.empty())
			st.pop();
		pCurr = pRoot;
		if (pCurr != NULL)
		{
			while (pCurr->pLeft != NULL)
			{
				st.push(pCurr);
				pCurr = pCurr->pLeft;
			}
		}
		st.push(pCurr);
	}

	void GoNext()
	{
		if (!st.empty())
			st.pop();
		pos++;
		if (pCurr->pRight != NULL)
		{
			pCurr = pCurr->pRight;
			while (pCurr->pLeft != NULL)
			{
				st.push(pCurr);
				pCurr = pCurr->pLeft;
			}
			st.push(pCurr);
		}
		else
			if (!st.empty())
			{
				pCurr = st.top();
			}
	}

	bool IsEnd()
	{
		return(pos == TTable<TValue>::DataCount);
	}

	bool IsFull()
	{
		return false;
	}

	void SetCurrentValue(TValue val)
	{
		pCurr->GetRec().SetData(val);
	}

	TRecord<TValue> GetCurrent()
	{
		return pCurr->rec;
	}

	void SetNumRow1(int row)
	{
		pCurr->rec.numRow = row;
	}

	TRecord<TValue> GetResRecord()
	{
		return (*pRes)->rec;
	}

	void SetRes(TValue val)
	{
		(*pRes)->rec.value = val;
	}
};