//============================================================================
// Name        : TranslateNumbers.cpp
// Author      : SuryaTSonti
// Version     :
// Copyright   : Your copyright notice
// Description : Translates 6 Digit numbers to strings in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

using namespace std;


string translate (int number);
string translateOnes(int number);
string translateTeens(int number);
string translateTens(int number);
string translateHundreds(int number);

string translate(int n)
{

	string words = "";
	if( n < 9 )
	{
		words = translateOnes(n);
	}
	else if ( ( n >= 11 ) || ( n <= 19) )
	{
		words = translateTeens(n);
	}
	return words;
}

string translateOnes(int n)
{
	switch(n)
	{
	case 1: return "One"; 	break;
	case 2: return "Two"; 	break;
	case 3: return "Three"; 	break;
	case 4: return "Four"; 	break;
	case 5: return "Five"; 	break;
	case 6: return "Six"; 	break;
	case 7: return "Seven"; 	break;
	case 8: return "Eight"; 	break;
	case 9: return "Nine"; 	break;

	default: return ""; break;
	}
}

string translateTeens(int n)
{
	switch(n)
	{
	case 11: return "Eleven"; 	break;
	case 12: return "Tweleve"; 	break;
	case 13: return "Thirteen"; 	break;
	case 14: return "Fourteen"; 	break;
	case 15: return "Fifteen"; 	break;
	case 16: return "Sixteen"; 	break;
	case 17: return "Seventeen";	break;
	case 18: return "Eighteen"; 	break;
	case 19: return "Ninteen"; 	break;

	default: return ""; break;
	}
}
string translateTens(int n)
{
	switch(n)
	{
	case 10: return "Ten"; 	break;
	case 20: return "Twenty"; 	break;
	case 30: return "Thirty"; 	break;
	case 40: return "Fourty"; 	break;
	case 50: return "Fifty"; 	break;
	case 60: return "Sixty"; 	break;
	case 70: return "Seventy"; 	break;
	case 80: return "Eighty"; 	break;
	case 90: return "Ninty"; 	break;

	default: return ""; break;
	}
}

string translateHundreds(int number)
{
	return "";
}

int main()
{
	int number;
	do
	{
		cin>>number;
		if(number > 0)
		{
			cout << number << ":" << translate(number) <<endl;
		}

	}while(number>0);

	return 0;
}
