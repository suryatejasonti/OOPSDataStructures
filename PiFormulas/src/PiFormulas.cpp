//============================================================================
// Name        : PiFormulas.cpp
// Author      : SuryaTSonti
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//includes
#include "PiFormulas.h"

//Global Variables
EulerConverganceStruct eulerConverganceData;

//Function Definitions

//Getting arc tan pi
double getArcTanPi()
{
	return 4*atan(1);
}
//Getting pi value upto 15 decimals
double getPi15Decimal()
{
	return ( 12 / getSqrtDouble( 130 ) )
			* log( ( 2 + getSqrtDouble( 5 ) )
					* ( 3 + getSqrtDouble( 13 ) ) / getSqrtDouble( 2) );
}
//Getting pi value upto 16 decimals
double getPi16Decimal()
{

	return ( 24 / getSqrtDouble( 142 ) )
			* log( ( getSqrtDouble( ( 10 + ( 11 * getSqrtDouble( 2 ) ) ) / 4 ) )
					+ ( getSqrtDouble( ( 10 + ( 7 * getSqrtDouble( 2 ) ) ) / 4 ) ) );
}
//Getting pi value upto 18 decimals
double getPi18Decimal()
{
	return ( 12 / getSqrtDouble( 190 ) )
				* log( ( ( 2 * getSqrtDouble( 2 ) ) + getSqrtDouble( 10 ) )
						* ( 3 + getSqrtDouble( 10 ) ) ) ;
}
//Getting pi value upto 22 decimals
double getPi22Decimal()
{
	return ( 12 / getSqrtDouble( 310 ) )
				* log( ( ( 3 + getSqrtDouble( 5 ) )
						* ( 2 + getSqrtDouble( 2 ) )
						* ( ( 5 + ( 2 * getSqrtDouble( 10 ) ) )
								+ getSqrtDouble( 61 + (20 * getSqrtDouble( 10 ) ) ) ) ) / 4 );
}
//Getting pi value upto 31 decimals
double getPi31Decimal()
{
	return ( 4 / getSqrtDouble( 522 ) )
				* log( getPowerDouble( ( 5 + getSqrtDouble( 29 ) ) / getSqrtDouble( 2 ), 3 )
						* ( ( 5 * getSqrtDouble( 29 ) ) + ( 11 * getSqrtDouble( 6 ) ) )
						* getPowerDouble( getSqrtDouble( ( 9 + ( 3 * getSqrtDouble( 6 ) ) ) / 4 )
								+ getSqrtDouble( ( 5 + ( 3 * getSqrtDouble( 6 ) ) ) / 4 ), 6 ) );
}
// Euler's infinite sum for pi*pi/6
float eulerInfiniteSum()
{
	return ( getArcTanPi() * getArcTanPi() / 6);
}
// Euler's convergence sum towards pi
EulerConverganceStruct eulerConvergenceSum()
{
	eulerConverganceData.itterations =1;
	eulerConverganceData.sum = 0;
	float term =0;
	do
	{
		term = 1.0 / getSquare(eulerConverganceData.itterations); // calculating fraction at every iteration
		eulerConverganceData.sum = eulerConverganceData.sum + term; // calculating sum at every step
		eulerConverganceData.itterations++; // adding iterations
	}while( term > ( 1 /getPowerFloat( 10, 8 ) ) ); // Verifying each term greater than 10^-8
	eulerConverganceData.piValue = getSqrtFloat( 6 * eulerConverganceData.sum); // Calculating final pi value
	return eulerConverganceData;
}

//Main function
int main() {

	// Setting initial precision for double
	cout.precision(dbl::max_digits10 -1);
	//Use of SetFill and SetW functions from std
	cout << "pi" << setfill (' ') << setw (5) << "= " << getArcTanPi() << " = 4*arctan(1)"<< endl << endl;
	cout << "Ramanujan's pi formulas:" <<endl;
	cout << "pi15 = " << getPi15Decimal() << endl;
	cout << "pi16 = " << getPi16Decimal() << endl;
	cout << "pi18 = " << getPi18Decimal() << endl;
	cout << "pi22 = " << getPi22Decimal() << endl;
	cout << "pi31 = " << getPi31Decimal() << endl << endl;
	//Changing precision to float
	cout.precision(flt::max_digits10 -1);
	cout << "Euler's infinite sum for pi*pi/6 = " << eulerInfiniteSum() << endl;
	eulerConvergenceSum();
	cout << setfill(' ') << setw(35) << "Converged to " << eulerConverganceData.sum << " after "
			<< eulerConverganceData.itterations << " iterations" << endl << endl;
	cout << "Euler's estimate for pi = " << eulerConverganceData.piValue << endl;
	//Changing precision of float
	cout.precision(flt::max_digits10 -2);
	cout << setfill(' ') << setw(26) << "error = " << getArcTanPi() - eulerConverganceData.piValue << endl;
	return 0;
}
