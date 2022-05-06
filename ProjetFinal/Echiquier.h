#pragma once
#include <vector>
#include <memory>
#include <set>
#include "Piece.h"
#include "Square.h"


class Piece;
class Square;

class Echiquier
{
public:
	Echiquier();
	~Echiquier() = default;
	void addPiece(std::shared_ptr<Piece> piece, int row, int collumn);
	//void movePiece(std::shared_ptr<Square> squareSelected, std::shared_ptr<Square> squareToGo);

	const int getNumberOfRows() { return 8; }
	const int getNumberOfCollumns() { return 8; }

	Square* findSquareKing(std::string color);

	Square* getCase(int row, int collumn) { return vectorSquare_[row][collumn].get(); }

	std::set<Square*> getSetSquaresAttacked(std::string colorOfPieces);
	bool isKingInCheck(std::string colorOfKing);
	bool isKingInCheckAfterMove(std::string colorOfKing, Square* currentPos, Square* dest);
	bool isKingInCheckMate(std::string colorOfKing);
	// faire une fonction getcase AVEC row et collonne valeur de retour case*
	// might have to define des opperateur begin et end pour permettre l'ittération facile. 
private:
	std::vector<std::vector<std::unique_ptr<Square>>>  vectorSquare_;
};
