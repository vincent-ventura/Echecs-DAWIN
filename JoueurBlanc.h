/** 
 * Header de JoueurBlanc.cxx
 *
 * @file JoueurBlanc.h
 */

#ifndef JoueurBlanc_h
#define JoueurBlanc_h

#include "Joueur.h"

class JoueurBlanc: public Joueur 
{

protected:


public:
JoueurBlanc();
~JoueurBlanc();
bool isWhite();
};

#endif // !defined JoueurBlanc_h
