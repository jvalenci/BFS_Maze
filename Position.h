//---------- Position.h ----------------//
// Position class -
// represents a position within a grid  //

#ifndef __POSITION
#define __POSITION

#include <iostream>

using namespace std;

typedef enum{DOWN, LEFT, UP, RIGHT, NONE} direction;

direction next_direction(direction d);

class Position {
 public:
   int row;
   int col;
   Position():row(0),col(0) {};
   Position(int m) : row(m),col(m) {};
   Position(int r, int c):row(r),col(c) {};
   void input();

   Position Neighbor(direction d) const;

   bool operator==(const Position &other) const;

   void display(ostream & out) const;

   void input(istream & in);
};

const Position NULLPOS = Position(-1,-1);

ostream & operator<<(ostream &out,const Position &P);

istream & operator>>(istream &in, Position &P);


#endif
