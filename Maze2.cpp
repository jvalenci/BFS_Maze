#include "Maze2.h"
#include <iostream>
#include <cassert>

using namespace std;

void Maze2::find_exit()
{
   // Use the BFS method to fill the array of predecessors
  Position nbr, current;
  direction d;
  int count = 0;
  //bool foundExit = false;
  
  Q.push(start);
  M[start.row][start.col] = VISITED;

  //check to make sure initi starting pos isn't blocked in
  for (direction dir = DOWN; dir != NONE; dir = next_direction(dir)) {
	  if (M[start.Neighbor(dir).row][start.Neighbor(dir).col] != OPEN) {
		  ++count;
		  continue;
	  }
	  break;
  }

  //if blocked it will return
  if (count >= 4) {
	  Q.pop();
	  return;
  }

  while (!Q.empty())
  {
	  current = Q.front();
	  Q.pop();

	  for (d = DOWN; d != NONE; d = next_direction(d)) {
		  nbr = current.Neighbor(d);
		  if (M[nbr.row][nbr.col] == OPEN) {
			  M[nbr.row][nbr.col] = VISITED;
			  pred[nbr.row][nbr.col] = current;

			  if (nbr == exitpos) {
				  //foundExit = true;
				  return;
			  }

			  Q.push(nbr);
		  }
	  }

  }
}




