#include "Maze2.h"
#include <iostream>
#include <cassert>

using namespace std;

void Maze2::find_exit()
{
   // Use the BFS method to fill the array of predecessors
  Position nbr, current;
  direction d;
  
  Q.push(start);
  M[start.row][start.col] = VISITED;


  while (!Q.empty())
  {
	  current = Q.front();			  //push current to the queue
	  Q.pop();						//pop off the first element

	  //main logic if open and not exit push on queue and track predessor
	  for (d = DOWN; d != NONE; d = next_direction(d)) {
		  nbr = current.Neighbor(d);
		  if (M[nbr.row][nbr.col] == OPEN) {
			  M[nbr.row][nbr.col] = VISITED;
			  pred[nbr.row][nbr.col] = current;

			  if (nbr == exitpos) {
				  return;
			  }

			  Q.push(nbr);
		  }
	  }
  }
}




