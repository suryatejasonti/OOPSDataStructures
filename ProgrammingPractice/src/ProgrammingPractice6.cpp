
#include "../include/Path.h"

int main()
{
	cout << "Adding to p1" << endl;
	Path p1(8);
	p1.add(1, 2);
	p1.add(2, 6);
	p1.add(3, 8);
	p1.add(4, 3);
	p1.add(5, 0);
	p1.add(6, -1);
	p1.print();
	cout << "Constructing p2 from p1" << endl;
	Path p2 = p1;
	cout << "Adding to p2" << endl;
	p2.add(3, 4);
	p2.add(5, 6);
	p2.add(7, 8);
	p2.print();
	cout << "All done" << endl;


   return 0;
}
