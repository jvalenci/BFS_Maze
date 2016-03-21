#ifndef __MAZE1
#define __MAZE1

#include <iostream>
#include <cstdlib>      // for the exit function
#include <cassert>      // for the assert function
#include "Position.h"
#include <queue>

using namespace std;

typedef enum{OPEN,WALL,VISITED} state;

class Maze2
{
  public:
   // Constructor - sets size to n, allocates the nxn state array 
   // and sets the state of every array element to WALL
   Maze2(int n);

   // Destructor - deallocates the state array
   ~Maze2();

   // Copy constructor and assignment disabled
   Maze2(const Maze2 & other);
   Maze2 & operator=(const Maze2 & origMaze);

   void initialize();
   // inputs the start and exit positions and sets their state to OPEN; 
   // then inputs the other OPEN positions; prompts will be printed to
   // cout only if in == cin

   void display() const;
   // Print the contents of the maze, one row per line
   // For each Position P, print 'b' if P is both the start and exit position;
   // print 's' if P is the start, print 'e' is P is the exit; 
   // print '*' if the P's state is WALL and print a space
   // if P's state is OPEN

   void printExitPath();
   // If the path stack is empty, output "No way out\; otherwise, output
   // "Exit path:" then call reverseStackPrint to print the exit path
   // In any case, at the last, insert endl into the output stream.

  private:
   int size;
   Position start;
   Position exitpos;
   queue<Position> Q;
   Position **pred; // initialized to all entries = NULLPOS; findExit will
                    // set M[i][j] to the predecessor of Position(i,j) in a 
                    // shortest path from start to Position(i,j)
                    // if there is no such path

   state **M; // two-dimensional array of state values

   void find_exit();
   // Use the BFS method to fill the array of predecessors

   void printPredPath(Position P); 
   // If there is no path from start to P, returns false; otherwise,
   // prints the path to P determined by the pred array and returns true

};


#endif
