#pragma once
#include "TLink.h"
#include <string>
#include <stack>
#include <iostream>
#include <fstream>

using namespace std;

class TText
{
private:
	TLink *pFirst;
	TLink *pCurr;
	stack <TLink*> st;
	int level;
public:
	TText();
	void GoNextLink();
	void GoDownLink();
	void GoPrevLink();
	void InsNextLine(char *s);
	void InsNextSection(char *s);
	void InsDownLine(char *s);
	void InsDownSection(char *s);
	void DelNext();
	void DelDown();

	void PrintText(TLink *tmp);
	void Print();
	void SaveText(TLink *tmp, ofstream& f);
	void Save(char *name);

	void Reset();
	bool IsEnd();
	void GoNext();

	void MarkCurr();
	TLink* GetCurr();
};