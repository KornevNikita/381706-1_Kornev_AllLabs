#pragma once
#include "TNode.h"

//class TText
//{
//protected:
//	TNode *root;
//
//public:
//	TText();
//	TText(TText &T);
//	TText(char *c = 0);
//
//	TText &operator= (TText &A);
//	TText &operator+=(char *str);
//
//	TNode* Copy(int start, int n);
//	TNode* Find(char *a);
//	int FindIndex(char *a);
//	void Insert(TNode *start, TNode* d);
//	
//};

//====================================================

#include "TNodeIter.h"

class TText
{
protected:
	TNode* root;
public:
	TText();
	char* Copy(int start, int n);
	void Del(int start, int n);
	void Insert(TNode* start, TNode* d);
	TNode* Find(char* a);
	int FindIndex(char* a);
};