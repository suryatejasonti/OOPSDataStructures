#include <map>
#include <string>
#include "WordMap.h"

using namespace std;

WordMap::WordMap() {}

WordMap::~WordMap() {}

int WordMap::get_count(const string text) const
{
    /** Complete this function. **/
    map<string, Word>::const_iterator it = find(text);
    return it != end() ? (it->second).get_count() : -1;
}

void WordMap::insert(const string text)
{
    /** Complete this function. **/
	pair<map<string,Word>::iterator,bool> it;
	// Starting time.
	steady_clock::time_point start_time = steady_clock::now();

	it = map<string, Word>::insert (pair<string,Word>(text,Word(text)));

	if (it.second==false)
		at(text).increment_count();

	// Compute and increment the elapsed time in microseconds.
	steady_clock::time_point end_time = steady_clock::now();

	this->increment_elapsed_time(start_time, end_time);

}

map<string, Word>::iterator WordMap::search(const string text)
{
    /** Complete this function. **/
    // Start the timer.
    steady_clock::time_point start_time = steady_clock::now();

    // Look for the word in the map.
    map<string, Word>::iterator it = find(text);

    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    steady_clock::time_point end_time = steady_clock::now();
    increment_elapsed_time(start_time, end_time);

    // Return the iterator.
    return it;
}
