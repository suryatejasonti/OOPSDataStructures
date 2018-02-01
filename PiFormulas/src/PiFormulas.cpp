//============================================================================
// Name        : PiFormulas.cpp
// Author      : SuryaTSonti
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//includes
#include "PiFormulas.h"

//Function Definitions

//Getting Square Root in double
double getSqrtDouble(double base)
{
	return sqrt(base);
}
// Getting Power in double
double getPowerDouble(double base, double exponent)
{
	return pow( base, exponent);
}
//Getting arc tan pi
double getArcTanPi()
{
	return 4*atan(1);
}
//Getting pi value upto 15 decimals
double getPi15Decimal()
{
	return ( 12.0 / getSqrtDouble( 130.0 ) )
			* log( ( 2.0 + getSqrtDouble( 5.0 ) )
					* ( 3.0 + getSqrtDouble( 13.0 ) ) / getSqrtDouble( 2.0 ) );
}
//Getting pi value upto 16 decimals
double getPi16Decimal()
{

	return ( 24.0 / getSqrtDouble( 142.0 ) )
			* log( ( getSqrtDouble( ( 10.0 + ( 11.0 * getSqrtDouble( 2.0 ) ) ) / 4.0 ) )
					+ ( getSqrtDouble( ( 10.0 + ( 7.0 * getSqrtDouble( 2.0 ) ) ) / 4.0 ) ) );
}
//Getting pi value upto 18 decimals
double getPi18Decimal()
{
	return ( 12.0 / getSqrtDouble( 190.0 ) )
				* log( ( ( 2.0 * getSqrtDouble( 2.0 ) ) + getSqrtDouble( 10.0 ) )
						* ( 3 + getSqrtDouble( 10.0 ) ) ) ;
}
//Getting pi value upto 22 decimals
double getPi22Decimal()
{
	return ( 12.0 / getSqrtDouble( 310.0 ) )
				* log( ( ( 3.0 + getSqrtDouble( 5.0 ) )
						* ( 2 + getSqrtDouble( 2.0 ) )
						* ( ( 5 + ( 2 * getSqrtDouble( 10.0 ) ) )
								+ getSqrtDouble( 61 + (20 * getSqrtDouble( 10.0 ) ) ) ) ) / 4.0 );
}
//Getting pi value upto 31 decimals
double getPi31Decimal()
{
	return ( 4.0 / sqrt( 522.0 ) )
				* log( sqrt(3.0) );
}

//Main function
int main() {

	cout.precision(dbl::max_digits10);
	cout << "!!!Hello World!!! pi value is "<<getPi22Decimal()<< endl; // prints !!!Hello World!!!
	return 0;
}
