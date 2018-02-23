//============================================================================
// Name        : BigPi.cpp
// Author      : SuryaTSonti
// Version     :
// Copyright   : Your copyright notice
// Description : Calculating Pi using Borwein algorithm in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <mpir.h>
#include <stdlib.h>
#include <string.h>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

const int MAX_ITERATIONS = 10;
const int PLACES         = 1000000;        // desired decimal places
const int PRECISION      = PLACES + 1;  // +1 for the digit 3 before the decimal

const int BASE       = 10;  // base 10 numbers
const int BIT_COUNT  = 8;   // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE  = 100;               // digits to print per line
const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;                 // line grouping size

/*
 * Global Variables to store values 1, 2, 4, 6 values respectively
 */
mpf_t one, two, four, six;

/*
 * Calculate pi for the Borewins quartic formula
 * @param ai pointer of a0 value calculated earlier
 * @param yi pointer of y0 value calculated earlier
 * @param pi pointer to pi value to be stored in.
 */
void calculatepi(mpf_t *pi, mpf_t *yi, mpf_t *ai);

/*
 * Prints the pi value with string formatting
 * @Parameter pi pointer to pi value calculated at the end of algorithm
 */
void printpi(mpf_t *pi);

void calculatepi(mpf_t *pi, mpf_t *yi, mpf_t *ai)
{
	//Declaring loop variables
	mpf_t nr,dr,lhs,rhs,temp;

	// Initializing variables
	mpf_init(temp);
	mpf_init(rhs);
	mpf_init(lhs);
	mpf_init(nr);
	mpf_init(dr);

	for( int i = 0; i < MAX_ITERATIONS; i++ )
	{
		//Calculating yi = nr/dr
		mpf_pow_ui( *yi, *yi, 4);
		mpf_sub( temp, one, *yi );
		mpf_sqrt( temp, temp );
		mpf_sqrt( temp, temp );
		mpf_add( dr, one, temp );
		mpf_sub( nr, one, temp );
		mpf_div( *yi, nr, dr );

		//calculating left hand side value
		mpf_add( lhs, one, *yi );
		mpf_pow_ui( lhs, lhs, 4 );
		mpf_mul( lhs, lhs, *ai );

		//calculating right hand side value
		mpf_pow_ui( temp, *yi, 2 );
		mpf_add( rhs, one, temp );
		mpf_add( rhs, rhs, *yi );
		mpf_mul( rhs, rhs, *yi );

		//calculating ai from substraction ai = lhs-rhs
		mpf_pow_ui( temp,two,(2*i) + 3 ) ;
		mpf_mul( rhs, rhs, temp );
		mpf_sub( *ai, lhs, rhs );

		//calculating pi from ai, pi = 1 / ai;
		mpf_div( *pi, one, *ai );
	}

	//Clearing temp loop variables.
	mpf_clear(nr);
	mpf_clear(dr);
	//Clearing temp loop variables.
	mpf_clear(temp);
	mpf_clear(rhs);
	mpf_clear(lhs);
}

void printpi(mpf_t *pi)
{

	mp_exp_t exp;
	char * pistring = mpf_get_str(NULL, &exp, BASE, PRECISION, *pi);
	cout << "pi to " << PLACES << " places:" << endl << endl;
	cout << pistring[0] << ".";

	for( int line = 0; line < LINE_COUNT; line++ )
	{
		if( line > 0 )
			cout << "  ";
	    for( int length = 0; length < ( LINE_SIZE / BLOCK_SIZE ); length++ )
	    {
	        for( int block=0; block < BLOCK_SIZE; block++ )
	        {
	            cout<<pistring[block + length * BLOCK_SIZE + line * LINE_SIZE + 1];
	        }
	        cout <<" ";
	    }
	    cout << endl;
		if( line % GROUP_SIZE == GROUP_SIZE - 1 )
			cout << endl;
	}
}

/**
 * The main.
 */

int main()
{
	//@variables are declared for saving temporary results.
	mpf_t tempresult;

	//@variables to calculate algorithm to compute pi value
	mpf_t yi, ai, pi;

	//Setting default precision for all float variables before initialization
	mpf_set_default_prec(BIT_COUNT*PLACES);

	// Initializing variables
	mpf_init(yi);
	mpf_init(ai);
	mpf_init(pi);
	mpf_init(tempresult);
	mpf_init_set_d(one,1.0);
	mpf_init_set_d(two,2.0);
	mpf_init_set_d(four,4.0);
	mpf_init_set_d(six,6.0);

	mpf_sqrt(tempresult,two);
	mpf_sub(yi,tempresult,one);
	mpf_mul(tempresult,four,tempresult);
	mpf_sub(ai,six,tempresult);

	//Clearing temp loop variables.
	mpf_clear(four);
	mpf_clear(six);
	mpf_clear(tempresult);

	//@variable start_time: Identifying the start time of the program to calculate execution.
	steady_clock::time_point start_time = steady_clock::now();

	//Calling algorithm
	calculatepi( &pi, &yi, &ai);

	//@variable end_time: Identifying the end time of the program to calculate execution.
	steady_clock::time_point end_time = steady_clock::now();

	//Calling print function to print pi value
	printpi(&pi);

	//Clearing temp loop variables.
	mpf_clear(yi);
	mpf_clear(ai);
	mpf_clear(pi);
	mpf_clear(one);
	mpf_clear(two);

	duration<double>time_span = end_time - start_time;
	cout << "  Elapsed time: " << time_span.count() << " seconds"<< endl;
}


