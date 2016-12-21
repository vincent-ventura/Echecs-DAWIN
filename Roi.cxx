#include "Roi.h"

Roi::Roi(bool white) : Piece(5, (white)?1:8, white)
{
  // cout << "Construction Roi specialise" << endl;
}

/* Mouvement valide d'un roi : 
  - deplacement de une case dans tous les sens
*/
bool 
Roi::mouvementValide(Echiquier &e, int x, int y)
{
    Piece * p = e.getPiece(x, y); 
    if ( ( p == nullptr || p->isWhite() != m_white ) &&    // destination libre ou bien de couleur differente de la piece à deplacer
      ( ( (m_y == y) && ( (m_x-1 == x) || (m_x+1 == x) ) ) || // mouvement horizontal
        ( (m_x == x) && ( (m_y-1 == y) || (m_y+1 == y) ) ) || // mouvement vertical
        ( (m_x+1 == x) && ( (m_y-1 == y) || (m_y+1 == y) ) ) || // mouvement diagonal vers la droite
        ( (m_x-1 == x) && ( (m_y-1 == y) || (m_y+1 == y) ) ) // mouvement diagonal vers la gauche
      )
       )
      return true;
    
    return false;
}
    
char 
Roi::myChar()
{
  return m_white?'R':'r';
}