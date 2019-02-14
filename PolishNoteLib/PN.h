#pragma once
#include"Queue.h"
#include"MyException.h"

class PN 
{
  int size;
	char* mas;
	
public:
	PN();
	PN(int _size, char* _mas);
	PN(PN& other);
	char& operator[](int i);
	void Print();
	int GetSize();
	int Getprior(const char a);
	bool IsOperation(char a);
	double Result();
};

