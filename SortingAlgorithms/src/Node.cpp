#include "Node.h"
#include "Element.h"

//Default Constructor for Node
Node::Node()
{
   Element();
   next = NULL;
}

//Constructor for node with input element object
Node::Node(const Element element)
{
   this->element = element;
   next = NULL;
}

Node::~Node() {}

