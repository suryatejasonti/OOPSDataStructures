//============================================================================
// Name        : MontyHall.cpp
// Author      : SuryaTSonti
// Version     :
// Copyright   : Your copyright notice
// Description : Monty Hall in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>

using namespace std;

typedef int Door;

const int SIMULATION_COUNT = 1000;

Door carPresent, firstChoice, opnedDoor, secondChoice;

int win1 = 0, win2 = 0;

void simulate( int i );

Door hideCar();

Door makeFirstChoice();

Door openDoor();

Door makeSecondChoice();


Door hideCar()
{
	return 1 + rand() % 3;
}
Door makeFirstChoice()
{
	return 1 + rand() % 3;
}
Door openDoor()
{
	Door door ;
	do
	{
		door = 1 + rand() % 3;
	}while( door == carPresent || door == firstChoice );
	return door;
}
Door makeSecondChoice()
{
	Door door ;
	do
	{
		door = 1 + rand() % 3;
	}while( door == opnedDoor );
	return door;
}
void simulate( int i)
{
	string winF, winS;

	carPresent = hideCar();
	firstChoice = makeFirstChoice();
	opnedDoor = openDoor();
	secondChoice = makeSecondChoice();

	if(firstChoice == carPresent)
	{
		winF = "yes"; winS = ""; win1++;
	}
	else if(secondChoice == carPresent)
	{
		winF = ""; winS = "yes"; win2++;
	}
	cout << setfill (' ') << setw (5) << i << setfill (' ') << setw (8) << carPresent << setfill (' ') << setw (8) <<
			firstChoice << setfill (' ') << setw (8) << opnedDoor << setfill (' ') << setw (8)
			<< setfill (' ') << setw (8) <<secondChoice << setfill (' ') << setw (7) << winF <<
			setfill (' ') << setw (7) << winS << endl;

}

int main()
{
	srand (time(NULL));
	cout << "    #     Car   First  Opened  Second    Win    Win" << endl;
	cout << "     	 here  choice    door  choice  first second" << endl;
    for (int i = 1; i <= SIMULATION_COUNT; i++)
    	{
    		simulate(i);
    	}
    cout << endl << setfill (' ') << setw (5) << win1 << " wins if stay with the first choice" << endl;
    cout << setfill (' ') << setw (5) << win2 << " wins if switch to the second choice" << endl;
    cout.precision(2);
    cout << endl << "Win ratio of switch over stay: " << (double)win2/win1 << endl;

}
