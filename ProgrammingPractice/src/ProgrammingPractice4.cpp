#include <iostream>
#include <vector>

#include "../include/BoxBug.h"
#include "../include/PipeBug.h"
#include "../include/VacuumBug.h"
#include "../include/SpiralBug.h"
#include "../include/LoveBug.h"


using namespace std;


void expect(int expected, int actual)
{
   cout << "Actual: " << actual << endl;
   cout << "Expected: " << expected << endl;
}

int main()
{

//	   PipeBug freddy(5);
//	   expect(0, freddy.get_x());
//	   freddy.move();
//	   expect(1, freddy.get_x());
//	   freddy.move();
//	   freddy.move();
//	   freddy.move();
//	   expect(4, freddy.get_x());
//	   freddy.move();
//	   expect(3, freddy.get_x());
//	   freddy.move();
//	   freddy.move();
//	   freddy.move();
//	   expect(0, freddy.get_x());
//	   freddy.move();
//	   expect(1, freddy.get_x());
//	   PipeBug mona(100);
//	   for (int i = 0; i < 100; i++) mona.move();
//	   expect(98, mona.get_x());
//	   for (int i = 0; i < 100; i++) mona.move();
//	   expect(2, mona.get_x());


//	int width;
//	int height;
//	int moves;
//	cin >> width >> height >> moves;
//
//	vector< vector<char> > region;
//	for (int y = 0; y < height; y++)
//	{
//	  region.push_back(vector<char>());
//	  for (int x = 0; x < width; x++)
//		 region[y].push_back(' ');
//	}
//	VacuumBug b(width, height);
//	region[0][0] = '0';
//	for (int move = 1; move <= moves; move++)
//	{
//	  b.move();
//	  region[b.get_y()][b.get_x()] = '0' + (move % 10);
//	}
//	cout << '+';
//	for (int x = 0; x < width; x++) cout << '-';
//	cout << '+' << endl;
//	for (int y = height - 1; y >= 0; y--)
//	{
//	  cout << "|";
//	  for (int x = 0; x < width; x++)
//	  {
//		 cout << region[y][x];
//	  }
//	  cout << "|" << endl;
//	}
//	cout << '+';
//	for (int x = 0; x < width; x++) cout << '-';
//	cout << '+' << endl;



//   int width;
//   int height;
//   int initial_x;
//   int initial_y;
//   int moves;
//   cout << "hi" << endl;
//   cin >> width >> height >> initial_x >> initial_y >> moves;
//
//   vector< vector<char> > box;
//   for (int y = 0; y < height; y++)
//   {
//      box.push_back(vector<char>());
//      for (int x = 0; x < width; x++)
//         box[y].push_back(' ');
//   }
//   BoxBug b(initial_x, initial_y, width, height);
//   box[initial_y][initial_x] = '0';
//   for (int move = 1; move <= moves; move++)
//   {
//      b.move();
//      box[b.get_y()][b.get_x()] = '0' + (move % 10);
//   }
//   cout << '+';
//   for (int x = 0; x < width; x++) cout << '-';
//   cout << '+' << endl;
//   for (int y = height - 1; y >= 0; y--)
//   {
//      cout << "|";
//      for (int x = 0; x < width; x++)
//      {
//         cout << box[y][x];
//      }
//      cout << "|" << endl;
//   }
//   cout << '+';
//   for (int x = 0; x < width; x++) cout << '-';
//   cout << '+' << endl;

//	int n;
//	int moves;
//	cin >> n >> moves;
//
//	int xmin = -10;
//	int xmax = 10;
//	int ymin = -10;
//	int ymax = 10;
//	int height = ymax - ymin + 1;
//	int width = xmax - xmin + 1;
//
//	vector< vector<char> > box;
//	for (int y = 0; y < height; y++)
//	{
//	 box.push_back(vector<char>());
//	 for (int x = 0; x < width; x++)
//		box[y].push_back(' ');
//	}
//	SpiralBug b(n);
//	box[-ymin][-xmin] = '0';
//	for (int move = 1; move <= moves; move++)
//	{
//	 b.move();
//	 box[b.get_y() - ymin][b.get_x() - xmin] = '0' + (move % 10);
//	}
//	cout << '+';
//	for (int x = 0; x < width; x++) cout << '-';
//	cout << '+' << endl;
//	for (int y = height - 1; y >= 0; y--)
//	{
//	 cout << "|";
//	 for (int x = 0; x < width; x++)
//	 {
//		cout << box[y][x];
//	 }
//	 cout << "|" << endl;
//	}
//	cout << '+';
//	for (int x = 0; x < width; x++) cout << '-';
//	cout << '+' << endl;
//

	LoveBug harry(0, 0);
	LoveBug sally(0.05, 0.05);
	harry.move(sally);
	cout << harry.get_happiness() << endl;
	cout << "Expected: 1" << endl;
	cout << sally.get_happiness() << endl;
	cout << "Expected: 0" << endl;
	cout << "(" << harry.get_x() << "," << harry.get_y() << ")" << endl;
	cout << "Expected: (0,0)" << endl;
	cout << "(" << sally.get_x() << "," << sally.get_y() << ")" << endl;
	cout << "Expected: (0.05,0.05)" << endl;

	LoveBug romeo(0, 0);
	LoveBug juliet(10, 10);
	juliet.move(romeo);
	cout << juliet.get_happiness() << endl;
	cout << "Expected: 1" << endl;
	cout << romeo.get_happiness() << endl;
	cout << "Expected: 0" << endl;
	cout << "(" << juliet.get_x() << "," << romeo.get_y() << ")" << endl;
	cout << "Expected: (3.35938,3.32031)" << endl;
	cout << "(" << romeo.get_x() << "," << romeo.get_y() << ")" << endl;
	cout << "Expected: (3.32031,3.32031)" << endl;

	LoveBug narcissus(5, 5);
	narcissus.move(narcissus);
	cout << narcissus.get_happiness() << endl;
	cout << "Expected: 0" << endl;
	cout << "(" << narcissus.get_x() << "," << narcissus.get_y() << ")" << endl;
	cout << "Expected: (5,5)" << endl;

}
