#pragma once
#include "Piece.h"

class NullPiece : Piece {
public:
	NullPiece(std::shared_ptr<Square> &square);
	~NullPiece() = default;

	virtual void checkPossibleMoves();
	virtual bool checkIfValidMove(std::shared_ptr<Square> caseToGo);

	const std::vector<std::shared_ptr<Square>> getVectorPossibleMoves() { return vectorPossibleMoves_; }
	void clearVectorPossibleMoves() { vectorPossibleMoves_.clear(); }
	virtual void setCase(std::shared_ptr<Square> squarePtr) { square_ = squarePtr;  }
	virtual void getColor() { return color_; }

private:
	std::vector<std::shared_ptr<Square>> vectorPossibleMoves_;
	std::shared_ptr<Square> square_;
	int row_;
	int collomn_;
	std::string color_;
};


// MASSIVE ERREUR DE CONCEPTION TROUV�E. Faut pas oublier que APR�S un move il faut itt�rer sur les pi�ces d'un player et de forcer
// le delete du vecteur de moves. 