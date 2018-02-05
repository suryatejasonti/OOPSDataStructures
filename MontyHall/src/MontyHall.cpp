//============================================================================
// Name        : MontyHall.cpp
// Author      : SuryaTSonti
// Version     :
// Copyright   : Your copyright notice
// Description : Monty Hall in C++, Ansi-style
//============================================================================


// includes
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>

//namespaces
using namespace std;

//typedef to save door number integer
typedef int Door;

//simulation count variable for number of itterations to run
const int SIMULATION_COUNT = 100;

/*
 * Global variables to save hidden car : carPresent, contestant first choice : firstChoice
 * contestant second choice, Remaining option for switch door: secondChoice, Monty opened door: openedDoor
 * win with stay with first choice: win1, win with switch choice: win2
 */
Door carPresent, firstChoice, opnedDoor, secondChoice;

int win1 = 0, win2 = 0;


// Function Declerations


// function: which door hides the car (randomly generated)
Door hideCar();
//function : which door is your first choice (randomly generated)
Door makeFirstChoice();
//function: which door Monty opens (possibly random)
Door openDoor();
//function: which door could be your second choice
Door makeSecondChoice();
//simulate function to call sequence and cout
void simulate( int i );

// Function Definitions

// function: which door hides the car (randomly generated)
Door hideCar()
{
	return 1 + rand() % 3;
}
//function : which door is your first choice (randomly generated)
Door makeFirstChoice()
{
	return 1 + rand() % 3;
}
//function: which door Monty opens (possibly random)
Door openDoor()
{
	Door door ;
	do
	{
		door = 1 + rand() % 3;
	}while( door == carPresent || door == firstChoice );
	return door;
}
//function: which door could be your second choice
Door makeSecondChoice()
{
	Door door ;
	do
	{
		door = 1 + rand() % 3;
	}while( door == opnedDoor || door == firstChoice );
	return door;
}
//simulate function to call sequence and cout
void simulate( int i)
{
	//local variables
	string winF, winS;

	//calling sequence to hide car, first choice, open door by monty, second choice
	carPresent = hideCar();
	firstChoice = makeFirstChoice();
	opnedDoor = openDoor();
	secondChoice = makeSecondChoice();

	//check for which choice wins
	if(firstChoice == carPresent)
	{
		winF = "yes"; winS = ""; win1++;
	}
	else if(secondChoice == carPresent)
	{
		winF = ""; winS = "yes"; win2++;
	}
	//cout data required in format
	cout << setfill (' ') << setw (5) << i << setfill (' ') << setw (8) << carPresent << setfill (' ') << setw (8) <<
			firstChoice << setfill (' ') << setw (8) << opnedDoor << setfill (' ') << setw (8)
			<< setfill (' ') << setw (8) <<secondChoice << setfill (' ') << setw (7) << winF <<
			setfill (' ') << setw (7) << winS << endl;

}
// main function to generate srand from current time stamp and cout for simulation
int main()
{
	srand (time(NULL)); // get current time stamp
	cout << "    #     Car   First  Opened  Second    Win    Win" << endl;
	cout << "     	 here  choice    door  choice  first second" << endl;
    for (int i = 1; i <= SIMULATION_COUNT; i++)
    	{
    		simulate(i); // call simulate
    	}
    //cout data required in format
    cout << endl << setfill (' ') << setw (5) << win1 << " wins if stay with the first choice" << endl;
    cout << setfill (' ') << setw (5) << win2 << " wins if switch to the second choice" << endl;
    cout.precision(2);
    cout << endl << "Win ratio of switch over stay: " << (double)win2/win1 << endl;

}
