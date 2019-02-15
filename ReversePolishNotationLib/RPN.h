#include<string>
#include"Queue.h"
#include"MyException.h"
#include<ctype.h>
using namespace std;

int Priority(const char ch);
//bool IsOperator(char ch);

TQueue<char> ToRPN (string str);
double Res (TQueue<char> q);

bool isnumber(char ch);


 