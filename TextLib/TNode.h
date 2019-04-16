#pragma once
#include "Queue.h"

//class TNode
//{
//protected:
//	TNode* s; // сосед
//	TNode* p; // потомок
//	char c; // значение элемента
//	int l; // уровень (0 - корень, 1 - строка, 2 - слово, 3 - буква)
//
//public:
//	TNode();
//	TNode(TNode &K);
//	TNode(TNode* _s, TNode* _p, char _c, int _l);
//	TNode* getS();
//	TNode* getP();
//	char getC();
//	int getL();
//
//	void setS(TNode* _s);
//	void setP(TNode* _p);
//	void setC(char _c);
//	void setL(int _l);
//	TNode& operator=(TNode& _elem);
//	char* ToChar();
//};

//=============================================================================

#include "MyException.h"
#include "Stack.h"
#include <string.h>

class TNode {

protected:
	TNode* nextLevel;
	TNode* sosed;
	int level;
	char data;
	static TNode* start;
	static TNode* end;
	static TNode* free;
	static char* mas; // íàáîð áàéòîâ
	static int sizeMas; //ðàçìåð ìàññèâà ïàìÿòè

public:
	TNode(char c);
	TNode(int _level);
	TNode(char* str);
	TNode(TNode& other);
	TNode& operator=(TNode& other);
	TNode& operator+=(TNode& other);
	TNode& operator+=(char c);
	TNode& operator+=(char *c);
	char* ToStr();
	TNode* Clone();
	static void Init(int size);
	void* operator new(size_t n);
	void operator delete(void* a);
	static void Dc(); //Ñáîðêà ìóñîðà
	TNode* GetSosed();
	void SetSosed(TNode* a);
	TNode* GetNextLevel();
	int GetLevel();
	void SetLevel(int l);
	char GetData();
	void SetData(char c);
	TNode* F()
	{
		return this;
	}
};
