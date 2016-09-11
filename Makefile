SRC_CXX=Piece.cxx Joueur.cxx

OBJ=${SRC_CXX:.cxx=.o}

all: testPiece

testPiece: $(OBJ) testPiece.o
	g++ $(OBJ) testPiece.o -o testPiece

%.o: %.cxx
	g++ -c $<

clean:
	@rm -f $(OBJ) testPiece.o testPiece *~

