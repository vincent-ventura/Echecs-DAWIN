/** 
 * Mise en oeuvre de JoueurNoir.h
 *
 * @file JoueurNoir.cxx
 */

#include <iostream>
#include "JoueurNoir.h"

using namespace std;

JoueurNoir::JoueurNoir() :  Joueur(false)
{
  // cout << "Construction de Joueur Noir par defaut" << endl;
}

JoueurNoir::~JoueurNoir()
{
  // cout << "Destruction de Joueur Noir par defaut" << endl;
}

bool
JoueurNoir::isWhite()
{
  return false;
}

