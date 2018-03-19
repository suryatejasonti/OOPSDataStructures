#include "SortedLinkedList.h"

SortedLinkedList::SortedLinkedList():head(nullptr) { }

SortedLinkedList::SortedLinkedList(Node* head)
{
	this->head = head;
}

void SortedLinkedList::insert(Node* node)
{
	Node * current;
	/* Special case for the head end */
	if (head == NULL || *head > *node)
	{
		node->next = head;
		head = node;
	}
	else
	{
		/* Locate the node before the point of insertion */
		current = head;

		while (current->next!=NULL &&
				*node > *current->next)
		{
			current = current->next;
		}
		node->next = current->next;
		current->next = node;
	}

}

ostream& operator <<(ostream& outs, const SortedLinkedList& list)
{
	Node * current;

	current = list.head;
	int row =current->get_row();
	while (current != nullptr)
	{
		outs << *current;
		if(row < current->next->get_row())
		{
			outs << endl;
		}
		row = current->next->get_row();
		current = current->next;
	}
	return outs;
}
