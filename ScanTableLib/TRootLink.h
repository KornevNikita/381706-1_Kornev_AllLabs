#pragma once
#include "TDatValue.h"
#include <iostream>


class TRootLink;
typedef TRootLink *PTRootLink;

class TRootLink 
{
protected:
    PTRootLink pNext;  // ��������� �� ��������� �����
public:
    TRootLink(PTRootLink pN = NULL) { pNext = pN; }
    PTRootLink  GetNextLink() { return  pNext; }
    void SetNextLink(PTRootLink pLink) { pNext = pLink; }
    void InsNextLink(PTRootLink pLink)
		{
        PTRootLink p = pNext;
        pNext = pLink;
        if (pLink)
            pLink->pNext = p;
    }
    virtual void SetDatValue(PTDatValue pVal) = 0;
    virtual PTDatValue GetDatValue() = 0;

    friend class TDatList;
};

