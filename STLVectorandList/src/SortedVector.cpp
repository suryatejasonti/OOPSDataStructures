#include <iostream>
#include <iterator>

#include "SortedVector.h"

using namespace std;

SortedVector::SortedVector()
{
    Node::reset();
}

SortedVector::~SortedVector()
{
    Node::reset();
}

/**
 * Insert a new node at the beginning of the vector.
 * @param value the new node's value.
 */
void SortedVector::prepend(const long value)
{
	vector<Node>::insert(begin(), Node(value));
}

/**
 * Append a new node at the end of the vector.
 * @param value the new node's value.
 */
void SortedVector::append(const long value)
{
	push_back(Node(value));
}

/**
 * Insert a new node into the vector at the
 * appropriate position to keep the vector sorted.
 * @param value the value of the node to insert.
 */
void SortedVector::insert(const long value)
{
	vector<Node>::iterator it = begin();
	while(it!=end() && (value >=(*it).get_value() ))
	{
		it++;
	}
	vector<Node>::insert(it, Node(value));
}

/**
 * Remove a node.
 * @param index the index of the node to remove.
 */
void SortedVector::remove(const int index)
{
	erase(begin() + index);
}

/**
 * Reverse in place the order of the nodes of the vector.
 */
void SortedVector::reverse()
{
    if (size() == 0) return;

    vector<Node>::const_iterator it = begin();
    it++;

    while(it != end())
    {
    		vector<Node>::insert(begin(), *it);
    		it++;
    		erase(it);
    }
}

bool SortedVector::check() const
{
    if (size() == 0) return true;

    vector<Node>::const_iterator it = begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than or equal to the previous node.
    while ((it != end()) && (*it >= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}

bool SortedVector::check_reversed() const
{
    if (size() == 0) return true;

    vector<Node>::const_iterator it = begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is less than or equal to the previous node.
    while ((it != end()) && (*it <= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}
