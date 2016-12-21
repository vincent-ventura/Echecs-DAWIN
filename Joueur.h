/** 
 * Header de Joueur.cxx
 *
 * @file Joueur.h
 */

#ifndef Joueur_h
#define Joueur_h

#include "Piece.h"
#include "Echiquier.h"
#include <vector>

using namespace std;

class Piece;
class Echiquier;

/**
 * Declaration d'une classe modélisant un joueur de jeu d'echec.
 */
class Joueur 
{
protected:
	vector<Piece*> m_pieces; // vecteur de pointeur sur des pieces (allocation dynamique)
  	//Piece m_pieces[16]; 
  
public:
  Joueur();
  ~Joueur();
  Joueur(bool white);
  void affiche();
  virtual bool isWhite()=0; // methode virtuelle PURE -> classe abstraite (non instanciable) !
  void placerPieces(Echiquier & e);
  Piece * getRoi();
  Piece * getPiece(int x, int y, char car, bool onBoard);
  bool estEnEchec(Echiquier & e, Joueur & adversaire);
}; 

#endif // !defined Joueur_h


// TODO:
// methode Piece & getRoi dans classe joueur
// methode bool estEnEchec dans classe joueur + appel dans mvtValide classe Pieces