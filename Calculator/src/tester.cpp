//============================================================================
// Name        : Calculator.cpp
// Author      : SuryaTSonti
// Version     :
// Copyright   : Your copyright notice
// Description : Calculator in C++, Ansi-style
//============================================================================

#include<iostream>
#include<sstream>
#include<string>
#include "Calculator.h"

using namespace std;

int main()
{
	Calculator calculator;

	char c;
	string str;

	cout << "Expression?";

	getline(cin,str);	// reading enterred expression in a string
	calculator.ss << str;		// reading string to stringstream for operations
	calculator.ss >> c;
	calculator.set_inp(c);

	while ( c != '.')		// loop will run until '.' is entered
	{
		try								// checking for error
		{
			cout << calculator.expression() <<endl;
		}
		catch(const char* s)				// catching error
		{
			cout << s << endl;
		}
		cout << "Expression?";
		getline(cin,str);
		calculator.ss.str("");
		calculator.ss.clear();
		calculator.ss << str;
		calculator.ss >> c;

		calculator.set_inp(c);

	}
	cout << "Done!"<<endl;
}
