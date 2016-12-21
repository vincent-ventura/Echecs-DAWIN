#include "Fou.h"

Fou::Fou(bool white, bool right) : Piece((right)?(white?3:6):(white?6:3), (white)?1:8, white)
{
  // cout << "Construction Fou" << (right ? "droit":"gauche") << endl;
}


/* Mouvement valide de Fou : 
* la difference |m_x-x| doit etre égal a la difference |m_y-y|
* car la piece doit avancer ou reculer d'autant en x et y 
*/
bool
Fou::mouvementValide(Echiquier &e, int x, int y)
{
  //cout << "mouvement valide de Fou" << endl;
  Piece * p = e.getPiece(x, y);
  bool obstruction = false;
  int i, j;

  if ( abs(m_x-x) == abs(m_y-y) && ( p == nullptr || ( m_white ? p->isBlack() : p->isWhite() ) ) ) { 
    i = m_x > x ? m_x-1 : m_x+1;
    j = m_y > y ? m_y-1 : m_y+1;
 
    while ( i != x && j != y && !obstruction ) {
      if ( e.getPiece(i, j) != nullptr )
        obstruction = true;
      m_x > x ? i-- : i++; 
      m_y > y ? j-- : j++;
    }

    return !obstruction;
  }

  return false;
}

char
Fou::myChar()
{
  return m_white?'F':'f';
}