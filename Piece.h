/** 
 * Header de Piece.cxx
 *
 * @file Piece.h
 */

#ifndef Piece_h
#define Piece_h

/**
 * Declaration d'une classe modélisant une piece de jeu d'echec.
 */
class Piece 
{
private:
  int m_x;
  int m_y;
  bool m_white;
  
public:
  Piece();
  Piece(const Piece & p);
  ~Piece();
  Piece( int x, int y, bool white );
  void init( int x, int y, bool white );
  void move( int x, int y );
  int x() const;
  int y() const;
  bool isWhite() const;
  bool isBlack() const;
  void affiche() const;
  bool samePosition(Piece p2) const;
}; 

#endif // !defined Piece_h
