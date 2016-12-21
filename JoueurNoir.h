/** 
 * Header de JoueurNoir.cxx
 *
 * @file JoueurNoir.h
 */

#ifndef JoueurNoir_h
#define JoueurNoir_h

#include "Joueur.h"

class JoueurNoir: public Joueur 
{

protected:


public:
JoueurNoir();
~JoueurNoir();
bool isWhite();
};

#endif // !defined JoueurNoir_h
