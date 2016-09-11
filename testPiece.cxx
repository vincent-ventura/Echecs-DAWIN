/** 
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include "Piece.h"
#include "Joueur.h"


// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

bool compare (const Piece &p1, const Piece &p2)
{
  return (p1.x()==p2.x()) && (p1.y()==p2.y());
}


/**
 * Programme principal
 */
int main( int argc, char** argv )
{
  // instancie un objet p1 de type Piece
  Piece p1;
  // p1 est une piece blanche de coordonnees (3,3)
  p1.init( 3, 3, true );

  // on construit une piece p2
  Piece p2( 4, 4, false );
  
  // On les affiche
  p1.affiche();
  p2.affiche();  

  // les objets definis dans cette fonction sont automatiquement détruits.
  // Ex : p1

  /*Joueur jb(true);
  Joueur jn(false);

  jn.affiche();
  jb.affiche();*/

  //cout << (p3.samePosition(p2) ? "Meme position" : "Positions differentes" ) << endl;
  cout << ( compare(p1,p2) ? "Meme position" : "Positions differentes" ) << endl;
}
