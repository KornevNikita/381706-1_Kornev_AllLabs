#include "Polinom.h"

TPolinom::TPolinom(int _n)
{
	if (_n < 0)
	{
		MyException ex(4, "Недопустимое значение");
		throw ex;
	}
	n = _n;
	size = 0;
	a = 0;
}

TPolinom::TPolinom(const TPolinom &A)
{
	size = A.size;
	n = A.n;
	if (A.a == 0)
		a = 0;
	else
	{
		a = new TMonom(*A.a);
		TMonom* tmp1 = A.a;
		TMonom* tmp2 = a;
		while (tmp1->GetNext() != 0)
		{
			tmp2->SetNext(new TMonom(*(tmp1->GetNext())));
			tmp2 = tmp2->GetNext();
			tmp1 = tmp1->GetNext();
		}
		tmp2->SetNext(NULL);
	}
}

TPolinom::~TPolinom()
{

}

TMonom* TPolinom::GetStart()
{
	return a;
}

int TPolinom::GetSize()
{
	return size;
}

TPolinom TPolinom::operator+(TPolinom &A)
{
	if (this->n != A.n)
	{
		MyException ex(85, "Разные размерности");
		throw ex;
	}
	TPolinom rez(n);
	TMonom *tmp1 = a,
		*tmp2 = A.a,
		*tmp = rez.a;
	while ((tmp1 != 0) && (tmp2 != 0))
	{
		TMonom *temp;
		if ((*tmp1) == (*tmp2))
		{
			TMonom t = *tmp1;
			t = t + *tmp2;
			temp = new TMonom(t);
			if (temp->GetC() == 0)
				continue;
			tmp1 = tmp1->GetNext();
			tmp2 = tmp2->GetNext();
		}
		else if ((*tmp1) < (*tmp2))
		{
			temp = new TMonom((*tmp2));
			if (temp->GetC() == 0)
				continue;
			tmp2 = tmp2->GetNext();
		}
		else if ((*tmp1) > (*tmp2))
		{
			temp = new TMonom((*tmp1));
			if (temp->GetC() == 0)
				continue;
			tmp1 = tmp1->GetNext();
		}
		if (tmp == 0)
		{
			tmp = temp;
			rez.a = temp;
			rez.size++;
		}
		else
		{
			temp->SetNext(temp);
			rez.size++;
			tmp = tmp->GetNext();
		}
	}
	if (tmp1 == 0)
		tmp1 = tmp2;
	while (tmp1 != 0)
	{
		if (tmp1->GetC() == 0)
			continue;
		tmp->SetNext(new TMonom(*tmp1));
		tmp1 = tmp1->GetNext();
		rez.size++;
		tmp = tmp->GetNext();
	}
	return rez;
}

TPolinom TPolinom::operator*(TPolinom &A)
{
	if (this->n != A.n)
	{
		MyException ex(85, "Разные размерности");
		throw ex;
	}
	TPolinom rez(n);
	TMonom *tmp1 = a;
	TMonom *tmp2 = A.a;
	while (tmp1 != 0)
	{
		while (tmp2 != 0)
		{
			TMonom temp1 = (*tmp1);
			temp1 = temp1 * (*tmp2);
			TMonom* temp2 = new TMonom(temp1);
			temp2->SetNext(NULL);
			rez += *temp2;
			tmp2 = tmp2->GetNext();
		}
		tmp1 = tmp1->GetNext();
		tmp2 = A.a;
	}
	return rez;
}

TPolinom& TPolinom::operator=(const TPolinom &A)
{
	if (&A == this)
		return *this;
	if (A.n != this->n)
	{
		MyException ex(85, "Разные размерности");
		throw ex;
	}
	else
	{
		TMonom* tmp1 = a;
		TMonom* tmp2 = a;
		while (tmp1 != 0)
		{
			tmp1 = tmp1->GetNext();
			delete tmp2;
			tmp2 = tmp1;
		}
		tmp1 = A.a;
		tmp2 = new TMonom(*A.a);
		a = tmp2;
		while (tmp1 != 0)
		{
			tmp2->SetNext(new TMonom(*tmp1));
			tmp1 = tmp1->GetNext();
			return *this;
		}
	}
}

TPolinom& TPolinom::operator +=(TMonom &A)
{
	if (this->n != A.GetN())
	{
		MyException ex(85, "Разные размерности");
		throw ex;
	}
	if (a == 0)
		a = new TMonom(A);
	else
	{
		TMonom *begin, *end;
		begin = a;
		end = a->GetNext();
		if (*a < A)
		{
			TMonom* tmp = new TMonom(A);
			tmp->SetNext(a);
			a = tmp;
		}
		else if (*a == A)
		{
			*a = A + *a;
			if (a->GetC() == 0)
			{
				TMonom* temp = a->GetNext();
				delete[] a;
				a = temp;
			}
		}
		else
		{
			while (end != 0)
			{
				if (*end == A)
				{
					*end = A + *end;
					if (end->GetC() == 0)
					{
						begin->SetNext(end->GetNext());
						delete[] end;
					}
					return *this;
				}
				if (*end < A)
				{
					TMonom* tmp = new TMonom(A);
					begin->SetNext(tmp);
					tmp->SetNext(end);
					size++;
					return *this;
				}
				begin = end;
				end = end->GetNext();
			}
			begin->SetNext(new TMonom(A));
		}
	}
	size++;
	return *this;
}

bool TPolinom::operator==(const TPolinom &A)
{
	if (this->n != A.n)
	{
		MyException ex(85, "Разные размерности");
		throw ex;
	}
	if (this->size != A.size)
		return false;
	TMonom* tmp1 = a;
	TMonom* tmp2 = A.a;
	while (tmp1 != 0)
	{
		if (!(*tmp1 == *tmp2))
			return false;
		if (tmp1->GetC() != tmp2->GetC())
			return false;
		tmp1 = tmp1->GetNext();
		tmp2 = tmp2->GetNext();
	}
	return true;
}

ostream& operator<<(ostream& ostr, TPolinom &A)
{
	TMonom *tmp = A.a;
	if (tmp != 0)
	{
		ostr << *tmp;
		tmp = tmp->GetNext();
	}
	while (tmp != 0)
	{
		if (tmp->GetC() != 0)
			ostr << " + " << *tmp;
		tmp = tmp->GetNext();
	}
	return ostr;
}