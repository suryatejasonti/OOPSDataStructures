#ifndef PIPE_BUG
#define PIPE_BUG
/*
 * A bug lives in a pipe that is closed at both ends.
 * The pipe has integer positions x = 0 (the left end) up to x = n - 1 (the right end), where n is the length of the pipe.
 * In each move, the bug moves to the right or to the left. It starts out at x = 0 moving right.
 * When it gets to the right end, it turns around, moving to the left. When it gets to the left end, it turns around, moving to the right.

Complete the following files:
 */

class PipeBug
{
 private:
	int bug, pipe_length;
 public:
    PipeBug(int pipe_length);
    void move();
    int get_x() const;
 };

 #endif
