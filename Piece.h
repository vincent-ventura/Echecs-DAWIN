/** 
 * Header de Piece.cxx
 *
 * @file Piece.h
 */

#ifndef Piece_h
#define Piece_h

#include "Echiquier.h" //pb de reference croisee
class Echiquier;

/**
 * Declaration d'une classe modélisant une piece de jeu d'echec.
 */
class Piece 
{
protected:
  int m_x;
  int m_y;
  bool m_white;
  bool m_on_board;
  
public:
  Piece();
  Piece(const Piece & autre);
  virtual ~Piece();
  Piece( int x, int y, bool white );
  Piece & operator=( const Piece & autre);
  const Piece & plusforte(const Piece & autre) const;
  void init( int x, int y, bool white );
  void move( int x, int y );
  int x() const;
  int y() const;
  bool isWhite() const;
  bool isBlack() const;
  void affiche() const;
  bool samePosition(const Piece & p2) const;
  virtual bool mouvementValide(Echiquier &e, int x, int y) =0; //methode virtuelle PURE -> classe abstraite (non instanciable) !
  virtual char myChar();
  bool getOnBoard() const;
  void setOnBoard(bool onBoard);
}; 

#endif // !defined Piece_h
