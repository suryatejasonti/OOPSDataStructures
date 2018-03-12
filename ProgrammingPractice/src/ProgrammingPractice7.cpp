#include <iostream>
#include "../include/stack.h"

using namespace std;

void swap_halves(Stack& s);

void swap_halves(Stack& s)
{
	int i=0;
	Stack one;
	Stack two;
	int half = Stack::stacks%2 == 0 ? Stack::stacks/ 2 : (Stack::stacks/ 2) +1;
	while(!s.empty())
	{
		string temp = s.pop();
		if(i < half)
		{
			one.push(temp);
		}
		else
		{
			two.push(temp);
		}
		i++;
	}
	while(!one.empty())
	{
	   s.push(one.pop());
	}
	while(!two.empty())
	{
	   s.push(two.pop());
	}
}


int main()
{
   Stack s;
   s.push("Mary");
   s.push("had");
   s.push("a");
   s.push("little");
   s.push("lamb");
   swap_halves(s);
   s.print();
   cout << "Expected: a had Mary lamb little" << endl;
   Stack t;
   t.push("Its");
   t.push("fleece");
   t.push("was");
   t.push("white");
   t.push("as");
   t.push("snow");
   swap_halves(t);
   t.print();
   cout << "Expected: was fleece Its snow as white" << endl;
   cout << "Constructed stacks: " << Stack::stacks << endl;
   cout << "Expected: 6" << endl;
}


