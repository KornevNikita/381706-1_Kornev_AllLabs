#include "TNode.h"

//TNode:: TNode()
//{
//	s = 0;
//	p = 0;
//	l = 3;
//	c = 0;
//}
//
//TNode:: TNode(TNode &K)
//{
//	s = K.s;
//	p = K.p;
//	l = K.l;
//	c = K.c;
//}
//
//TNode:: TNode(TNode* _s, TNode* _p, char _c, int _l)
//{
//	s = _s;
//	p = _p;
//	c = _c;
//	l = _l;
//}
//
//TNode* TNode:: getS()
//{
//	return s;
//}
//
//TNode* TNode:: getP()
//{
//	return p;
//}
//
//char TNode:: getC()
//{
//	return c;
//}
//
//int TNode:: getL()
//{
//	return l;
//}
//
//void TNode:: setS(TNode* _s)
//{
//	s = _s;
//}
//
//void TNode:: setP(TNode* _p)
//{
//	p = _p;
//}
//
//void TNode::setC(char _c)
//{
//	c = _c;
//}
//
//void TNode:: setL(int _l)
//{
//	if (_l < 0 || _l > 3)
//		throw - 1;
//	l = _l;
//}
//
//TNode& TNode:: operator=(TNode& _elem)
//{
//	s = _elem.s;
//	p = _elem.p;
//	c = _elem.c;
//	l = _elem.l;
//	return *this;
//}

//char* TNode::ToChar()
//{
//	if (l == 3)
//	{
//		char* result = new char[2];
//		result[0] = c;
//		result[1] = 0;
//		return result;
//	}
//
//	else
//	{
//		TNode *i, *j;
//		bool isStop = false;
//		int n = 0;
//		i = p;
//		j = p->s;
//		TQueue <TNode*> q;
//		q.Put(i);
//
//		while (!isStop)
//		{
//			i = q.Get();
//			j = i->p;
//
//			if (j->l == 3)
//			{
//				while (j != 0)
//				{
//					n++;
//					j = j->s;
//				}
//			}
//			else
//			{
//				q.Put(i->s);
//				q.Put(i->p);
//			}
//			isStop = q.IsEmpty();
//		}
//	}
//}

//char* TNode:: ToChar()
//{
//	int l = 0;
//	int n = 0;
//	TStack <TNode*> st;
//	st.Put(this);
//
//	while (!st.IsEmpty())
//	{
//		TNode *t = st.Get();
//		if (t->getP() != 0)
//			st.Put(t->getP());
//
//		if (t->getS() != 0)
//			st.Put(t->getS());
//
//		if (t->getL() == 3)
//			l++;
//	}
//	 
//	char *res = new char[l + 1];
//	st.Put(this);
//	
//	while (!st.IsEmpty())
//	{
//		TNode *t = st.Get();
//		if (t->getL() == 3)
//		{
//			res[n] = t->getC();
//			n++;
//		}
//
//		if (t->getP() != 0)
//			st.Put(t->getP());
//
//		if (t->getS() != 0)
//			st.Put(t->getS());
//	}
//  
//	res[l] = 0;
//	return res;
//}

#include "TNode.h"

TNode* TNode::start = 0;
TNode* TNode::end = 0;
TNode* TNode::free = 0;
char* TNode::mas = 0;
int TNode::sizeMas = 0;

TNode::TNode(char c)
{
	data = c;
	nextLevel = sosed = NULL;
	level = 3;
}

TNode::TNode(int _level)
{
	if (_level >= 0 && _level < 4)
	{
		level = _level;
		data = 0;
		nextLevel = NULL;
		sosed = NULL;
	}
	else
	{
		MyException ex(15, "Некорректное значение уровня");
		throw ex;
	}
}

TNode::TNode(char* str)
{
	data = 0;
	nextLevel = new TNode(str[0]);
	level = 2;
	//	sosed = 0;
	TNode* b = nextLevel;
	int l = strlen(str);
	for (int i = 1; i < l; i++)
	{
		b->sosed = new TNode(str[i]);
		b = b->sosed;
	}
}

TNode::TNode(TNode& other)
{
	data = other.data;
	nextLevel = other.nextLevel;
	sosed = other.sosed;
	level = other.level;
}

TNode& TNode::operator=(TNode& other)
{
	if (this == &other)
		return *this;
	data = other.data;
	nextLevel = other.nextLevel;
	sosed = other.sosed;
	level = other.level;
	return *this;
}

/*TNode& TNode::operator+=(char c)
{
	TNode tmp(c);
	return (*this += tmp);
}*/

/*TNode& TNode::operator+=(TNode& a)
{
	if (level < a.level)
	{
		MyException ex(16, "Уровни не совпадают");
		throw ex;
	}
	TStack<TNode*> st;
	st.Put(this);
	bool f = true;
	while (f || st.IsEmpty())
	{
		TNode* t = st.Pow();
		if (t->nextLevel != NULL)
			st.Put(t->nextLevel);
		if (t->sosed != NULL)
			st.Put(t->sosed);
		if (t->level == a.GetLevel() && t->sosed == NULL)
		{
			f = false;
			t->sosed = a.Clone();
		}
	}
	return *this;
}*/

//char* TNode::ToStr()
//{
//	int l = 0;
//	int i = 0;
//	TStack<TNode*> st;
//	st.Put(this);
//	while (st.IsEmpty())
//	{
//		TNode* t = st.Put();
//		if (t->nextLevel != NULL)
//			st.Put(t->nextLevel);
//		if (t->sosed != NULL)
//			st.Put(t->sosed);
//		if (t->level == 3)
//			l++;
//	}
//	char* res = new char[l + 1];
//	st.Put(this);
//	while (!st.IsEmpty())
//	{
//		TNode* t = st.Pow();
//		if (t->level == 3)
//		{
//			res[i] = t->data;
//			i++;
//		}
//		if (t->sosed != NULL)
//			st.Put(t->sosed);
//		if (t->nextLevel != NULL)
//			st.Put(t->nextLevel);
//	}
//	res[i] = 0;
//	return res;
//}

char* TNode:: ToStr()
{
	int l = 0;
	int n = 0;
	TStack <TNode*> st;
	st.Put(this);

	while (!st.IsEmpty())
	{
		TNode *t = st.Get();
		if (t->GetNextLevel() != 0)
			st.Put(t->GetNextLevel());

		if (t->GetSosed() != 0)
			st.Put(t->GetSosed());

		if (t->GetLevel() == 3)
			l++;
	}

	char *res = new char[l + 1];
	st.Put(this);

	while (!st.IsEmpty())
	{
		TNode *t = st.Get();
		if (t->GetLevel() == 3)
		{
			res[n] = t->GetData();
			n++;
		}

		if (t->GetNextLevel() != 0)
			st.Put(t->GetNextLevel());

		if (t->GetSosed() != 0)
			st.Put(t->GetSosed());
	}

	res[l] = 0;
	return res;
}

/*TNode* TNode::Clone()
{
	TNode* res = new TNode(*this);
	TStack<TNode*> st;
	TStack<TNode*> copy;
	st.Put(this);
	copy.Put(res);
	while (!st.IsEmpty())
	{
		TNode* t = st.Pow();
		TNode* c = copy.Pow();
		if (t->sosed != 0)
		{
			c->sosed = new TNode(t->sosed);
			st.Put(t->sosed);
			copy.Put(t->sosed);
		}
		if (t->nextLevel != NULL)
		{
			//c->nextLevel = new TNode(t->nextLevel);
			st.Put(t->nextLevel);
			copy.Put(t->nextLevel);
		}
	}
	return res;
}*/

void TNode::Init(int size)
{
	if (mas == 0)
	{
		sizeMas = size;
		int l = size * sizeof(TNode);
		mas = new char(l);
		start = (TNode*)(mas); //преобразование первого элемента массива в указатель типа
		end = start;
		free = start;
		for (int i = 1; i < size; i++)
		{
			int j = i * sizeof(TNode);
			end->nextLevel = (TNode*)(&mas[j]);
		}
		end->nextLevel = 0;
	}
}

void* TNode::operator new(size_t n)
{
	TNode* result = free;
	if (free != NULL)
	{
		free = free->nextLevel;
		return result;
	}
}

void TNode::operator delete(void* a)
{
	TNode* t = (TNode*)(a);
	t->nextLevel = free;
	free = t;
	t->data = -1;
}

void TNode::Dc()
{
	free = 0;
	for (int i = 0; i < sizeMas; i++)
	{
		int j = i * sizeof(TNode);
		if (((TNode*)(&mas[j]))->data == -1)
		{
			((TNode*)(&mas[j]))->nextLevel = free;
			free = (TNode*)(&mas[j]);
		}
	}
}

TNode* TNode::GetSosed()
{
	return sosed;
}

void TNode::SetSosed(TNode* a)
{
	sosed = a;
}

TNode* TNode::GetNextLevel()
{
	return sosed;
}

int TNode::GetLevel()
{
	return level;
}

void TNode::SetLevel(int l)
{
	level = l;
}

char TNode::GetData()
{
	return data;
}

void TNode::SetData(char c)
{
	data = c;
}