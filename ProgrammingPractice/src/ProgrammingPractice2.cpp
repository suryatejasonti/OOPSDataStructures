//============================================================================
// Name        : ProgrammingPractice2.cpp
// Author      : SuryaTSonti
// Version     :
// Copyright   : Your copyright notice
// Description : Practice questions in C++, Ansi-style
//============================================================================

#include <iostream>


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

