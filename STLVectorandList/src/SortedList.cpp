#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
    Node::reset();
}

SortedList::~SortedList()
{
    Node::reset();
}


/**
 * Insert a new node at the beginning of the list.
 * @param value the new node's value.
 */
void SortedList::prepend(const long value)
{
	list<Node>::push_front(Node(value));
}

/**
 * Append a new node at the end of the list.
 * @param value the new node's value.
 */
void SortedList::append(const long value)
{
	list<Node>::push_back(Node(value));
}

/**
 * Insert a new node into the list at the
 * appropriate position to keep the list sorted.
 * @param value the value of the node to insert.
 */
void SortedList::insert(const long value)
{
    list<Node>::const_iterator it = begin();
    Node node(value);
	// Ensure that each node is less than or equal to the value.
	while ((it != end()) && (node >= *it ))
	{
		it++;
	}

	list<Node>::insert(it, node); //insert the node.
}

/**
 * Remove a node.
 * @param index the index of the node to remove.
 */
void SortedList::remove(const int index)
{
	list<Node>::const_iterator it = begin();
	advance(it, index);
	erase(it);
}

/**
 * Reverse in place the order of the nodes of the list.
 */
void SortedList::reverse()
{
	if (size() == 0) return;

	list<Node>::const_iterator it = begin();
	it++;

	while(it != end())
	{
		list<Node>::insert(begin(), *it);
		list<Node>::erase(it);
		it++;
	}

}

bool SortedList::check() const
{
    if (size() == 0) return true;

    list<Node>::const_iterator it = begin();
    list<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than or equal the previous node.
    while ((it != end()) && (*it >= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}

bool SortedList::check_reversed() const
{
    if (size() == 0) return true;

    list<Node>::const_iterator it = begin();
    list<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is less than or equal to the previous node.
    while ((it != end()) && (*it <= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}

/**
 * Overloaded [] operator that returns
 * a reference to a Node element.
 * @param index the index of the element to return.
 * @return a reference to the element.
 */
Node& SortedList::operator[](const int index)
{
	list<Node>::iterator it = begin();
	for(int i=0; i<index; i++, ++it);

	return *it;
}
