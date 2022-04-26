#pragma once
#include "Piece.h"

class NullPiece : Piece {
public:
	NullPiece();
	~NullPiece() = default;

	virtual void checkPossibleMoves();
	virtual bool checkIfValidMove(std::shared_ptr<Case> caseToGo);

	const std::vector<std::shared_ptr<Case>> getVectorPossibleMoves() { return vectorPossibleMoves_; }
	void clearVectorPossibleMoves() { vectorPossibleMoves_.clear(); }

private:
	std::vector<std::shared_ptr<Case>> vectorPossibleMoves_;
};


// MASSIVE ERREUR DE CONCEPTION TROUVÉE. Faut pas oublier que APRÈS un move il faut ittérer sur les pièces d'un player et de forcer
// le delete du vecteur de moves. 