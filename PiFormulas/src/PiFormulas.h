/*
 * PiFormulas.h
 *
 *  Created on: Jan 31, 2018
 *      Author: suryasonti
 */

#ifndef PIFORMULAS_H_
#define PIFORMULAS_H_

#include <iostream>
#include <cmath> /*atan*/
#include <limits> /* To get maximum digits of precision*/

// namespaces for iostream etc..
using namespace std;

//Getting Numeric limit for double to dbl
typedef std::numeric_limits<double> dbl;


//Function Declarations

//Getting Square Root in double
double getSqrtDouble(double base);

// Getting Power in double
double getPowerDouble(double base, double exponent);

//Getting arc tan pi
double getArcTanPi();
//Getting pi value upto 15 decimals
double getPi15Decimal();
//Getting pi value upto 16 decimals
double getPi16Decimal();
//Getting pi value upto 18 decimals
double getPi18Decimal();
//Getting pi value upto 22 decimals
double getPi22Decimal();
//Getting pi value upto 31 decimals
double getPi31Decimal();

#endif /* PIFORMULAS_H_ */
