#pragma once
#include "THashTable.h"
#include "TDatList.h"
#include <iostream>


template<class TValue>
class TListHash : public THashTable<TValue>
{
 protected:
    PTDatList *pList; 
    int TabSize;      
    int CurrList;    
 public:
	 TListHash(int Size)
	 {
		 pList = new PTDatList[Size];
		 TabSize = Size;
		 CurrList = 0;
		 for (int i = 0; i < TabSize; ++i)
			 pList[i] = new TDatList;
	 }

	 ~TListHash()
	 {
		 for (int i = 0; i < TabSize; ++i)
			 delete pList[i];
		 delete[] pList;
	 }
    
  virtual int IsFull() const
	{
		return 0;
	}	

  virtual TKey GetKey() const
	{
		if (CurrList < 0 || CurrList >= TabSize)
			return "";
		PTTabRecord pRec = PTTabRecord(pList[CurrList]->GetDatValue());
		return pRec ? pRec->Key : "";
	}

  virtual PTDatValue GetValuePtr() const
	{
		if (CurrList < 0 || CurrList >= TabSize)
			return NULL;
		PTTabRecord pRec = PTTabRecord(pList[CurrList]->GetDatValue());
		return pRec ? pRec->pValue : NULL;
	}

  virtual PTDatValue FindRecord(TKey k)
	{
		PTDatValue pValue = NULL;
		CurrList = HashFunc(k) % TabSize;
		PTDatList pL = pList[CurrList];
		for (pL->Reset(); !pL->IsListEnded(); pL->GoNext()) 
		{
			if (PTTabRecord(pL->GetDatValue())->Key == k) 
			{
				pValue = PTTabRecord(pL->GetDatValue())->pValue;
				break;
			}
		}
		Efficiency += pL->GetCurrentPos() + 1;
		return pValue;
	}

  virtual void InsRecord(TKey k, PTDatValue pVal)
	{
		CurrList = HashFunc(k) % TabSize;
		pList[CurrList]->InsLast(new TTabRecord(k, pVal));
		++DataCount;
		++Efficiency;
	}

  virtual void DelRecord(TKey k)
	{
		CurrList = HashFunc(k) % TabSize;
		PTDatList pL = pList[CurrList];
		for (pL->Reset(); !pL->IsListEnded(); pL->GoNext()) 
		{
			++Efficiency;
			if (PTTabRecord(pL->GetDatValue())->Key == k) 
			{
				pL->DelCurrent();
				--DataCount;
				break;
			}
		}
	}

  virtual int Reset()
	{
		CurrList = 0;
		pList[CurrList]->Reset();
		return IsTabEnded();
	}

  virtual int IsTabEnded() const
	{
		return CurrList >= TabSize;
	}

  virtual int GoNext()
	{
		if (!pList[CurrList]->IsListEnded())
			pList[CurrList]->GoNext();
		while (pList[CurrList]->IsListEnded()) 
		{
			CurrList = (CurrList + 1) % TabSize;
			pList[CurrList]->Reset();
		}
		return IsTabEnded();
	}
};

