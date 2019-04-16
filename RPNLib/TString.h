#pragma once
#include <iostream>
#include "MyException.h"

class TString
{
protected:
  char* s;
  int length;

public:
  TString();
  TString(TString &A);
  TString(char* s);
  ~TString();

  int Len();
  void DeleteS();

  TString operator+(TString &A);
  TString& operator=(TString &A);
  char& operator[](int i);

  friend std::istream& operator>>(std::istream &A, TString &B);
  friend std::ostream& operator<<(std::ostream &A, const TString &B);
};