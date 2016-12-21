/** 
 * Mise en oeuvre de Joueur.h
 *
 * @file Joueur.cxx
 */

// A besoin de la declaration de la classe
#include <iostream>
#include <assert.h>
#include "Joueur.h"
#include "Pion.h"
#include "Roi.h"
#include "Cavalier.h"
#include "Tour.h"
#include "Fou.h"
#include "Reine.h"

using namespace std;


Joueur::Joueur()
{
  // cout << "Construction de Joueur par defaut" << endl;
}

Joueur::~Joueur()
{
  for (auto p : m_pieces)
    delete p;
  // cout << "Destruction de Joueur par defaut" << endl;
}

Joueur::Joueur(bool white)
{
  Roi *r = new Roi(white); // construction de piece dynamique (pour ne pas qu'elle soit detruite juste apres sa creation)
  m_pieces.push_back(r); // on ajoute un roi dans la collection de piece
  Reine *q = new Reine(white);
  m_pieces.push_back(q);
  Tour *td = new Tour(white, true);
  m_pieces.push_back(td);
  Tour *tg = new Tour(white, false);
  m_pieces.push_back(tg);
  Cavalier *cd = new Cavalier(white, true);
  m_pieces.push_back(cd);
  Cavalier *cg = new Cavalier(white, false);
  m_pieces.push_back(cg);
  Fou *fd = new Fou(white, true);
  m_pieces.push_back(fd);
  Fou *fg = new Fou(white, false);
  m_pieces.push_back(fg);
  Pion *p;
  for (int i=1; i<9; i++){
    m_pieces.push_back( new Pion(white, i) );
  }
  
  // cout << "Construction de Joueur specialise" << endl;
}

void
Joueur::affiche()
{
  for (Piece * p : m_pieces)
    p->affiche();
}

void
Joueur::placerPieces(Echiquier & e)
{
  for (auto p : m_pieces) {
    bool ok = e.placer( p );
    assert(ok);
  }
}

Piece *
Joueur::getRoi()
{
  for (auto p : m_pieces)
    if( p->myChar() == 'R' || p->myChar() == 'r' )
      return p;

  return nullptr;
}

Piece *
Joueur::getPiece(int x, int y, char car, bool onBoard)
{
  for (auto p : m_pieces) {
    cout << p->myChar() << endl;
    if ( p->myChar() == car && p->getOnBoard() == onBoard ) {
      if ( p->x() == x && p->y() == y ) {
        return p;
      }
    }
  }
  return nullptr;
}

bool
Joueur::estEnEchec(Echiquier & e, Joueur & adversaire)
{
  for (auto p : adversaire.m_pieces)
    if ( p->getOnBoard() && p->mouvementValide(e, this->getRoi()->x(), this->getRoi()->y() ) )
      return true;
  return false;
}
