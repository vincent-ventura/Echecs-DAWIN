/** 
 * Mise en oeuvre de Joueur.h
 *
 * @file Joueur.cxx
 */

// A besoin de la declaration de la classe
#include <iostream>
#include "Joueur.h"

using namespace std;


Joueur::Joueur()
{
  cout << "Construction de Joueur par defaut" << endl;
}

Joueur::~Joueur()
{
  cout << "Destruction de Joueur par defaut" << endl;
}

Joueur::Joueur(bool white)
{

  int p=0;
  int y= (white)?1:8;
  for (int x=1; x<=8; x++)
    m_pieces[p++].init(x,y,white);
  y=(white)?2:7;
  for(int x=1; x<=8; x++)
    m_pieces[p++].init(x,y,white);

  cout << "Construction de Joueur specialise" << endl;
}

bool
Joueur::isWhite()
{
  return m_pieces[0].isWhite();
}

void
Joueur::affiche()
{
  for (int i=0;i<16;i++)
    m_pieces[i].affiche();
}
