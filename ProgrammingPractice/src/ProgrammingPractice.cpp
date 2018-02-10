//============================================================================
// Name        : ProgrammingPractice.cpp
// Author      : SuryaTSonti
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

/*
 * Question 1
 */
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
 * Question 2
 */

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
int n1=0, n2=0, n3=0, n4=0, n5=0, n6=0, n7=0, n8=0, n9=0, n0=0;
// Add any helper functions here
bool searchNumber(int number)
{
	switch(number)
	{
		case 0:
			if(n0 == 0)
			{
				n0++	;
				return false;
			}
			break;
		case 1:
			if(n1 == 0)
			{
				n1++	;
				return false;
			}
			break;
		case 2:
			if(n2 == 0)
			{
				n2++	;
				return false;
			}
			break;
		case 3:
			if(n3 == 0)
			{
				n3++	;
				return false;
			}
			break;
		case 4:
			if(n4 == 0)
			{
				n4++	;
				return false;
			}
			break;
		case 5:
			if(n5 == 0)
			{
				n5++	;
				return false;
			}
			break;
		case 6:
			if(n6 == 0)
			{
				n6++	;
				return false;
			}
			break;
		case 7:
			if(n7 == 0)
			{
				n7++	;
				return false;
			}
			break;
		case 8:
			if(n8 == 0)
			{
				n8++	;
				return false;
			}
			break;
		case 9:
			if(n9 == 0)
			{
				n9++	;
				return false;
			}
			break;
	}
	return true;
}
int digitsInCommon(int m, int n)
{
	int second =m;//Store second number:- n, to loop this again with digits in first number.
	int count =0; // variables to save different digits and digits common counter.
	for( int i =0; n > 0 ; i++ )
	{
		int nNumber = n % 10;
		n = n / 10;
		m = second; // Make sure to do this as we are over writing m value.
		for( int j =0; m > 0 ; j++ )
		{
			int mNumber = m % 10;
			m = m / 10;

			if( nNumber == mNumber && !searchNumber(nNumber)) // check if you found a match.
			{
				count++; // Save counter and different digits if no repetition is found.
			}
		}
	}
	return count;
}

/*
 * Question 3
 */

// Place any helper functions here
double ceil(double v, int p)
{
  v *= pow(10, p);
  v = ceil(v);
  v /= pow(10, p);
}
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

	if( hours <= 0 || minutes < 0 || seconds < 0 || hours > 24 || minutes > 60 || seconds > 60 )
		return -1;
	return ceil( ( ( pm == true ? ( hours == 12 ? 12 : ( hours + 12 ) ) : ( hours == 12 ? 0 : hours ) ) * ( 10.0 / 24 ) )
					+ ( minutes / ( 24.0 * 60.0 * 0.1 ) )
					+ ( seconds / ( 24.0 * 60.0 * 60.0 * 0.1 ) ) , 4);
}

/*
 * Question 4
 */
/*
  The Chevalier de Blasé, a notorious 17th century gambler, wanted to
  know whether he had higher odds of winning a dice game with four
  dice, where a win meant a pair of 5s and a pair of 6s, or a game
  with six dice, where a win meant four sixes (and two dice
  that are not a six).

  Help him out by writing a simulation that "throws" virtual dice
  with a random number generator.
*/

/*
  Return a random number between 1 and 6.
*/
int die_toss()
{
   return 1 + rand() % 6;
}

/*
  Return true if you got a pair of 5s and 6s.
*/
int game1_wins(int a, int b, int c, int d)
{
	return ( ( a == 5 && b == 5 && c == 6 && d == 6 )
			|| ( a == 6 && b == 6 && c == 5 && d == 5 )
			|| ( a == 5 && b == 6 && c == 5 && d == 6 )
			|| ( a == 6 && b == 5 && c == 6 && d == 5 )
			|| ( a == 5 && b == 6 && c == 6 && d == 5 )
			|| ( a == 6 && b == 5 && c == 5 && d == 6 ) ) ? 1 : 0;
}

/*
  Return true if you got four 6s.
*/
int game2_wins(int a, int b, int c, int d, int e, int f)
{
	return ( ( a == 6 ) + ( b == 6 ) + ( c == 6 ) + ( d == 6 ) + ( e == 6 ) + ( f == 6 ) ) == 4 ? 1: 0;
}
/*
  Play game 1 for the given number of iterations and return the
  number of wins.
*/
int game1(int iterations)
{
	int wins =0;
	while( iterations > 0 )
	{
		if( game1_wins( die_toss(), die_toss(), die_toss(), die_toss() ) == 1)
			wins++;
		iterations--;
	}
	return wins;
}
/*
  Play game 2 for the given number of iterations and return the
  number of wins.
*/
int game2(int iterations)
{
	int wins =0;
		while( iterations > 0 )
		{
			if( game2_wins( die_toss(), die_toss(), die_toss(), die_toss(), die_toss(), die_toss() ) == 1)
				wins++;
			iterations--;
		}
		return wins;
}

/*
 * Question 5
 */
/*
  Returns a random number between 0 and 1.
*/
double rand_double()
{
   return rand() * 1.0 / RAND_MAX;
}

/*
  The "Las Vegas" method of finding the area of a circle works
  as follows. Consider a square with side length r with a
  quarter circle inscribed, like in this ASCII art:

r .....
  |    ....
  |        ...
  |   (x,y)   .
  |  *         .
  |            .
  +------------.
(0, 0)         r

  Take a machine gun and fire bullets into the square. If
  a bullet lands inside the quarter circle, it's a hit. Otherwise
  it's a miss. The ratio of hits to tries is proportional to
  the ratio of the areas of the quarter circle and the square.

  Generate random points (x, y) in the square. Check whether they
  are inside the circle. Return the ratio of hits to tries.

 */
double inside_quarter_circle(double radius, int tries)
{
	double xCor, yCor; int hits=0;
	for( int i =0; i < tries; i++ )
	{
		xCor = rand_double();
		yCor = rand_double();
		if( xCor * xCor + yCor * yCor <= 1 )
		  hits++;
	}
	return (double)hits / tries;
}
int main()
{
	/*
	 * Question 1
	 */
	//cout << "!!!Hello World!!!" << middle(10, 24, 6, 5) << endl; // prints !!!Hello World!!!
	/*
	 * Question 2
	 */
	//cout<< digitsInCommon(1234567890, 987654321) << endl;
	/*
	 * Question 3
	 */
	//cout << decimal_time(9, 0, 0, false) << endl;
	/*
	 * Question 4
	 */
//	srand(42);
//	cout << game1(1000) << endl;
//	cout << game2(1000) << endl;
//	cout << game1(10000) << endl;
//	cout << game2(10000) << endl;
//	cout << game1(100000) << endl;
//	cout << game2(100000) << endl;
//	cout << game1(1000000) << endl;
//	cout << game2(1000000) << endl;
//
//	/*
//	 * Question 5
//	 */
	srand(42);
	cout << inside_quarter_circle(1, 1000) << endl;
	cout << inside_quarter_circle(20, 1000) << endl;
	// Approximating pi
	cout << 4 * inside_quarter_circle(1, 10000000) << endl;
	return 0;
}
