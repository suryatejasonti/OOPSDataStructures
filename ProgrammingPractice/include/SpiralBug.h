#ifndef SPIRAL_BUG
#define SPIRAL_BUG

#include <iostream>

using namespace std;

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
class SpiralBug
{
 private:
	int step_size, x, y, direction, ittr, temp;
 public:
    SpiralBug(int step_size);
    void move();
    int get_x() const;
    int get_y() const;
 };

 #endif
