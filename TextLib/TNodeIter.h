#pragma once

#include "Stack.h"
#include "TNode.h"

class TNodeIter
{
protected:
	TNode* root;
	TNode* cur;
	TStack<TNode*> St;
public:
	TNodeIter(TNode* r);
	TNodeIter& GoNext();
	void Reset(); //ñáðîñ çíà÷åíèÿ è óñòàíîâêà óêàçàòåëÿ â íà÷àëî
	bool IsEnd();
	TNode* operator()();
	TNodeIter& operator++();
};
