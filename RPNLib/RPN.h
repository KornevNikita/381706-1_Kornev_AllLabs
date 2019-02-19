#pragma once
#include "Queue.h"
#include "TString.h"

int Priority(const char op);
bool IsOperator(char a);
TQueue<char> ToRPN(TString s);
double Result(TQueue<char> q);
