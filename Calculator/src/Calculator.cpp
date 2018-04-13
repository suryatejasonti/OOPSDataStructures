#include "Calculator.h"

int Calculator::parenthesis_open = 0;
int Calculator::parenthesis_close = 0;


Calculator::Calculator()
{
	output = 0;
	input = 0;
}

Calculator::~Calculator(){}

void Calculator::set_inp(char inp)
{
	input = inp;
}

char Calculator::get_inp()
{
	return input;
}

double Calculator::expression()
{
	output = term();

	while(!ss.eof())
	{
		char c;
		ss >> c;

		if (c == '+')
		{
			double temp;
			temp = term();
			output = output + temp;
		}
		else if (c == '-')
		{
			double temp;
			temp = term();
			output = output - temp;
		}
		else if ( c == '*')
		{
			ss.unget();
			output = term();
		}
		else if ( c == '/')
		{
			ss.unget();
			output = term();
		}
	}
	return output;
}

double Calculator::term()
{
	double outputt = factor();

	while(!ss.eof())
	{
		char c;

		ss >> c;
		if ( c == '*')
		{
			double temp;
			temp = factor();
			outputt = outputt*temp;
		}
		else if (c == '/')
		{
			double temp;
			temp = factor();
			if (temp != 0 )
			{
				outputt = outputt / temp;
			}
			else
			{
				throw  "***** Division by zero";
			}
		}
		else if (c == '+')
		{
			ss.unget();
			return outputt;
		}
		else if (c == '-')
		{
			ss.unget();
			return outputt;
		}
		else if ( c == '%')
		{
			cout << outputt << endl;
			throw "***** Unexpected %";

		}
	}
	return outputt;
}

double Calculator::factor()
{
	char c;
	double outputf = 0;

	if (this->get_inp())
	{
		c = this->get_inp();
		this->set_inp(0);
	}
	else
	{
		ss >> c;
	}
	if ( c >= '0' && c <='9')
	{
		ss.unget();
		ss >> outputf;
		return outputf;
	}
	else if ( c == '(')
	{
		outputf = expression();
	}
	return outputf;
}
