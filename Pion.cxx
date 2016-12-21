#include "Pion.h"

Pion::Pion(bool white, int p) : Piece(p, (white)?2:7, white)
{
  // cout << "Construction Pion" << endl;
}


/* Mouvement valide d'un pion : 
  - 1 er déplacement : 1 ou 2 cases tout droit
  - sinon : 1 case tout droit si personne devant
            1 case en diagonale si piece adverse à cet endroit
*/
bool
Pion::mouvementValide(Echiquier &e, int x, int y)
{
  // cout << "mouvement valide de Pion" << endl;
  Piece * p = e.getPiece(x, y);

  // Determiner si le mouvement est tout droit, en diagonale ou incorrect
  if (m_white) { // piece blanche
    if ( ( m_y+1 == y )  && ( m_x-1 == x || m_x+1 == x ) ) // mouvement en diagonale
      if ( p != nullptr && p->isBlack() )  // mouvement vers une piece adverse
        return true;

    if (m_x == x) { // mouvement tout droit
      if (m_y+1 == y) // mouvement tout droit d'une case
        if ( p == nullptr ) // s'il n'y a pas de piece devant
          return true;

      if (m_y+2 == y  && m_y == 2) // mouvement tout droit de deux cases et 1 er déplacement de la piece
        if ( p == nullptr && e.getPiece(x, y-1) == nullptr ) // s'il n'y a pas de pieces sur le chemin
          return true;
    }
  }
  else { // piece noire
    if ( ( m_y-1 == y )  && ( m_x-1 == x || m_x+1 == x ) ) // mouvement en diagonale
      if ( p != nullptr && p->isWhite() )  // mouvement vers une piece adverse
        return true;

    if (m_x == x) { // mouvement tout droit
      if (m_y-1 == y) // mouvement tout droit d'une case
        if ( p == nullptr ) // s'il n'y a pas de piece devant
          return true;

      if (m_y-2 == y && m_y == 7) // mouvement tout droit de deux cases et 1 er déplacement de la piece
        if ( p == nullptr && e.getPiece(x, y+1) == nullptr ) // s'il n'y a pas de pieces sur le chemin
          return true;
    }
  }

  return false;
}

char
Pion::myChar()
{
  return m_white?'P':'p';
}