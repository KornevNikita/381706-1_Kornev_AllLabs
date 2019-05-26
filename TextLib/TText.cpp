#include "TText.h"
#include "TLink.h"
#include <iostream>

using namespace std;

TText::TText() 
{}

void TText::GoNextLink() 
{
	if (this->pCurr->pNext != NULL)
	{
		st.push(this->pCurr);
		pCurr = this->pCurr->pNext;
	}
}


void TText::GoDownLink() 
{
	if (this->pCurr->pDown != NULL)
	{
		st.push(this->pCurr);
		pCurr = this->pCurr->pDown;
	}
}

void TText::GoPrevLink() {
	if (!st.empty())
	{
		this->pCurr = st.top();
		st.pop();
	}
}

void TText::InsNextLine(char *s) {
	TLink *p = new TLink(s, pCurr->pNext, NULL);
	pCurr->pNext = p;
}

void TText::InsNextSection(char *s) {
	TLink *p = new TLink(s, NULL, pCurr->pNext);
	pCurr->pNext = p;
}

void TText::InsDownLine(char *s) {
	TLink *p = new TLink(s, pCurr->pDown, NULL);
	pCurr->pDown = p;
}

void TText::InsDownSection(char *s) {
	TLink *p = new TLink(s, NULL, pCurr->pDown);
	pCurr->pDown = p;
}

void TText::DelNext() {
	if (pCurr->pNext != NULL)
	{
		TLink *p = pCurr->pNext;
		pCurr->pNext = p->pNext;
		delete p;
	}
}

void TText::DelDown() {
	if (pCurr->pDown != NULL)
	{
		TLink *p = pCurr->pDown;
		pCurr->pDown = p->pDown;
		delete p;
	}
}


void TText::Print() 
{
	level = 0;
	PrintText(pFirst);
}

void TText::PrintText(TLink *tmp)
{
	if (tmp != NULL)
	{
		if (pCurr == tmp)
			cout << "--> ";
		for (int i = 0; i < level; i++)
			cout << "    ";
		cout << tmp->str << endl;
		if (tmp->pDown != NULL)
		{
			level++;
			PrintText(tmp->pDown);
			level--;
		}
		if (tmp->pNext != NULL)
		{
			PrintText(tmp->pNext);
		}
	}
}


void TText::SaveText(TLink *tmp, ofstream& f) 
{
	f << tmp->str << endl;
	if (tmp->pDown != NULL)
	{
		f << "{\n";
		SaveText(tmp->pDown, f);
		f << "}\n";
	}
	if (tmp->pNext != NULL)
		SaveText(tmp->pNext, f);
}

void TText::Save(char *name) 
{
	ofstream ofs(name);
	SaveText(pFirst, ofs);
	ofs.close();
}

void TText::Reset() 
{
	while (!st.empty())
		st.pop();

	pCurr = pFirst;
	st.push(pCurr);
	if (pFirst->pDown != NULL)
		st.push(pFirst->pDown);

	if (pFirst->pNext != NULL)
		st.push(pFirst->pNext);
}

bool TText::IsEnd() 
{
	return st.empty();
}

void TText::GoNext() 
{
	if (!st.empty())
	{
		pCurr = st.top();
		st.pop();
	}

	if (pCurr != pFirst)
	{
		if (pCurr->pNext != NULL)
			st.push(pCurr->pNext);
		if (pCurr->pDown != NULL)
			st.push(pCurr->pDown);
	}
}

void TText::MarkCurr()
{
	pCurr->flag = true;
}

TLink* TText::GetCurr()
{
	return pCurr;
}