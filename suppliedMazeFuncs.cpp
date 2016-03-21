#include "Maze2.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Maze2::Maze2(int n): size(n) 
{
  // start and exit will be set by the initialize method
  M = new(nothrow) state *[size+2];
  assert(M);

  for(int i = 0; i < size+2; ++i) {
    M[i] = new (nothrow) state[size+2];
    assert(M[i]);
    for(int j = 0 ; j < size+2; ++j)
      M[i][j] = WALL;
  }
  
  pred = new(nothrow) Position *[size+2];
  assert(pred);

  for(int i = 0; i < size+2; ++i) {
    pred[i] = new (nothrow) Position[size+2];
    assert(pred[i]);
    for(int j = 0 ; j < size+2; ++j)
      pred[i][j] = NULLPOS;
  }
}

Maze2::~Maze2()
{
  for(int i = 0; i < size+2; ++i)
    delete [] M[i];
  delete [] M;
  for(int i = 0; i < size+2; ++i)
    delete [] pred[i];
  delete [] pred;
}

void Maze2::display() const
{
  state s;
  for(int i = 0; i < size+2; ++i) {
    for(int j = 0; j < size+2; ++j) {
      s = M[i][j];
      assert(s == OPEN || s == WALL);
      if (s == WALL)
	cout << "*";
      else {
	Position P(i,j);
	if(P == start && P == exitpos)
	  cout << "b";
	else if(P == start)
	  cout << "s";
	else if(P == exitpos)
	  cout << "e";
	else
	  cout << "-";
      }
    }
    cout << endl;
  }
}


void Maze2::initialize()
{
  
  cout << "The coordinates of positions in the maze must be in the range\n";
  cout << "from 1 to " << size << ", inclusive\n" << endl;
  cout << "Enter the row and column coordinates of the start position: ";
  cin >> start;
  while(1 > start.row || start.row > size || 1 > start.col || start.col > size 
	|| start == NULLPOS) {
    cout << "Invalid position; try again\n";
    cin >> start;
  }
  cout << endl;
  M[start.row][start.col] = OPEN;
    
  cout << "Enter the row and column coordinates of the exit position: ";
  cin >> exitpos;
  while(1 > exitpos.row || exitpos.row > size || 1 > exitpos.col 
	|| exitpos.col > size || exitpos  == NULLPOS) {
    cout << "Invalid position; try again\n";
    cin >> exitpos;
  }
  cout << endl;
  M[exitpos.row][exitpos.col] = OPEN;

  Position P;
  cout << "Enter the row and column coordinates of the other OPEN positions\n"
       << "terminating input with \"-1 -1\"\n";
  int count = 0;
  do {
    cin >> P;
    if(P == start || P == exitpos)
      continue;
    while(!(P == NULLPOS) && (1 > P.row || P.row > size || 1 > P.col 
			      || P.col > size)) {
      cout << "Invalid position; try again\n";
      cin >> P;
    }
    if(!(P == NULLPOS)) {
      if (M[P.row][P.col] == OPEN) {
	cout << "Duplicate in open position list: " << P << endl;
	exit(1);
      }
      M[P.row][P.col] = OPEN;
      count += 1;
    }
  } while(!(P == NULLPOS) && count < size*size);
  cout << endl;
}

void Maze2::printPredPath(Position P)
// Print the path from start to P determined by the pred array
// Precondition: pred[p] != NULLPOS (so the path exists)
{
  if(P == NULLPOS)
    return;
  printPredPath(pred[P.row][P.col]);
  cout << P << " ";
}

void Maze2::printExitPath()
// If the path stack is empty, output "No way out\; otherwise, output
// "Exit path:" then call reverseStackPrint to print the exit path
// In any case, at the last, insert endl into the output stream.
{
  find_exit();
  if(!(exitpos == start) && pred[exitpos.row][exitpos.col] == NULLPOS)
    cout << "No way out" << endl;
  else {
    cout << "Path to exit:\n\n";
    printPredPath(exitpos);
    cout << endl;
  }  
}

