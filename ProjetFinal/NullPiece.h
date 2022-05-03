#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Piece.h"
#include "Square.h"
#include "Echiquier.h"


class NullPiece : public Piece {
public:
	NullPiece(std::shared_ptr<Square> &square);
	~NullPiece() = default;

	virtual std::vector<std::shared_ptr<Square>> checkPossibleMoves(std::unique_ptr<Echiquier>& echiquier) override;
	virtual bool checkIfValidMove(std::shared_ptr<Square> caseToGo, std::unique_ptr<Echiquier>& echiquier)override;

	//const std::vector<std::shared_ptr<Square>> getVectorPossibleMoves() { return vectorPossibleMoves_; }
	//void clearVectorPossibleMoves() { vectorPossibleMoves_.clear(); }

	virtual void setCase(std::shared_ptr<Square> squarePtr) { square_ = squarePtr; }
	virtual const std::string getColor() { return color_; }

private:
	//std::vector<std::shared_ptr<Square>> vectorPossibleMoves_;
	std::shared_ptr<Square> square_;
	int row_;
	int collomn_;
	std::string color_;
};


// MASSIVE ERREUR DE CONCEPTION TROUVÉE. Faut pas oublier que APRÈS un move il faut ittérer sur les pièces d'un player et de forcer
// le delete du vecteur de moves. 