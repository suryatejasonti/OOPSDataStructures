//============================================================================
// Name        : ProgrammingPractice.cpp
// Author      : SuryaTSonti
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


/**
   Computes the smallest of four values.
*/
int min(int a, int b, int c, int d)
{
   int result = a;
   if (b < result) result = b;
   if (c < result) result = c;
   if (d < result) result = d;
   return result;
}
/**
   Computes the average of the middle values of four given values
   (that is, without the largest and smallest value).
   Hint: Use the given min function. You may also want to define a
   max helper function or take advantage of the fact that max can be
   computed from the min of the negative values.
*/
double middle(int a, int b, int c, int d)
{
	int minimum = min(a, b, c, d);
	int maximum = -min(-a, -b, -c, -d);
	cout << minimum << endl;
	cout << maximum << endl;
	if( ( minimum == b || minimum == c ) && ( maximum ==b  || maximum == c ) ){
		return (a+b)/2.0;
	}
	else if( ( minimum == b || minimum ==d ) && ( maximum == b || maximum ==d ) ){
				return (a+c)/2.0;
			}
	else if( ( minimum == b || minimum ==c ) && ( maximum == b || maximum ==c ) ){
				return (a+d)/2.0;
			}
	else if( ( minimum == a || minimum ==d ) && ( maximum == a || maximum ==d ) ){
		return (b+c)/2.0;
	}
	else if( ( minimum == b || minimum ==c ) && ( maximum == b || maximum ==c ) ){
				return (b+d)/2.0;
			}
	else if( ( minimum == a || minimum ==b ) && ( maximum == a || maximum ==d ) ){
					return (c+d)/2.0;
				}
	return 0;
}
/*
  Write a function that computes how many digits two positive
  integers m and n have in common. For example, if m is 112358 and
  n is 179881, then the result is 2 because the numbers have the digits
  1 and 8 in common. It does not matter how often a digit occurs.

  Hint: This loop yields all digits of a positive number n:

  while (n > 0)
  {
     int digit = n % 10;
     n = n / 10;
     // Process digit
  }
*/

// Add any helper functions here

int digitsInCommon(int m, int n)
{
	int second =m;//Store second number:- n, to loop this again with digits in first number.
	int digits[10]; int count =0; // variables to save different digits and digits common counter.
	for(int i =0; n > 0 ; i++)
	{
		int nNumber = n % 10;
		n = n / 10;
		m = second; // Make sure to do this as we are over writing m value.
		for(int j =0; m > 0 ; j++)
		{
			int mNumber = m % 10;
			m = m / 10;
			if(nNumber == mNumber) // check if you found a match.
			{
				int k=0;int repeat=0;
				do{
					if(digits[k] != nNumber)
					{
						repeat++;
					}
					k++;
				}while(k<count); // loop to identify digit already pre exists and is counted in digits.
				if(repeat>0) // Save counter and different digits if no repetition is found.
				{
					digits[count] = nNumber;
					count++;
				}
			}
		}
	}
	return count;
}
// Place any helper functions here

/*
  Write a function that converts US time with hours, minutes, seconds,
  am/pm to "decimal time". In decimal time, the day has ten "hours",
  of 100 "minutes" each, and each "minute" has 100 "seconds". Return
  a floating-point number whose integral part is the decimal hours
  and whose fractional part are 0.01 * decimal minutes + 0.0001 *
  decimal seconds. Round to the nearest decimal second. If the inputs
  are invalid, return -1.
*/
double decimal_time(int hours, int minutes, int seconds, bool pm)
{

}
int main()
{
	cout<< digitsInCommon(1203, 4126378) << endl;
	//cout << "!!!Hello World!!!" << middle(10, 24, 6, 5) << endl; // prints !!!Hello World!!!
	return 0;
}
