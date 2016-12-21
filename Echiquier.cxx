/** 
 * Mise en oeuvre de Echiquier.h
 *
 * @file Echiquier.cxx
 */

#include <iostream>
#include <assert.h>

// A besoin de la declaration de la classe
#include "Echiquier.h"

/**
 * Constructeur par défaut.
 * Initialise à vide l'echiquier.
 */
Echiquier::Echiquier()
{
  for (int i=0;i<64;i++)
    m_cases[i] = nullptr;
}


/**
 * Recupere la piece situee sur une case.
 *
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 0 si aucune piece n'est sur cette case et un pointeur
 * vers une piece sinon.
 */
Piece* 
Echiquier::getPiece( int x, int y )
{
  //assert(x<9 && x>0 && y<9 && y>0);
  if( x<9 && x>0 && y<9 && y>0 )
    return m_cases[(x-1)+8*(y-1)];  
  return nullptr;
}

  
/**
 * Place une piece sur l'echiquier, aux coordonnees specifiees dans la piece.
 *
 * @param p un pointeur vers une piece
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide )
 */
bool 
Echiquier::placer( Piece* p )
{
  assert(p->x()<9 && p->x()>0 && p->y()<9 && p->y()>0);
  if ( getPiece(p->x(),p->y())==nullptr && p!=nullptr )
  {
      m_cases[(p->x()-1)+8*((*p).y()-1)] = p;
      p->setOnBoard(true);
      return true;
  }
  else
    return false;
}


/**
 * Deplace une piece sur l'echiquier, des coordonnees specifiees
 * dans la piece aux coordonnees x,y. 
 *
 * @param p un pointeur vers une piece
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide, piece pas
 * presente au bon endroit sur l'echiquier)
 */
bool 
Echiquier::deplacer( Piece* p, int x, int y, vector<string> & deplacement )
{
  if ( p->mouvementValide( (*this), x, y ) ) { // si le mouvement est valide
    deplacement.push_back( to_string(p->x()) );
    deplacement.push_back( to_string(p->y()) );
    deplacement.push_back( to_string(x) );
    deplacement.push_back( to_string(y) );

    Piece * autre = getPiece(x, y);

    if ( autre != nullptr ) { // si une piece est au point de destination (forcément de couleur adverse)
      deplacement.push_back("true");
      deplacement.push_back( to_string(autre->myChar()) );
      enleverPiece(x, y); // on l'enleve
      autre->setOnBoard(false);
    }
    else
      deplacement.push_back("false");

    enleverPiece( p->x(), p->y() ); // on enleve la piece que l'on veut déplacer
    p->move(x, y); // on change ses coordonnées
    placer(p); // on la replace
    return true;
  }

  return false;    
}

/**
 * Annule le dernier déplacement effectué
 * sur l'échiquier
 */
void
Echiquier::annulerDeplacement( vector<string> deplacement, Joueur & adversaire )
{
  int xDep, yDep, xFin, yFin;
  bool wasAPieceDeleted;
  char car;

  vector<string>::iterator it = deplacement.begin();

  // On récupère les infos du deplacement à annuler
  xDep = stoi(*it); // x initial de la piece deplacée
  *it++; 
  yDep = stoi(*it); // y initial de la piece deplacée
  *it++;
  xFin = stoi(*it); // x final de la piece deplacée
  *it++;
  yFin = stoi(*it); // y final de la piece deplacée
  *it++;
  wasAPieceDeleted = *it == "true" ? true : false; // indicateur à vrai si une piece avait été mangée    
  *it++;

  // on replace la piece qui avait ete deplace
  Piece * p;
  p = getPiece(xFin, yFin); // on recupere la piece ayant été deplace
  enleverPiece(xFin, yFin); // on l'enleve de l'echiquier
  p->move(xDep, yDep); // on change ses coordonnees
  placer(p); // on la replace sur l'echiquier

  // on replace la piece qui avait ete mangée s'il y en avait une
  if( wasAPieceDeleted ) {
    car = stoi(*it);
    Piece * pOld = adversaire.getPiece(xFin, yFin, car, false);
    placer( pOld );
  }

}


/**
 * Enleve la piece situee sur une case (qui devient vide).
 *
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 0 si aucune piece n'est sur cette case et le pointeur
 * vers la piece enlevee sinon.
 */
Piece* 
Echiquier::enleverPiece( int x, int y )
{
  Piece *tmp;
  tmp=m_cases[(x-1)+8*(y-1)];
  tmp->setOnBoard(false);
  m_cases[(x-1)+8*(y-1)]=nullptr;
  return tmp;
}


/**
 * Affiche l'echiquier avec des # pour les cases noires et . pour
 * les blanches si elles sont vides, et avec B pour les pieces
 * blanches et N pour les pieces noires.
 */
void
Echiquier::affiche()
{
  cout << endl << "   1 2 3 4 5 6 7 8" << endl << endl;
  for ( int y = 1; y <= 8; ++y )
    {
      cout << y << "  ";
      for ( int x = 1; x <= 8; ++x )
	{
	  char c;
	  Piece* p = getPiece( x, y );
	  if ( p == nullptr ) 
	    c = ( ( x + y ) % 2 ) == 0 ? '#' : '.';
	  else
	    c = p->myChar(); // p->isWhite() ? 'B' : 'N';
	  cout << c << " ";
	}
      cout << " " << y << endl;
    }
  cout << endl << "   1 2 3 4 5 6 7 8" << endl;
}

  

