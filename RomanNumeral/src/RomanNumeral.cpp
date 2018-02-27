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



RomanNumeral::RomanNumeral(string roman)
{
	this->roman = roman;
	decimal =to_decimal(roman);
}
RomanNumeral::RomanNumeral(int decimal)
{
	this->decimal = decimal;
	roman = to_roman(decimal);
}
int RomanNumeral::get_decimal() const
{
	return this->decimal;
}

string RomanNumeral::get_roman() const
{
	return this->roman;
}

// This function returns value of a Roman symbol
int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;

    return -1;
}

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
// To add corresponding base symbols in the array
// to handle cases which follow subtractive notation.
// Base symbols are added index 'i'.
int sub_digit(char num1, char num2, int i, char *c)
{
    c[i++] = num1;
    c[i++] = num2;
    return i;
}

// To add symbol 'ch' n times after index i in c[]
int digit(char ch, int n, int i, char *c)
{
    for (int j = 0; j < n; j++)
        c[i++] = ch;
    return i;
}
string RomanNumeral::to_roman(int decimal)
{
	char c[10001];
	int i = 0;
	string result;
	// If number entered is not valid
	if (decimal <= 0)
	{
		result = "Invalid number";
		return result;
	}

	// TO convert decimal number to roman numerals
	while (decimal != 0)
	{
		// If base value of number is greater than 1000
		if (decimal >= 1000)
		{
			// Add 'M' number/1000 times after index i
			i = digit('M', decimal/1000, i, c);
			decimal = decimal%1000;
		}

		// If base value of number is greater than or
		// equal to 500
		else if (decimal >= 500)
		{
			// To add base symbol to the character array
			if (decimal < 900)
			{
			   // Add 'D' number/1000 times after index i
			   i = digit('D', decimal/500, i, c);
			   decimal = decimal%500;
			}

			// To handle subtractive notation in case of number
			// having digit as 9 and adding corresponding base
			// symbol
			else
			{
				// Add C and M after index i/.
				i = sub_digit('C', 'M', i, c);
				decimal = decimal%100 ;
			}
		}

		// If base value of number is greater than or equal to 100
		else if (decimal >= 100)
		{
			// To add base symbol to the character array
			if (decimal < 400)
			{
				i = digit('C', decimal/100, i, c);
				decimal = decimal%100;
			}

			// To handle subtractive notation in case of number
			// having digit as 4 and adding corresponding base
			// symbol
			else
			{
				i = sub_digit('C','D',i,c);
				decimal = decimal%100;
			}
		}

		// If base value of number is greater than or equal to 50
		else if (decimal >= 50 )
		{
			// To add base symbol to the character array
			if (decimal < 90)
			{
				i = digit('L', decimal/50,i,c);
				decimal = decimal%50;
			}

			// To handle subtractive notation in case of number
			// having digit as 9 and adding corresponding base
			// symbol
			else
			{
				i = sub_digit('X','C',i,c);
				decimal = decimal%10;
			}
		}
		// If base value of number is greater than or equal to 10
		else if (decimal >= 10)
		{
			// To add base symbol to the character array
			if (decimal < 40)
			{
				i = digit('X', decimal/10,i,c);
				decimal = decimal%10;
			}

			// To handle subtractive notation in case of
			// number having digit as 4 and adding
			// corresponding base symbol
			else
			{
				i = sub_digit('X','L',i,c);
				decimal = decimal%10;
			}
		}

		// If base value of number is greater than or equal to 5
		else if (decimal >= 5)
		{
			if (decimal < 9)
			{
				i = digit('V', decimal/5,i,c);
				decimal = decimal%5;
			}

			// To handle subtractive notation in case of number
			// having digit as 9 and adding corresponding base
			// symbol
			else
			{
				i = sub_digit('I','X',i,c);
				decimal = 0;
			}
		}

		// If base value of number is greater than or equal to 1
		else if (decimal >= 1)
		{
			if (decimal < 4)
			{
				i = digit('I', decimal,i,c);
				decimal = 0;
			}

			// To handle subtractive notation in case of
			// number having digit as 4 and adding corresponding
			// base symbol
			else
			{
				i = sub_digit('I', 'V', i, c);
				decimal = 0;
			}
		}
	}
	result = c;
	return result;
}

RomanNumeral RomanNumeral::operator + (const RomanNumeral& romannumeral) const
{
	int a = decimal + romannumeral.get_decimal();
	RomanNumeral result(a);
	return result;
}

RomanNumeral RomanNumeral::operator - (const RomanNumeral& romannumeral) const
{
	RomanNumeral result(decimal + romannumeral.get_decimal());
	return result;
}

RomanNumeral RomanNumeral::operator * (const RomanNumeral& romannumeral) const
{
	RomanNumeral result(decimal * romannumeral.get_decimal());
	return result;
}

RomanNumeral RomanNumeral::operator / (const RomanNumeral& romannumeral) const
{
	RomanNumeral result(decimal / romannumeral.get_decimal());
	return result;
}

bool RomanNumeral::operator == (const RomanNumeral& romannumeral) const
{
	return decimal == romannumeral.get_decimal() ? true : false;
}

bool RomanNumeral::operator != (const RomanNumeral& romannumeral) const
{
	return decimal == romannumeral.get_decimal() ? false : true;
}

ostream & operator << (ostream &output, const RomanNumeral &romannumeral)
{
	output << "[" << romannumeral.get_decimal() << ":" << romannumeral.get_roman() << "]";
	return output;
}

ifstream & operator >> (ifstream &input, RomanNumeral &romannumeral)
{
	input >> romannumeral.roman;
	return input;
}

