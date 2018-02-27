#include <iostream>
#include <vector>

#include "../include/BoxBug.h"
#include "../include/PipeBug.h"
#include "../include/VacuumBug.h"


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



   int width;
   int height;
   int initial_x;
   int initial_y;
   int moves;
   cout << "hi" << endl;
   cin >> width >> height >> initial_x >> initial_y >> moves;

   vector< vector<char> > box;
   for (int y = 0; y < height; y++)
   {
      box.push_back(vector<char>());
      for (int x = 0; x < width; x++)
         box[y].push_back(' ');
   }
   BoxBug b(initial_x, initial_y, width, height);
   box[initial_y][initial_x] = '0';
   for (int move = 1; move <= moves; move++)
   {
      b.move();
      box[b.get_y()][b.get_x()] = '0' + (move % 10);
   }
   cout << '+';
   for (int x = 0; x < width; x++) cout << '-';
   cout << '+' << endl;
   for (int y = height - 1; y >= 0; y--)
   {
      cout << "|";
      for (int x = 0; x < width; x++)
      {
         cout << box[y][x];
      }
      cout << "|" << endl;
   }
   cout << '+';
   for (int x = 0; x < width; x++) cout << '-';
   cout << '+' << endl;


}
