#ifndef BOX_BUG
#define BOX_BUG



/*
 * A bug lives in a box of width w and height h, at an integer position (x, y), 0 ≤ x < w and 0 ≤ y < h.
 * In each move, it moves diagonally until it hits one of the walls or a corner. If it hits a wall, its direction is reflected.
 * If it hits a corner, it turns around. When constructed with a given position, the bug initially moves towards increasing x- and y-positions.

Here is a trace of a bug in a box of width 10 and height 3 when move is called 5 times.

+----------+
|      1 5 |
|     0 2 4|
|        3 |
+----------+
Complete the following files:
 */
class BoxBug
{
 private:
	int x, y, bw, bh, rd, ld, ru, lu;
 public:
    BoxBug(int initial_x, int initial_y, int box_width, int box_height);
    void move();
    int get_x() const;
    int get_y() const;
 };

 #endif
