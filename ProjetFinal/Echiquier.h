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

	std::vector<std::vector<std::shared_ptr<Square>>> getVectorSquare() const {
		return vectorSquare_;
	}

	const int getNumberOfRows() { numberOfRows_ = 8; return numberOfRows_; }
	const int getNumberOfCollumns() { numberOfCollumns_ = 8; return numberOfCollumns_; }
	std::unique_ptr<Echiquier> getPtrEchiquier() { return std::unique_ptr<Echiquier>(this); }

	std::shared_ptr<Square> findSquareKing(std::string color);

	std::shared_ptr<Square> getCase(int row, int collumn) { return vectorSquare_[row][collumn]; }

	std::set<std::shared_ptr<Square>> getSetSquaresAttacked(std::string colorOfPieces);
	bool isKingInCheck(std::string colorOfKing);
	bool isKingInCheckAfterMove(std::string colorOfKing, Square* currentPos, Square* dest);
	// faire une fonction getcase AVEC row et collonne valeur de retour case*
	// might have to define des opperateur begin et end pour permettre l'ittération facile. 
private:
	std::vector<std::vector<std::shared_ptr<Square>>>  vectorSquare_;
	int numberOfRows_;
	int numberOfCollumns_;
};
