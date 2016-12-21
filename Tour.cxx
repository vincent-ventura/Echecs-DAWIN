#include "Tour.h"

Tour::Tour(bool white, bool right) : Piece((right)?(white?1:8):(white?8:1), (white)?1:8, white)
{
  // cout << "Construction Tour " << (right ? "droite": "gauche") << endl;
}

bool
Tour::mouvementValide(Echiquier &e, int x, int y)
{
  Piece * p = e.getPiece(x, y);
  bool obstruction = false;
  int i;
  //cout << "mouvement valide de Tour" << endl;
  if ( ( m_y == y && m_x != x ) && ( p == nullptr || ( m_white ? p->isBlack() : p->isWhite() ) ) ) { // deplacement horizontal
    i = m_x > x ? m_x-1 : m_x+1; // on initialise la premiere position à laquelle on doit vérifier qu'il n'y ait personne

    while ( i != x && !obstruction ) { // tant qu'il n'y a pas obstruction et qu'on est pas arrivé jusqu'à la destination
      if ( e.getPiece(i, y) != nullptr ) // si il y a une piece sur le chemin
        obstruction = true; // obstruction prend vrai
      m_x > x ? i-- : i++; // on avance de position
    }

    return !obstruction; // on retourne !obstruction (si y'a obstruction on retourne donc false et vice versa)
  }

  if ( ( m_x == x && m_y != y ) && ( p == nullptr || ( m_white ? p->isBlack() : p->isWhite() ) ) ) { // deplacement vertical
      i = m_y > y ? m_y-1 : m_y+1;

      while ( i != y && !obstruction ) {
        if ( e.getPiece(x, i) != nullptr )
          obstruction = true;
        m_y > y ? i-- : i++;
    }

    return !obstruction;
  }

  return false;
}

char
Tour::myChar()
{
  return m_white?'T':'t';
}