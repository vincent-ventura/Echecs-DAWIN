/** 
 * Header de Cavalier.cxx
 *
 * @file Cavalier.h
 */

#ifndef Cavalier_h
#define Cavalier_h

#include "Piece.h"

class Cavalier : public Piece
{
 public:
  Cavalier(bool white, bool right);
  bool mouvementValide(Echiquier &e, int x, int y);
  char myChar();
};

#endif // !defined Cavalier_h