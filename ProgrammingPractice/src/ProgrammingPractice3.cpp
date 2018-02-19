//============================================================================
// Name        : ProgrammingPractice2.cpp
// Author      : SuryaTSonti
// Version     :
// Copyright   : Your copyright notice
// Description : Practice questions in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstring>
#include <chrono>

using namespace std;
using namespace std::chrono;


/**
   Compute the minimum and maximum value in an array.
   @param arr the array
   @param n the length of the array
   @param min a pointer to a variable holding the minimum
   @param max a pointer to a variable holding the minimum
*/
void minmax(int* arr, int n, int* min, int* max);


void minmax(int* arr, int n, int* min, int* max)
{
	for( int i = 0; i < n; i++ )
	{
	  if( i == 0 )
	  {
		 *min = arr[0];
		 *max = arr[0];
	  }
	  if( arr[i] < *min )
		  *min = arr[i];
	  if( arr[i] > *max )
	  		  *max = arr[i];
	}
}

/*
  Return a pointer to the nth occurrence of a repeated character
  in the given string. For example, if str is "occurrence" and n is 2,
  return a pointer to the first r.
*/
const char* nthrep(const char* str, int n);

const char* nthrep(const char* str, int n)
{
	int r = 0; char c = '\0';
	for (int i = 0; i < strlen(str) - 1; i++)
	{
		if ( c != str[i] && str[i] == str[i+1] )
		{
			r++;
			c = str[i];
		}

		if( r == n )
			return &str[i];
	}
	return NULL;
}

/*
  Repeats a string n times and places it into a buffer, filling
  it up as much as possible, and providing a terminating 0.
  Use strncpy.
  @param str a string
  @param n an integer
  @param result a character array to hold the result
  @param sz the size of result
*/
void repeat(const char* str, int n, char result[], int sz);

void repeat(const char* str, int n, char result[], int sz)
{
	char temp[strlen(str) * n];
	for(int i =0; i < sz-1; i++ )
	{
		temp[i] = str[(i+strlen(str))%strlen(str)];
	}
	temp[sz-1] = '\0';
	strncpy( result, temp,  sz);
}

/**
   Duplicate the beginning and the end of the given array
   numbers. You are given the number of elements of the array.

   For example, 1 2 4 8 should turn into 1 1 2 4 8 8.

   Allocate a new array and place all numbers into it (that is,
   the duplicates at the beginning and the end, and all numbers
   in between).

   If the array is empty, return an array holding two zeroes.

   Use the C++ style new operator.

   Return a pointer to the new array. Do not modify the original array.
*/
void print_array(int a[], int n)
{
   if (n == 0) { cout << "{}" << endl; return; }
   cout << "{ ";
   for (int i = 0; i < n; i++)
   {
      if (i > 0) cout << ", ";
      cout << a[i];
   }
   cout << " }" << endl;
}


int* dupefirstlast(int numbers[], int size);

int* dupefirstlast(int numbers[], int size)
{
	int *array = new int[ size + 2 ];
	if( size == 0 )
	{
		array[0]=0;array[1] = 0;
	}
	else
	{
		array[0] = numbers[0];
		for( int i = 0; i < size; i++ )
		{
			array[i+1] = numbers[i];
		}
		array[ size +1] = numbers[size-1];
	}

	return array;
}

/*
  You are given two time intervals with given start and end.
  Compute the number of seconds in their overlap, or 0 if the
  time intervals don't overlap.
*/
int seconds_in_overlap(steady_clock::time_point start1,
   steady_clock::time_point end1,
   steady_clock::time_point start2,
   steady_clock::time_point end2);

int seconds_in_overlap(steady_clock::time_point start1,
   steady_clock::time_point end1,
   steady_clock::time_point start2,
   steady_clock::time_point end2)
{
	int overlap;
	if( time_point_cast<seconds>(start1).time_since_epoch().count() <= time_point_cast<seconds>(start2).time_since_epoch().count()
			&& time_point_cast<seconds>(end1).time_since_epoch().count() <= time_point_cast<seconds>(end2).time_since_epoch().count() )
		overlap = time_point_cast<seconds>(end1).time_since_epoch().count() - time_point_cast<seconds>(start2).time_since_epoch().count();

	if( time_point_cast<seconds>(start1).time_since_epoch().count() <= time_point_cast<seconds>(start2).time_since_epoch().count()
				&& time_point_cast<seconds>(end2).time_since_epoch().count() <= time_point_cast<seconds>(end1).time_since_epoch().count() )
		overlap = time_point_cast<seconds>(end2).time_since_epoch().count() - time_point_cast<seconds>(start2).time_since_epoch().count();

	if( time_point_cast<seconds>(start2).time_since_epoch().count() <= time_point_cast<seconds>(start1).time_since_epoch().count()
				&& time_point_cast<seconds>(end1).time_since_epoch().count() <= time_point_cast<seconds>(end2).time_since_epoch().count() )
		overlap = time_point_cast<seconds>(end1).time_since_epoch().count() - time_point_cast<seconds>(start1).time_since_epoch().count();

	if( time_point_cast<seconds>(start2).time_since_epoch().count() <= time_point_cast<seconds>(start1).time_since_epoch().count()
					&& time_point_cast<seconds>(end2).time_since_epoch().count() <= time_point_cast<seconds>(end1).time_since_epoch().count() )
		overlap = time_point_cast<seconds>(end2).time_since_epoch().count() - time_point_cast<seconds>(start1).time_since_epoch().count();

	return overlap < 0 ? 0 : overlap;
}

int main()
{
//	int a[] = { 1, 4, 9, -4, 8, 0 };
//	int r1 = -999;
//	int r2 = -999;
//	minmax(a, sizeof(a) / sizeof(a[0]), &r1, &r2);
//	cout << r1 << " " << r2 << endl;
//	cout << "Expected: -4 9" << endl;
//
//	int b[] = { 1 };
//	r1 = -999;
//	r2 = -999;
//	minmax(b, sizeof(b) / sizeof(b[0]), &r1, &r2);
//	cout << r1 << " " << r2 << endl;
//	cout << "Expected: 1 1" << endl;
//
//	int c[] = { 1, 4, 9, -4, 8, 0, 11, 23, -12 };
//	r1 = -999;
//	r2 = -999;
//	minmax(c, sizeof(c) / sizeof(c[0]), &r1, &r2);
//	cout << r1 << " " << r2 << endl;
//	cout << "Expected: -12 23" << endl;
//
//	r1 = -999;
//	r2 = -999;
//	minmax(c, 0, &r1, &r2);
//	cout << r1 << " " << r2 << endl;
//	cout << "Expected: -999 -999" << endl;

//	const char* p = "occurrence";
//	const char* r = nthrep(p, 1);
//	cout << r - p << endl;
//	cout << "Expected: 1" << endl;
//	r = nthrep(p, 2);
//	cout << r - p << endl;
//	cout << "Expected: 4" << endl;
//	r = nthrep(p, 3);
//	cout << boolalpha << (r == NULL) << endl;
//	cout << "Expected: true" << endl;
//	p = "abbaccccaddabbra";
//	r = nthrep(p, 2);
//	cout << r - p << endl;
//	cout << "Expected: 4" << endl;
//	r = nthrep(p, 3);
//	cout << r - p << endl;
//	cout << "Expected: 9" << endl;

//	char results[28];
//	char* r2 = results;
//	char* r1 = results + 10;
//	char* r4 = results + 21;
//	char* r3 = results + 22;
//	char* r5 = results + 26;
//	strcpy(r5, "x");
//	repeat("Hello", 2, r1, 11);
//	repeat("Goodbye", 3, r2, 10);
//	repeat("Goodbye", 3, r3, 4);
//	repeat("HI", 10, r4, 1);
//	cout << r1 << endl;
//	cout << "Expected: HelloHello" << endl;
//	cout << r2 << endl;
//	cout << "Expected: GoodbyeGo" << endl;
//	cout << r3 << endl;
//	cout << "Expected: Goo" << endl;
//	cout << "\"" << r4 << "\"" << endl;
//	cout << "Expected: \"\"" << endl;
//	cout << "\"" << r5 << "\"" << endl;
//	cout << "Expected: \"x\"" << endl;

//	int a[] = { 1, 4, 9, 16, 25, 36, 49, 64};
//	int* b = dupefirstlast(a, 8);
//	print_array(b, 10);
//	cout << "Expected: { 1, 1, 4, 9, 16, 25, 36, 49, 64, 64 }" << endl;
//	delete[] b;
//
//	int* c = dupefirstlast(a, 3);
//	print_array(c, 5);
//	cout << "Expected: { 1, 1, 4, 9, 9 }" << endl;
//	delete[] c;
//
//	int* d = dupefirstlast(a, 5);
//	print_array(d, 7);
//	cout << "Expected: { 1, 1, 4, 9, 16, 25, 25 }" << endl;
//	delete[] d;
//
//	int* e = dupefirstlast(a, 0);
//	print_array(e, 2);
//	cout << "Expected: { 0, 0 }" << endl;
//	delete[] e;
//
//	int* f = dupefirstlast(a, 1);
//	print_array(f, 3);
//	cout << "Expected: { 1, 1, 1 }" << endl;
//	delete[] f;

	steady_clock::time_point now = steady_clock::now();
	steady_clock::time_point later1 = now + std::chrono::seconds(4);
	steady_clock::time_point later2 = now + std::chrono::seconds(10);
	steady_clock::time_point later3 = now + std::chrono::seconds(20);
	steady_clock::time_point earlier = now + std::chrono::seconds(-10);
	cout << seconds_in_overlap(now, later2, earlier, later1) << endl;
	cout << "Expected: 4" << endl;
	cout << seconds_in_overlap(earlier, later1, now, later2) << endl;
	cout << "Expected: 4" << endl;
	cout << seconds_in_overlap(earlier, now, later1, later2) << endl;
	cout << "Expected: 0" << endl;
	cout << seconds_in_overlap(later1, later2, earlier, now) << endl;
	cout << "Expected: 0" << endl;
	cout << seconds_in_overlap(earlier, later2, now, later1) << endl;
	cout << "Expected: 4" << endl;
	cout << seconds_in_overlap(later1, later2, earlier, later3) << endl;
	cout << "Expected: 6" << endl;
	cout << seconds_in_overlap(now, later1, later2, later3) << endl;
	cout << "Expected: 0" << endl;
	cout << seconds_in_overlap(now, later2, now, later3) << endl;
	cout << "Expected: 10" << endl;
	cout << seconds_in_overlap(now, later3, now, later3) << endl;
	cout << "Expected: 20" << endl;
	cout << seconds_in_overlap(earlier, later3, now, later2) << endl;
	cout << "Expected: 10" << endl;

	return 0;
}
