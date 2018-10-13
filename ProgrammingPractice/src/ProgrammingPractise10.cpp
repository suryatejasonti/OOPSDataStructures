//============================================================================
// Name        : MidTerm.cpp
// Author      : SuryaTSonti
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Stack_V.h"
#include "DynamicStack.h"

using namespace std;

int main() {

	Stack<int> a;
	a.push(10);
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	cout<< a.size() << endl;
	cout << a.top() << endl;
	cout << a.pop() << endl;
	cout << a.size() << endl;

	DynamicStack<int> b;
	b.histogram();
	return 0;
}
