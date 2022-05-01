#pragma once
#pragma once
#include <Vector>
#include <memory>
#include "Case.h"
#include "NullPiece.h"
class Echiquier
{
public:
	Echiquier();
	~Echiquier() = default;
	void addPiece(std::shared_ptr<Piece> piece, int row, int collumn);
	void movePiece(std::shared_ptr<Square> squareSelected, std::shared_ptr<Square> squareToGo);

	std::vector<std::vector<std::shared_ptr<Square>>> getVectorSquare() const {
		return vectorSquare_;
	}

	const int getNumberOfRows() { numberOfRows_ = 8; return numberOfRows_; }
	const int getNumberOfCollumns() { numberOfCollumns_ = 8; return numberOfCollumns_; }

	const std::shared_ptr<Square> getCase(int row, int collumn) { return vectorSquare_[row][collumn]; }
	// faire une fonction getcase AVEC row et collonne valeur de retour case*
	// might have to define des opperateur begin et end pour permettre l'ittération facile. 
private:
	std::vector<std::vector<std::shared_ptr<Square>>>  vectorSquare_;
	static int numberOfRows_;
	static int numberOfCollumns_;
};
