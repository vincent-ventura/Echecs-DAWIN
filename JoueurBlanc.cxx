/** 
 * Mise en oeuvre de JoueurBlanc.h
 *
 * @file JoueurBlanc.cxx
 */

#include <iostream>
#include "JoueurBlanc.h"

using namespace std;

JoueurBlanc::JoueurBlanc() : Joueur(true)
{
  // cout << "Construction de Joueur Blanc par defaut" << endl;
}

JoueurBlanc::~JoueurBlanc()
{
  // cout << "Destruction de Joueur Blanc par defaut" << endl;
}

bool
JoueurBlanc::isWhite()
{
  return true;
}

