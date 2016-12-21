/** 
 * Programme du jeu d'echec
 *
 * @file jeuDEchecs.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include "Piece.h"
#include "Joueur.h"
#include "JoueurBlanc.h"
#include "JoueurNoir.h"
#include "Echiquier.h"
#include <limits>

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

void getUserIntValue(int & value)
{
  while(!(cin >> value)){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Erreur de saisie.  Reessayez : ";
  }
}

/**
 * Programme principal
 */
int main( int argc, char** argv )
{
  Echiquier e;

  Joueur * jb = new JoueurBlanc();
  Joueur * jn = new JoueurNoir();

  jb->placerPieces(e);
  jn->placerPieces(e);

  Piece * p; // pièce courante que le jb ou jn veut déplacer
  bool finPartie = false; // indicateur de fin de partie
  int xDep, yDep, xFin, yFin; // coordonnées départ / fin de la piece p
  bool joueurBlanc = true; // indicateur du joueur courant
  char action;
  vector<string> deplacement; /* represente  le dernier deplacement sous forme de texte 
  ********** Exemple : xDep, yDep, xFin, yFin, [true|false], [carPiece]
  ********** : x depart, y depart, x fin, y fin, une piece a été mangée ?, caractere representatif de la piece mangée
  **/

  cout << "----------------------------------" << endl;
  cout << "---------- JEU D'ECHECS ----------" << endl;
  cout << "----------------------------------" << endl << endl ;

  e.affiche();

  while ( !finPartie ) {

    cout << endl << "Joueur " << (joueurBlanc ? "BLANC" : "NOIR") << ", a votre tour" << endl;

    deplacement.clear();

    if ( joueurBlanc ? jb->estEnEchec(e, *jn) : jn->estEnEchec(e, *jb) ) {
      cout << "/!\\ Attention - Vous etes en ECHEC /!\\ " << endl;
    }


    cout << "Choisissez une piece a deplacer ; " << endl;
    cout << "   Coordonnee en X : ";
    getUserIntValue(xDep);

    //cin >> xDep;
    cout << "   Coordonnee en Y : ";
    getUserIntValue(yDep);

    p = e.getPiece(xDep, yDep);
    if ( p == nullptr || ( p->isWhite() != joueurBlanc ) ) {
      cout << "Les coordonnees entrees ne correspondent a aucunes de vos pieces" << endl;
      continue;
    }

    cout << "Ou voulez vous la deplacer ?" << endl;
    cout << "   Coordonnee en X : ";
    getUserIntValue(xFin);
    cout << "   Coordonnee en Y : ";
    getUserIntValue(yFin);
    cout << endl;


    if ( e.deplacer(p, xFin, yFin, deplacement) ) {
      // On vérifie que le Roi (du joueur en cours) ne soit pas (ou plus) en Echec
      if ( joueurBlanc ? jb->estEnEchec(e, *jn) : jn->estEnEchec(e, *jb) ) { // s'il est en echec
        e.annulerDeplacement(deplacement, joueurBlanc ? *jn : *jb); // on annule son déplacement
        e.affiche();
        cout << endl << "Vous êtes ou vous vous etes mis en Echec, veuillez rejouer en consequence !";
        continue;
      }
      else {
        e.affiche();
        cout << "Deplacement effectue !" << endl;
      }
    }
    else {
      e.affiche();
      cout << "Deplacement non autorise !";
      continue;
    }

    // DETECTION DE FIN PARTIE ?
    if ( joueurBlanc ? !jn->getRoi()->getOnBoard() : !jb->getRoi()->getOnBoard() ) {
      cout << endl << "ECHEC ET MAT !!!" << endl;
      cout << "FIN DE PARTIE !!! Vainqueur : Joueur " << (joueurBlanc ? "BLANC" : "NOIR") << " !" << endl << endl;
      break;
    }

    joueurBlanc = !joueurBlanc; // on change de joueur
  }

}
