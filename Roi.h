/** 
 * Header de Roi.cxx
 *
 * @file Roi.h
 */

#ifndef Roi_h
#define Roi_h

#include "Piece.h"

class Roi : public Piece
{
  private:
    bool enEchec;
  public:
    Roi(bool white);
    bool mouvementValide(Echiquier &e, int x, int y);
    char myChar();
};

#endif // !defined Roi_h