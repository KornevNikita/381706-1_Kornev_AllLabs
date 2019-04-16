#include "TText.h"

char* TText::Copy(int start, int n)
{
	char* res = new char[n];
	bool f = false;
	int pos = 0;
	TNodeIter t(root);
	t.operator++();
	for (int i = 0; i < n;)
	{
		if (t()->GetLevel() == 3)
		{
			pos++;
			if (pos == start)
				f = true;
			if (f)
			{
				res[i] = t()->GetData();
				i++;
			}
			t.operator++();
		}
	}
	return res;
}

void TText::Del(int start, int n)
{
	int pos = 0;
	for (TNodeIter i(root); !i.IsEnd(); i.operator++())
		if (i()->GetLevel() == 3)
		{
			pos++;
			TNode* t = i();
			for (int j = 0; j < n; j++)
			{
				t->GetSosed()->SetData(-1);
				t->SetSosed(t->GetSosed());
			}
		}
}

TNode* TText:: Find(char* a)
{
	int l = strlen(a);
	TNodeIter i(root);
	//bool f;
	i.operator++();
	for (; !i.IsEnd(); i.operator++())
		if (i()->GetData() == a[0])
		{
			bool f = true;
			TNodeIter j = i;
			for (int t = 0; t < l && !j.IsEnd(); t++)
				if (j()->GetData() != a[t])
				{
					f = false;
					break;
				}
			if (f)
				return i();
		}
	return NULL;
}

void TText::Insert(TNode* start, TNode* d)
{
	d->SetSosed(start->GetSosed());
	start->SetSosed(d);
}

int TText::FindIndex(char* a)
{
	return 0;
}
