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

const int MAX_ITERATIONS = 5;
const int PLACES         = 1000;        // desired decimal places
const int PRECISION      = PLACES + 1;  // +1 for the digit 3 before the decimal

const int BASE       = 10;  // base 10 numbers
const int BIT_COUNT  = 8;   // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE  = 100;               // digits to print per line
const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;                 // line grouping size

/***** Complete this file. *****/

/**
 * The main.
 */


#include <iostream>
#include <mpir.h>

using namespace std;

int main()
{
	mpf_t res,one,two,four,mulfr,six;
	mpf_t yi, ai, pi;
	mpf_set_default_prec(PLACES*MAX_ITERATIONS);
	mpf_init(yi);
	mpf_init(ai);
	mpf_init(pi);
	mpf_init(res);
	mpf_init_set_d(two,2.0);
	mpf_sqrt(res,two);
	mpf_init_set_d(one,1.0);
	mpf_sub(yi,res,one);
	mpf_init_set_d(four,4.0);
	mpf_init(mulfr);
	mpf_mul(mulfr,four,res);
	mpf_init_set_d(six,6.0);
	mpf_sub(ai,six,mulfr);

	for( int i = 0; i < MAX_ITERATIONS; i++ )
	{
		mpf_t sub1,nthrt,nr,dr,lhs,rhs,temp;

		mpf_init(sub1);
		mpf_init(nthrt);
		mpf_pow_ui(yi,yi,4);
		mpf_sub(sub1,one,yi);

		mpf_sqrt(nthrt,sub1);
		mpf_sqrt(nthrt,nthrt);
		mpf_init(nr);
		mpf_init(dr);
		mpf_add(dr, one, nthrt);
		mpf_sub(nr, one, nthrt);
		mpf_div(yi,nr,dr);

		mpf_init(lhs);
		mpf_add(lhs,one,yi);
		mpf_pow_ui(lhs, lhs, 4);
		mpf_mul(lhs, lhs, ai);

		mpf_init(temp);
		mpf_init(rhs);
		mpf_pow_ui(temp, yi, 2);
		mpf_add(rhs, one, temp);
		mpf_add(rhs, rhs, yi);
		mpf_mul(rhs, rhs, yi);

		int hello = (2*i) +3;
		mpf_pow_ui(temp,two,hello);
		mpf_mul(rhs, rhs, temp);


		mpf_sub(ai, lhs, rhs);

		mpf_div(pi, one, ai);

		gmp_printf ("INput: %.1000Ff\n\n",pi);

	}
	//gmp_printf ("INput: %.1000Ff\n\n",pi);

	operator<< (ostream& stream, mpz t op)
}

