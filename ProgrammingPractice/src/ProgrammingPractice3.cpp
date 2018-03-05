//============================================================================
// Name        : ProgrammingPractice3.cpp
// Author      : SuryaTSonti
// Version     :
// Copyright   : Your copyright notice
// Description : Practice questions in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


/**
   Computes the average of all nonnegative elements in the given array.
   @param a an array of integers
   @param alen the number of elements in a
   @return the average of all nonnegative elements in a, or 0 if there are none.
*/
double nnavg(int a[], int alen)
{
   double sum = 0; int count = 0;
	for(int i = 0; i < alen; i++)
	{
		if( a[i] >= 0 )
		{
			sum += a[i];
			count++;
		}
	}
	return count == 0 ? 0 : sum / count;
}


/**
   Swaps the third and last value of a.
   For example, if a is {3, 1, 4, 1, 5, 9, 2, 6}
   after calling this method it is {3, 1, 6, 1, 5, 9, 1, 4}.
   If the array has length < 3, do nothing.
   @param a a vector of integers
*/
void swap3last(vector<int>& a)
{
	if(! ( a.size() < 3 ) )
	{
		int temp = a[2];
		a[2] = a[a.size() -1];
		a[a.size() -1] = temp;
	}
}
void print(const vector<int>& v)
{
   cout << "{";
   for (int i = 0; i < v.size(); i++)
   {
      cout << v[i];
      if (i < v.size() - 1) cout << ", ";
   }
   cout << "}" << endl;
}

/**
   Replaces each element in an array with the sum of itself and the
   elements preceding it.

   For example { 1, 2, 3, 4 } turns into { 1, 3, 6, 10 }

   Do not declare any arrays or vectors.
   @param a an array
   @param n the length of the array
*/
void precedingsum(double a[], int n);
void precedingsum(double a[], int n)
{
	double sum = 0;
	for(int i = 0; i < n; i++)
	{
	   sum += a[i];
		a[i] = sum;
	}
}
void print(double v[], int size)
{
   cout << "{";
   for (int i = 0; i < size; i++)
   {
      cout << v[i];
      if (i < size - 1) cout << ", ";
   }
   cout << "}" << endl;
}

/**
   Return a string that mixes the characters in the string a
   with the characters in b reversed. For example,
   intertwine("Fred", "Mary") yields "FyrreadM".

   If one string is longer than the other, append the unused
   characters (in reverse order if the second string is longer).
   intertwine("Sue", "Peggy") yields "SyugegeP".
*/
string intertwine(string a, string b)
{
	string interW;
	for( int i = 0; i < a.length() || i < b.length(); ++i  )
	{
		if( i < a.length() )
		{
			interW = interW + a.at(i);
		}
		if( i < b.length() )
		{
			interW = interW + b.at( b.length() - i -1 );
		}
	}
	return interW;
}

//IGNORESPACE false
/**
   This program reads in the name of a file from stdin.
   Then it opens the file and reads all lines of the file.
   Each line has the form

   label abbreviation value

   The label and abbreviation are nonempty strings without spaces.
   The value is a floating-point number.

   Print out the label and abbreviation with the smallest and
   largest value, in a left-justified, field of width 50,
   followed by the value in a right-justified field of width 10, with
   three digits after the decimal point.
*/
void question5()
{
	cout << "Input file:" << endl;
	string input_file;
	cin >> input_file;
	ifstream in(input_file);
	string maxLabel, maxAbbreviation, minLabel, minAbbreviation, label, abbreviation; float maxValue, minValue, value;
		for( int i = 0; !in.eof(); i++ )
		{
		   in >> label >> abbreviation >> value ;
		   if( i == 0 )
		   {
		      maxLabel = label;
		      maxAbbreviation = abbreviation;
		      maxValue = value;
		      minLabel = label;
		      minAbbreviation = abbreviation;
		      minValue = value;
		   }

			if( maxValue < value)
			{
				maxLabel = label;
				maxAbbreviation = abbreviation;
				maxValue = value;
			}

			if( minValue > value )
			{
				minLabel = label;
				minAbbreviation = abbreviation;
				minValue = value;
			}
		}
		cout << setw(50) << left << minLabel + " " + minAbbreviation << setw(12) << right << fixed << setprecision(2) << minValue << endl;
		cout << setw(50) << left << maxLabel + " " + maxAbbreviation << setw(12) << right << fixed << setprecision(2) << maxValue << endl;
	in.close();
}
int main()
{
//	vector<int> values = { 3, 1, 4, 1, 5, 9, 2, 6 };
//	swap3last(values);
//	print(values);
//	cout << "Expected: {3, 1, 6, 1, 5, 9, 2, 4}" << endl;
//
//	vector<int> values2 = { 1, -2, 3, -4, 5, -6 };
//	swap3last(values2);
//	print(values2);
//	cout << "Expected: {1, -2, -6, -4, 5, 3}" << endl;
//
//	vector<int> values3 = { 1, 2, 3, 4 };
//	swap3last(values3);
//	print(values3);
//	cout << "Expected: {1, 2, 4, 3}" << endl;
//
//	vector<int> values4 = { 1, 2, 3 };
//	swap3last(values4);
//	print(values4);
//	cout << "Expected: {1, 2, 3}" << endl;
//
//	vector<int> values5 = { 1 };
//	swap3last(values5);
//	print(values5);
//	cout << "Expected: {1}" << endl;
//
//	vector<int> values6 = {};
//	swap3last(values6);
//	print(values6);
//	cout << "Expected: {}" << endl;

//	double values[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
//	precedingsum(values, sizeof(values) / sizeof(values[0]));
//	print(values, sizeof(values) / sizeof(values[0]));
//	cout << "Expected: {3, 4, 8, 9, 14, 23, 25, 31}" << endl;
//
//	double values2[] = { 1, -2, 3, -4, 5, -6 };
//	precedingsum(values2, sizeof(values2) / sizeof(values2[0]));
//	print(values2, sizeof(values2) / sizeof(values2[0]));
//	cout << "Expected: {1, -1, 2, -2, 3, -3}" << endl;
//
//	double values3[] = { 1, 2 };
//	precedingsum(values3, sizeof(values3) / sizeof(values3[0]));
//	print(values3, sizeof(values3) / sizeof(values3[0]));
//	cout << "Expected: {1, 3}" << endl;
//
//	double values4[] = { 1 };
//	precedingsum(values4, sizeof(values4) / sizeof(values4[0]));
//	print(values4, sizeof(values4) / sizeof(values4[0]));
//	cout << "Expected: {1}" << endl;
//
//	double values5[] = {};
//	precedingsum(values5, sizeof(values5) / sizeof(values5[0]));
//	print(values5, sizeof(values5) / sizeof(values5[0]));
//	cout << "Expected: {}" << endl;

//	cout << intertwine("Goodbye", "World") << endl;


	return 0;
}
