/** 
 * Header de Reine.cxx
 *
 * @file Reine.h
 */

#ifndef Reine_h
#define Reine_h

#include "Piece.h"
#include "Fou.h"
#include "Tour.h"

class Reine : public Fou, public Tour
{
  public:
    Reine(bool white);
    bool mouvementValide(Echiquier &e, int x, int y);
    char myChar();
};

#endif // !defined Reine_h