//============================================================================
// Name        : MontyHall.cpp
// Author      : SuryaTSonti
// Version     :
// Copyright   : Your copyright notice
// Description : Monty Hall in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

typedef int Door;

const int SIMULATION_COUNT = 100;

//void simulate(int i, int win1, int win2 );

Door hideCar();

//Door openDoor();

Door makeFirstChoice();

//Door makeSecondChoice( ... );

Door hideCar()
{
	return 1 + rand() % 3;
}

Door makeFirstChoice()
{
	return 1 + rand() % 3;
}

int main()
{
	srand (time(NULL));
	cout<<"Monty"<<endl;
    //int win1 = 0, win2 = 0;
    for (int i = 1; i <= SIMULATION_COUNT; i++)
    	{
    		//simulate(i, win1, win2);
    	}
}
