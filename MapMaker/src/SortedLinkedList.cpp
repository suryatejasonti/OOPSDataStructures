#include "SortedLinkedList.h"

SortedLinkedList::SortedLinkedList():head(nullptr) { }

SortedLinkedList::SortedLinkedList(Node* head)
{
	this->head = head;
}

SortedLinkedList::~SortedLinkedList()
{
	Node * current = head;
	while(current != nullptr)
	{
		Node * next = current->next;
		delete current;
		current = next;
	}
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

		node->next = current->next;
		current->next = node;
	}
}
void removedupilicates(const SortedLinkedList& list, Node * head)
{
	Node * current = head;


	Node* next_next;

	/* do nothing if the list is empty */
	if (current == nullptr)
	   return;
	/*Remove dupilicates */
	/*Remove space not sufficient elements */
	int lengthold, lengthnew;
	lengthold = current->get_col() + current->get_name().length() + current->get_state().length();
	/* Traverse the list till last node */
	while (current->next != NULL)
	{
		/* Get the new length */
		lengthnew = current->next->get_col();
	   /* Compare current node with next node */
	   if ((current->get_col() == current->next->get_col() && current->get_row() == current->next->get_row())
			   || (lengthnew <= lengthold && current->get_row() == current->next->get_row()))
	   {
		   /* The sequence of steps is important*/
		   next_next = current->next->next;
		   delete current->next;
		   current->next = next_next;
	   }
	   else /* This is tricky: only advance if no deletion */
	   {
		  current = current->next;
		  lengthold = current->get_col() + current->get_name().length() + current->get_state().length();
		  if(current->get_name() != "")
			lengthold += 1;
	   }
	}
}

ostream& operator <<(ostream& outs, const SortedLinkedList& list)
{
	Node * current = list.head;

	removedupilicates(list, current);

	int oldcol, newcol;

	while (current->next != nullptr)
	{
		newcol = current->get_col();

		outs << setw(newcol-oldcol);
		outs  << *current;
		oldcol = newcol;
		if(current->get_name() != "")
		{
			oldcol += current->get_name().length() + current->get_state().length()+1;
		}
		if(current->get_row() < current->next->get_row())
		{
			for(int i=0;i<current->next->get_row()-current->get_row();i++)
				outs << endl;
			oldcol = 0;
		}
		current = current->next;

	}
	newcol = current->get_col();
	outs << setw(newcol-oldcol);
	outs  << *current;
	return outs;
}
