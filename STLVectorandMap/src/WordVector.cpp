#include <vector>
#include <string>
#include "WordVector.h"

using namespace std;

WordVector::WordVector() {}

WordVector::~WordVector() {}

int WordVector::get_count(const string text) const
{
    /** Complete this function. **/
    int index = find(text, 0, size()-1);
    return index >= 0 ? index : -1;
}

void WordVector::insert(const string text)
{
    /** Complete this function. **/
     // Start the timer.a
    steady_clock::time_point start_time = steady_clock::now();

    // First insertion?
    int pos = find(text,0,size()-1);

	if (pos < 0) // A negative pos means that the text was not found
	{
		pos *= -1;
		vector<Word>::insert(begin()+pos-1, Word(text));
	}
	else // The text was found. So, the count has to be incremented
	{
		vector<Word>::iterator it = begin();
		advance (it,pos);
		it->increment_count();
	}

    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    steady_clock::time_point end_time = steady_clock::now();
    increment_elapsed_time(start_time, end_time);

}

vector<Word>::iterator WordVector::search(const string text)
{
    /** Complete this function. **/
    // Start the timer.
    steady_clock::time_point start_time = steady_clock::now();

    // Look for the word in the vector.
    int index = find(text, 0, size()-1);

    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    steady_clock::time_point end_time = steady_clock::now();
    increment_elapsed_time(start_time, end_time);

    // Return the iterator.
    return index >= 0 ? begin() + index : end();
}

int WordVector::find(const string text, int low, int high) const
{
    /** Complete this function. **/
    // binary Search
	if (low <= high)
	{
		vector<Word>::const_iterator it = begin();

		int mid = (low + high)/2;
		advance(it, mid);
		if (text == (*it).get_text())
			return mid;
		else if (text < (*it).get_text() )
				return find(text, low, mid-1);
			else
				return find(text, mid+1, high);
	}

	//Returning ( position to be inserted - 1 ) instead of just a -1 in order to use binary search for insertion
	return -(low + 1);

}
