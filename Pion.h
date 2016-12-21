/** 
 * Header de Pion.cxx
 *
 * @file Pion.h
 */

#ifndef Pion_h
#define Pion_h

#include "Piece.h"

class Pion : public Piece
{
	public:
	  Pion(bool white, int p);
	  bool mouvementValide(Echiquier &e, int x, int y);
	  char myChar();
};

#endif // !defined Pion_h
