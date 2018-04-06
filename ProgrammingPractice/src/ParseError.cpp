#include <cctype>
#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>
using namespace std;

/*
  Implement the following function to parse a string of the form
  xx:yy am or xx:yy pm and set the reference parameters hours and
  minutes to military time (with hours between 0 and 23). \

  Here xx is either one or two digits between 1 and 12, and yy are
  two digits between 00 and 59.

  If xx or yy are out of range (1-12 and 0-59 respectively), throw
  a std::range_error.

  If the time string isn't long enough, throw an out_of_range exception.
  You can achieve that without any checking simply by calling
  string::at instead of string::operator[].

  If there is any other syntax error, throw a ParseError whose
  what() message says "time not valid: " followed by the invalid
  time string.

  If you throw an exception, do not modify hours or minutes.
*/

class ParseError : public runtime_error
{
public:
   ParseError(const string& what);
};

ParseError::ParseError(const string& what) : runtime_error(what) {}

void parse_time(string time, int& hours, int& minutes)
{

	int i = 1;
	if (isdigit(time[i])) {
	  hours = 10 * (time[i - 1] - '0') + time[i] - '0';
	  i++;
	}
	else {
	  hours = time[i - 1] - '0';
	}
	i += 2;
	minutes = 10 * (time[i - 1] - '0') + time[i] - '0';
	i += 2;
	if (time[i] == 'a')
	{
	  if (hours == 12) hours = 0;
	}
	else
	{
	  if (hours != 12) hours += 12;
	}
	cout << time.length() << " " << hours << " " << time[i] << endl;
	if(time.length() < 5)
	{
		throw out_of_range(time);
	}
	else if(time[i] != 'a' && time[i] != 'p'
			&& ((time.length() < 9 && hours > 9) || (time.length() < 8 && hours < 10)))
	{
		throw ParseError("time not valid: " + time);
	}
}
