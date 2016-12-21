/** 
 * Header de Fou.cxx
 *
 * @file Fou.h
 */

#ifndef Fou_h
#define Fou_h

#include "Piece.h"

class Fou : virtual public Piece // virtual pour héritage en diament
{
 public:
  Fou(bool white, bool right);
  bool mouvementValide(Echiquier &e, int x, int y);
  char myChar();
};

#endif // !defined Fou_h