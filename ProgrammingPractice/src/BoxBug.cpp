#include "../include/BoxBug.h"

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
BoxBug::BoxBug(int initial_x, int initial_y, int box_width, int box_height)
{
	x=initial_x;
	y=initial_y;
	bw=box_width;
	bh=box_height;
	rd=0;
	ld=0;
	ru=0;
	lu=0;
}

void BoxBug::move()
{
	if ((x==0)&&(y==(bh-1)))
   {

	  x++;
	  y--;
	  lu=0;
	  rd=1;
   }
   else if(y==(bh-1))
   {
	if(ru==1)
	{
	  y--;
	  x++;
	  rd=1;
	  ru=0;
	}
	else if(lu==1)
	{
	   x--;
	   y--;
	   lu=0;
	   ld=1;
	}

   }
   else if(y==0)
   {
	  if(ld==1)
	  {
		 x--;
		 y++;
		 lu=1;
		 ld=0;
	  }
	  else if(rd==1)
	  {
	  x++;
	  y++;
	  ru=1;
	  rd=0;

	  }
   }
   else if(x==(bw-1))
   {
	  if(rd==1)
	  {
		 x--;
		 y--;
		 ld=1;
		 rd=0;
	  }
	  else if(ru==1)
	  {
		 x--;
	   y++;
	   lu=1;
	   ru=0;
	  }
   }

   else
   {
	  if(ld==0 && rd==0 && lu==0 && ru==0)
	  {
		 x++;
		 y++;
		 ru=1;
	  }
	  else if((rd==1))
	  {
		 y--;
		 x++;
	  }

	  else if(ru==1)
	  {
	  x++;
	  y++;
	  }
	  else if(ld==1)
	  {
		 x--;
		 y--;
	  }
	  else if(lu==1)
	  {
		 x--;
		 y++;
	  }

   }
}

int BoxBug::get_x() const
{
	return x;
}

int BoxBug::get_y() const
{
	return y;
}
