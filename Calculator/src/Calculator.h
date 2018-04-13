#include <iostream>
#include <string>
#include <sstream>
#ifndef CALCULATOR_H_
#define CALCULATOR_H_


using namespace std;



class Calculator {
public:
	//default constructor
	Calculator();

	//destructor
	virtual ~Calculator();

	//expression function
	double expression();

	//factor function
	double factor();

	//term function
	double term();

	//getter and setter functions
	void set_inp(char inp);
	char get_inp();

	//stringstream object
	stringstream ss;

	static int parenthesis_open;
	static int parenthesis_close;

private:
	double output;
	char input;

};

#endif
