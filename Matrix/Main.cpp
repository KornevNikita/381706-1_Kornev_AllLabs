#include "Matrix.h"

int main(){
try {
	TMatrix<int> A(3);
	A[0][0] = 1;
	cout << A;
}
catch (MyException ex) {
	ex.Print();
}
	return 0;
}
