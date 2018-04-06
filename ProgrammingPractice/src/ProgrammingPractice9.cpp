#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;

class ParseError : public runtime_error
{
public:
   ParseError(const string& what);
};

void parse_time(string time, int& hours, int& minutes)
{
	int len = time.length();ParseError parseError("time not valid: "+time);
	int i = 1;
	if (isdigit(time[i])) {hours = 10 * (time[i - 1] - '0') + time[i] - '0';i++;
	} else if(isdigit(time[i-1])) { hours = time[i - 1] - '0';
	}
	i += 2;
	if(isdigit(time[i])){ minutes = 10 * (time[i - 1] - '0') + time[i] - '0';
	}i += 2;
	if(len<i+1){throw out_of_range("out_of_range");
	}else if(len>i+2){throw  parseError;
	}
	if(hours>12||hours<1||minutes>59||minutes<0)throw range_error("range_error");
	if(time[i] == 'a') {
	  if (hours == 12) hours = 0;
	}else if(time[i] == 'p') {
	  if (hours != 12) hours += 12;
	}else{
	  throw  parseError;
	}
}

void test(string time, int h, int m, string e)
{
   int hours = -1;
   int minutes = -1;
   try
   {
      parse_time(time, hours, minutes);
      cout << hours << ":" << minutes << endl;
      if (e == "")
         cout << "Expected: " << h << ":" << m << endl;
      else
         cout << "Expected: " << e << endl;
   }
   catch (ParseError& ex) {
      cout << ex.what() << endl;
      cout << "Expected: ";
      if (e == "") cout << h << ":" << m << endl;
      else cout << e << endl;
   }
   catch (range_error& ex) {
      cout << "range_error" << endl;
      cout << "Expected: ";
      if (e == "") cout << h << ":" << m << endl;
      else cout << e << endl;
   }
   catch (out_of_range& ex) {
      cout << "out_of_range" << endl;
      cout << "Expected: ";
      if (e == "") cout << h << ":" << m << endl;
      else cout << e << endl;
   }
   catch (...)
   {
      cout << "Unexpected exception" << endl;
      cout << "Expected: ";
      if (e == "") cout << h << ":" << m << endl;
      else cout << e << endl;
   }
}

int main()
{
   test("1:23 am", 1, 23, "");
   test("1:23 pm", 13, 23, "");
   test("12:23 pm", 12, 23, "");
   test("12:23 am", 0, 23, "");
   test("1:23 qm", -1, -1, "time not valid: 1:23 qm");
   test("1:23am", -1, -1, "time not valid: 1:23am");
   test("1:23 am ", -1, -1, "time not valid: 1:23 am");
   test("1:23", -1, -1, "out_of_range");
   test("1", -1, -1, "out_of_range");
   test("1:63 am", -1, -1, "range_error");
   test("0:13 am", -1, -1, "range_error");
   test("13:13 am", -1, -1, "range_error");

   return 0;
}
