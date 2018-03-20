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

		while (current->next &&
				*node > *current->next)
		{
			current = current->next;
		}
		if(current->next != nullptr && node->get_row() == current->next->get_row()
				&& node->get_col() == current->next->get_col())
			return;

		node->next = current->next;
		current->next = node;
	}
}

ostream& operator <<(ostream& outs, const SortedLinkedList& list)
{
	Node * current;

	current = list.head;
	int row =current->get_row();
	int oldcol = current->get_col();
	int temp=0;
	while (current->next != nullptr)
	{
		outs << setw(oldcol-temp);
		if(current->get_name() == "")
		{
			outs  << *current;
		}
		else
		{
			outs << current->get_city();
		}

		if(row < current->next->get_row())
		{
			for(int i=0;i<current->next->get_row()-row;i++)
				outs << endl;
			oldcol = 0 ;
		}
		row = current->next->get_row();
		temp=oldcol;
		oldcol = current->next->get_col();
		if(current->get_name() != "")
		{
			temp += current->get_name().length() + current->get_state().length()+1;
		}
		current = current->next;

	}
	outs << setw(oldcol-temp);
	outs  << *current;
	return outs;
}
