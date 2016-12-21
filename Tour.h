/** 
 * Header de Tour.cxx
 *
 * @file Tour.h
 */

#ifndef Tour_h
#define Tour_h

#include "Piece.h"

class Tour : virtual public Piece // virtual pour héritage en diament
{
 public:
  Tour(bool white, bool right);
  bool mouvementValide(Echiquier &e, int x, int y);
  char myChar();
};

#endif // !defined Tour_h