#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Piece.h"
#include "Square.h"
#include "Echiquier.h"


class NullPiece : public Piece {
public:
	NullPiece(Square* square);
	~NullPiece() override = default;

	std::vector<std::shared_ptr<Square>> checkPossibleMoves(std::unique_ptr<Echiquier>& echiquier) override;
	bool checkIfValidMove(std::shared_ptr<Square> caseToGo, std::unique_ptr<Echiquier>& echiquier) override;

	//const std::vector<std::shared_ptr<Square>> getVectorPossibleMoves() { return vectorPossibleMoves_; }
	//void clearVectorPossibleMoves() { vectorPossibleMoves_.clear(); }



};


// MASSIVE ERREUR DE CONCEPTION TROUVÉE. Faut pas oublier que APRÈS un move il faut ittérer sur les pièces d'un player et de forcer
// le delete du vecteur de moves. 