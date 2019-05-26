#include <iostream>
#include "TText.h"

using namespace std;

int main()
{
	TLink link("String");
	TText text;
	text.InsNextLine("S");
	text.InsNextLine("t");
	text.InsNextLine("r");
	text.Print();
	text.PrintText(&link);
	return 0;
}
