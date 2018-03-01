#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_

#include <iostream>
#include <fstream>

using namespace std;

class RomanNumeral
{
private:
	int decimal;

	string roman;
	//private method converting decimal to roman from decimal
	string to_roman(int decimal);
	//private method used for converting string to decimal value
	int to_decimal(string &roman);

public:
    /**
     * Default constructor.
     */
    RomanNumeral();
    //construct with decimal argument
    RomanNumeral(int decimal);
    //Constructor with string argument
    RomanNumeral(string roman);
    //public method to get decimal value from roman
    int get_decimal() const;
    //public method to get string from decimal value
    string get_roman() const;
    //Overloading opeator for addition
    RomanNumeral operator + (const RomanNumeral& romannumeral) const;
    //Overloading opeator for substraction
    RomanNumeral operator - (const RomanNumeral& romannumeral) const;
    //Overloading opeator for multiply
    RomanNumeral operator * (const RomanNumeral& romannumeral) const;
    //Overloading opeator for division
    RomanNumeral operator / (const RomanNumeral& romannumeral) const;
    //Overloading opeator for equal comparison
    bool operator == (const RomanNumeral& romannumeral) const;
    //Overloading opeator for not equal comparison
    bool operator != (const RomanNumeral& romannumeral) const;
    //Overloading opeator for output stream
    friend ostream & operator<<(ostream &output, const RomanNumeral &romannumeral);
    //Overloading opeator for input stream
    friend istream & operator>>(istream &input, RomanNumeral &romannumeral);

};

#endif /* ROMANNUMERAL_H_ */
