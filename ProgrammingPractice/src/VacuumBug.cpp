/*
 * A vacuum bug lives in a rectangular region of width w and height h, at an integer position (x, y), 0 ≤ x < w and 0 ≤ y < h.
 * It wants to clean the entire region. It starts at (0, 0), traverses the row (x, 0) where x goes from 0 to w - 1.
 * Then it traverses the row above, but backwards, going from (w - 1, 1) to (0, 1). Then it traverses the next row forward.
 * Each call to move moves the vacuum bug one step in this journey.
 * When the bug reaches the final position in the topmost row, a call to move has no further effect.
 * Complete the following files:
 */

#include "../include/VacuumBug.h"

VacuumBug::VacuumBug(int region_width, int region_height)
{
	this->region_width = region_width;
	this->region_height = region_height;
	x = 0; y = 0;
	reverse = false;
}

void VacuumBug::move()
{
	if(x < region_width -1 && y < region_height)
	{
		x++;
	}
	else if(x == region_width -1 && y < region_height -1)
	{
		y++; x = -x;
		reverse = true;
	}
	if(x == 1 && reverse)
	{
		x--; y++;
		reverse = false;
	}
}

int VacuumBug::get_x() const
{
	return x > 0 ? x : -x;
}

int VacuumBug::get_y() const
{
	return y > 0 ? y : -y;
}
