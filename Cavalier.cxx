#include "Cavalier.h"

Cavalier::Cavalier(bool white, bool right) : Piece((right)?(white?2:7):(white?7:2), (white)?1:8, white)
{
  // cout << "Construction Cavalier" << (right ? "droit": "gauche") << endl;
}

/* Mouvement valide du cavalier
   +/-1x +/-3y ou +/-1y +/-3x
*/
bool
Cavalier::mouvementValide(Echiquier &e, int x, int y)
{
  //cout << "mouvement valide de Cavalier" << endl;
  Piece * p = e.getPiece(x, y);

  if ( m_x+1 == x || m_x-1 == x ) {
    if ( ( m_y+2 == y || m_y-2 == y ) && ( p == nullptr || ( m_white ? p->isBlack() : p->isWhite() ) ) ) 
      return true;
  }

  if( m_y+1 == y || m_y-1 == y ) {
    if ( ( m_x+2 == x || m_x-2 == x ) && ( p == nullptr || ( m_white ? p->isBlack() : p->isWhite() ) ) )
      return true;
  }

  return false;
}

char
Cavalier::myChar()
{
  return m_white?'C':'c';
}