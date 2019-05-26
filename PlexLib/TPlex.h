#include "TPoint.h"
#include "TSection.h"

class TPlex : public TPoint
{
protected:
	TPoint *l, *r;

public:
	void SetL(TPoint *_l);
	void SetR(TPoint *_r);
	TPoint* GetL();
	TPoint* GetR();

	TPlex();
	TPlex(TPoint *_l, TPoint *_r);
	TPlex(TPlex& P);

	virtual void show();

	void Add(TPoint *_A, TPoint *_B);
	TPoint* Search(TPoint *A);
};
