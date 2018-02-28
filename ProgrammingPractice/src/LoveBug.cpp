/*
 * A LoveBug (google it if you dare) can occupy any floating-point coordinates (x, y).
 * Its initial position is given in the constructor. Its move member function has another LoveBug as a parameter.
 * If it is closer than 0.1 to that love bug, this love bug's happiness goes up by 1. Otherwise, it Moves itself halfway towards the position of the other love bug
 * Asks the other love bug to move it closer to this one. (Hint: *this). Yes, this will cause this bug recursively to move closer again.
 * Love is like that. “Mathematicians are like lovers… Grant a mathematician the least principle, and he will draw from it a
 * consequence which you must grant him also, and from this consequence another.”—Bernard Le Bovier de Fontenelle
 * However, no love bug loves itself. If the move method is called with the same bug as parameter, it does nothing.
 */
#include <cmath>
#include "../include/LoveBug.h"

using namespace std;

LoveBug::LoveBug(double x, double y)
{
	this->x = x;
	this->y = y;
	happiness = 0;
}

void LoveBug::move(LoveBug& other)
{
	if(&other == this)
	{
	  happiness = 0;
	}
	else if(distance(other)<0.1)
	{
	  happiness++;
	}

	else
	{
	 this->x = (this->x+other.get_x())/2;
	 this->y = (this->y+other.get_y())/2;

	 other.move(*this);
	}
}

double LoveBug::get_x() const
{
	return x;
}

double LoveBug::get_y() const
{
	return y;
}

double LoveBug::distance(const LoveBug& other) const
{
   double dx = get_x() - other.get_x();
   double dy = get_y() - other.get_y();
   return sqrt(dx * dx + dy * dy);
}

int LoveBug::get_happiness() const
{
	return happiness;
}
