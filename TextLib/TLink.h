#pragma once
#include "TText.h"
#include <string>
#include <iostream>

class TLink;

struct TMem
{
	TLink* pFirst;
	TLink *pFree;
	TLink *pLast;
};

class TLink
{
public:
	char str[80];
	TLink *pNext;
	TLink *pDown;
	static TMem mem;
	bool flag;

	TLink(char *s = NULL, TLink * pN = NULL, TLink *pD = NULL)
	{
		pNext = pN;
		pDown = pD;

		if (s == NULL)
			str[0] = '\0';
		strcpy(str, s);
	}
	~TLink();
	void SetLine(char *s);
	char* GetLine();
	void* operator new(size_t s);
	void operator delete(void* p);
	static void InitMem(int s);
	static int PrintFree(TText &t);
	static void MemClean(TText &t);
};
