/** 
 * Header de Joueur.cxx
 *
 * @file Joueur.h
 */

#ifndef Joueur_h
#define Joueur_h

#include "Piece.h"

/**
 * Declaration d'une classe modélisant un joueur de jeu d'echec.
 */
class Joueur 
{
private:
  Piece m_pieces[ 16 ];  
  
public:
  Joueur();
  ~Joueur();
  Joueur(bool white);
  void affiche();
  bool isWhite();

}; 

#endif // !defined Joueur_h
