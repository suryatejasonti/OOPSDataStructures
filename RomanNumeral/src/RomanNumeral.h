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

	string to_roman(int decimal);

	int to_decimal(string &roman);

public:
    /**
     * Default constructor.
     */
    RomanNumeral();

    RomanNumeral(int decimal);

    RomanNumeral(string roman);

    int get_decimal() const;

    string get_roman() const;

    RomanNumeral operator + (const RomanNumeral& romannumeral) const;

    RomanNumeral operator - (const RomanNumeral& romannumeral) const;

    RomanNumeral operator * (const RomanNumeral& romannumeral) const;

    RomanNumeral operator / (const RomanNumeral& romannumeral) const;

    bool operator == (const RomanNumeral& romannumeral) const;

    bool operator != (const RomanNumeral& romannumeral) const;

    friend ostream & operator<<(ostream &output, const RomanNumeral &romannumeral);

    friend ifstream & operator>>(ifstream &input, RomanNumeral &romannumeral);

    friend void operator>>(char &op, RomanNumeral &romannumeral);

};

#endif /* ROMANNUMERAL_H_ */
