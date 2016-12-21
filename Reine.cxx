#include "Reine.h"

Reine::Reine(bool white) : Piece(4, (white?1:8), white), Fou(white, true), Tour(white, true)
{
  // cout << "Construction Renne specialise" << endl;
}
    
bool 
Reine::mouvementValide(Echiquier &e, int x, int y)
{
  // cout << "mouvement valide de Reine" << endl;
  return Fou::mouvementValide(e, x, y) || Tour::mouvementValide(e, x, y);
}
    
char 
Reine::myChar()
{
  return m_white?'Q':'q';
}