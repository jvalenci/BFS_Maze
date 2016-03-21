#include <fstream>
#include <iostream>
#include "Maze2.h"

using namespace std;

int main(int argc, char * argv[])
{
  int maze_size;
      
  cout << "Welcome to the Rat in a Maze Program\n\n";
  cout << "You will prompted for the maze size, the start position,\n";
  cout << "the exit position, and the open positions of the maze.";
  cout << "If there is a path from the start to the exit, the sequence\n";
  cout << "of positions on that path will be printed; if no such path\n";
  cout << "exits, the message \"no way out\" will be printed\n\n";
  cout << "Input the size of the maze (not including the hedge): ";

  cin >> maze_size;

  Maze2 RatHaus(maze_size);

  RatHaus.initialize();

  RatHaus.display();
  cout << "\n\n";
  RatHaus.printExitPath();
  cout << "\n\n";

  return 0;
}

