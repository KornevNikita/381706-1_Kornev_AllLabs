#include "List.h"
int main(){
	TList<int> A;
	A.PutBegin(5);
	TList<int> B(A);
	return 0;
}