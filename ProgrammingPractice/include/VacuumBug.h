/*
 * A vacuum bug lives in a rectangular region of width w and height h, at an integer position (x, y), 0 ≤ x < w and 0 ≤ y < h.
 * It wants to clean the entire region. It starts at (0, 0), traverses the row (x, 0) where x goes from 0 to w - 1.
 * Then it traverses the row above, but backwards, going from (w - 1, 1) to (0, 1). Then it traverses the next row forward.
 * Each call to move moves the vacuum bug one step in this journey.
 * When the bug reaches the final position in the topmost row, a call to move has no further effect.
 * Complete the following files:
 */
#ifndef VACUUM_BUG
#define VACUUM_BUG

class VacuumBug
{
 private:
	int region_width, region_height, x, y;
	bool reverse;
 public:
    VacuumBug(int region_width, int region_height);
    void move();
    int get_x() const;
    int get_y() const;
 };

 #endif
