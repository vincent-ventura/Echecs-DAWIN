SRC_CXX=Piece.cxx Joueur.cxx Echiquier.cxx JoueurBlanc.cxx JoueurNoir.cxx Pion.cxx Roi.cxx Cavalier.cxx Tour.cxx Fou.cxx Reine.cxx
OBJ=${SRC_CXX:.cxx=.o}

all: jeuDEchecs

jeuDEchecs: $(OBJ) jeuDEchecs.o
	g++ $(OBJ) jeuDEchecs.o -o jeuDEchecs

%.o: %.cxx
	# g++ -c $<
	g++ -std=c++11 -c $<

clean:
	@rm -f $(OBJ) jeuDEchecs.o jeuDEchecs *~

