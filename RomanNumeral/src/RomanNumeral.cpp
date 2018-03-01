//============================================================================
// Name        : RomanNumerals.cpp
// Author      : SuryaTSonti
// Version     :
// Copyright   : Your copyright notice
// Description :Design and implement a C++ class RomanNumeral that reads, writes, and performs
//arithmetic operations on Roman numerals  in C++, Ansi-style
//============================================================================


#include "RomanNumeral.h"

using namespace std;

//DEfault constructor
RomanNumeral::RomanNumeral()
{
	this->roman = "";
	this->decimal = 0;
}
//Constructor with string argument
RomanNumeral::RomanNumeral(string roman)
{
	this->roman = roman;
	decimal =to_decimal(roman);
}
//construct with decimal argument
RomanNumeral::RomanNumeral(int decimal)
{
	this->decimal = decimal;
	roman = to_roman(decimal);
}

// This function returns value of a Roman symbol
int value(char ch)
{
	switch(ch)
	{
		case 'I':
			return 1;
			break;
		case 'V':
			return 5;
			break;
		case 'X':
			return 10;
			break;
		case 'L':
			return 50;
			break;
		case 'C':
			return 100;
			break;
		case 'D':
			return 500;
			break;
		case 'M':
			return 1000;
			break;
		default:
			return -1;
			break;
	}
}
/*
 * private method used for converting string to decimal value
 */
int RomanNumeral::to_decimal(string &roman)
{
	// Initialize result
	int res = 0;

	// Traverse given input
	for (int i=0; i<roman.length(); i++)
	{
		// Getting value of symbol s[i]
		int s1 = value(roman[i]);

		if (i+1 < roman.length())
		{
			// Getting value of symbol s[i+1]
			int s2 = value(roman[i+1]);

			// Comparing both values
			if (s1 >= s2)
			{
				// Value of current symbol is greater
				// or equal to the next symbol
				res = res + s1;
			}
			else
			{
				res = res + s2 - s1;
				i++; // Value of current symbol is
					 // less than the next symbol
			}
		}
		else
		{
			res = res + s1;
			i++;
		}
	}
	return res;
}
/*
 * private method converting decimal to roman from decimal from 1 to 3999
 * identify the index in array and add string to result after getting each character
 */
string RomanNumeral::to_roman(int decimal)
{
	//result variable to store result
    string result;
    //char M array to get M in decimal value
    string M[] = {"","M","MM","MMM"};
    //char C array to get M in decimal value and combinations with D, M, C
    string C[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    //char X array to get X in decimal value and combinations with L, X, C
    string X[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    //char I array to get I in decimal value and combinations with I, V
    string I[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    result = M[decimal/1000]+C[(decimal%1000)/100]+X[(decimal%100)/10]+I[(decimal%10)];
    return result;
}

//public method to get decimal value from roman
int RomanNumeral::get_decimal() const
{
	return this->decimal;
}
//public method to get string from decimal value
string RomanNumeral::get_roman() const
{
	return this->roman;
}

//Overloading opeator for addition
RomanNumeral RomanNumeral::operator + (const RomanNumeral& romannumeral) const
{
	int a = decimal + romannumeral.get_decimal();
	RomanNumeral result(a);
	return result;
}
//Overloading opeator for substraction
RomanNumeral RomanNumeral::operator - (const RomanNumeral& romannumeral) const
{
	RomanNumeral result(decimal - romannumeral.get_decimal());
	return result;
}
//Overloading opeator for multiply
RomanNumeral RomanNumeral::operator * (const RomanNumeral& romannumeral) const
{
	RomanNumeral result(decimal * romannumeral.get_decimal());
	return result;
}
//Overloading opeator for division
RomanNumeral RomanNumeral::operator / (const RomanNumeral& romannumeral) const
{
	RomanNumeral result(decimal / romannumeral.get_decimal());
	return result;
}
//Overloading opeator for equal comparison
bool RomanNumeral::operator == (const RomanNumeral& romannumeral) const
{
	return decimal == romannumeral.get_decimal() ? true : false;
}
//Overloading opeator for not equal comparison
bool RomanNumeral::operator != (const RomanNumeral& romannumeral) const
{
	return decimal == romannumeral.get_decimal() ? false : true;
}
//Overloading opeator for output stream
ostream & operator << (ostream &output, const RomanNumeral &romannumeral)
{
	output << "[" << romannumeral.decimal << ":" << romannumeral.roman << "]";
	return output;
}
//Overloading opeator for input stream
istream & operator >> (istream &input, RomanNumeral &romannumeral)
{
	input >> romannumeral.roman;
	romannumeral.decimal = romannumeral.to_decimal(romannumeral.roman);
	return input;
}

