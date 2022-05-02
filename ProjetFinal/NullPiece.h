#pragma once
#include "Piece.h"

class NullPiece : Piece {
public:
	NullPiece(std::shared_ptr<Square> &square);
	~NullPiece() = default;

	virtual std::vector<std::shared_ptr<Square>> checkPossibleMoves(std::unique_ptr<Echiquier> echiquier);
	virtual bool checkIfValidMove(std::shared_ptr<Square> caseToGo, std::unique_ptr<Echiquier> echiquier);

	//const std::vector<std::shared_ptr<Square>> getVectorPossibleMoves() { return vectorPossibleMoves_; }
	//void clearVectorPossibleMoves() { vectorPossibleMoves_.clear(); }

private:
	//std::vector<std::shared_ptr<Square>> vectorPossibleMoves_;
	std::shared_ptr<Square> square_;
	int row_;
	int collomn_;
	std::string color_;
};


// MASSIVE ERREUR DE CONCEPTION TROUVÉE. Faut pas oublier que APRÈS un move il faut ittérer sur les pièces d'un player et de forcer
// le delete du vecteur de moves. 