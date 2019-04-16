#include "TNodeIter.h"

TNodeIter::TNodeIter(TNode* r)
{
	TStack<TNode*> St(50);
	root = r;
	cur = r;
	St.Put(root);
}

TNodeIter& TNodeIter::GoNext()
{
	cur = St.Get();
	if (cur->GetSosed() != 0)
		St.Put(cur->GetSosed());
	if (cur->GetNextLevel() != 0)
		St.Put(cur->GetNextLevel());
	return *this;
}

void TNodeIter::Reset()
{
	cur = root;
	St.Clean();
	St.Put(cur);
}

bool TNodeIter::IsEnd()
{
	return St.IsEmpty();
}

TNode* TNodeIter::operator()()
{
	return cur;
}

TNodeIter& TNodeIter::operator++()
{
	return GoNext();
}
