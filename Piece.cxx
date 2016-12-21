/** 
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

// A besoin de la declaration de la classe
#include <iostream>
#include "Piece.h"
#include <stdlib.h>     /* abs */

using namespace std;

Piece::Piece()
{
  // ne fait rien => objet instancie mais non valide.
  //cout << "Constructeur Piece par defaut" << endl;
}

Piece::Piece(const Piece & autre)
{
  m_x = autre.x();
  m_y = autre.y();
  m_white = autre.isWhite();
  //cout << "Constructeur Piece par copie" << endl;
}

Piece::~Piece()
{
  //cout << "Destructeur Piece " << endl;
}

Piece::Piece( int x, int y, bool white )
{
  m_x = x;
  m_y = y;
  m_white = white;
  m_on_board = false;
  //cout << "Constructeur Piece specialisee" << endl;
}

Piece &
Piece::operator=(const Piece & autre)
{
  m_x = autre.x();
  m_y = autre.y();
  m_white = autre.isWhite();
  m_on_board = autre.getOnBoard();
  //cout << "Operateur d'affectation Piece" << endl;
  return *this;
}

void
Piece::init( int x, int y, bool white )
{
  m_x = x;
  m_y = y;
  m_white = white;
}

void
Piece::move( int x, int y )
{
  m_x = x;
  m_y = y;
}

int
Piece::x() const
{
  return m_x;
}

int
Piece::y() const
{
  return m_y;
}

bool
Piece::isWhite() const
{
  return m_white;
}

bool
Piece::isBlack() const
{
  return !m_white;
}

void
Piece::affiche() const
{
  cout << "Piece: x=" << m_x << " y=" << m_y << " "
       << ( m_white ? "blanche" : "noire" ) << " "
       << ( m_on_board ? "enJeu" : "prise" ) << endl;
}

bool
Piece::samePosition(const Piece & p2) const
{
  return ( m_x==p2.x() && m_y==p2.y() );
}

const Piece & 
Piece::plusforte(const Piece & autre) const
{
  if (true)
    return autre;
  else
    return *this;
}

bool 
Piece::mouvementValide(Echiquier &e, int x, int y)
{
  return false;
}

char
Piece::myChar()
{
  return (m_white ? 'B' : 'N');
}

bool
Piece::getOnBoard() const
{
  return m_on_board;
}

void
Piece::setOnBoard(bool onBoard)
{
  m_on_board = onBoard;
}