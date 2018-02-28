#include "../include/SpiralBug.h"
/*
 * A SpiralBug can occupy any integer coordinates (x, y), where x and y can be 0, negative, or positive.
 * It starts at (0, 0). For the next n steps, it moves to the right. Then it makes n steps up.
 * Then it makes 2n steps to the left, 2n steps down, and so on, tracing a spiral. (Hence its name. Google it if you dare.)
 * Each call to move should carry out one step.
	Here is the trace of the first 24 steps when n is 2.
         *
         *
   ***** *
   *   * *
   * *** *
   *     *
   *******
 */
SpiralBug::SpiralBug(int step_size)
{
	this->step_size = step_size;
	this->x = 0;
	this->y =0;
	this->direction = 0;
	this->ittr = 0;
	this->temp = 0;
}

void SpiralBug::move()
{
	switch(direction)
	{
		case 0:
			if(temp +1 < (2*ittr + 1) * step_size)
			{
				x++;temp++;
			}
			else
			{
				cout << "changed 0" << temp <<endl;
				x++; temp =0;
				direction = 1;
			}
			break;
		case 1:
			if(temp + 1 < (2*ittr + 1) * step_size)
			{
				y++;temp++;
			}
			else
			{
				cout << "changed 1" << temp <<endl;
				y++; temp =0;
				direction = 2;
			}
			break;
		case 2:
			if(temp +1 < (((2*ittr + 1) * step_size) + step_size))
			{
				x--;
				temp++;
			}
			else
			{
				cout << "changed 2" << temp <<endl;
				temp = 0;
				x--;
				direction = 3;
			}
			break;
		case 3:
			if(temp +1  < ((2*ittr + 1) * step_size) + step_size)
			{
				y--;
				temp++;
			}
			else
			{
				y--;cout << "changed 3" << temp <<endl;
				direction = 0;
				ittr++;temp = 0;
			}
			break;
	}
}

int SpiralBug::get_x() const
{
	return x;
}

int SpiralBug::get_y() const
{
	return y;
}
