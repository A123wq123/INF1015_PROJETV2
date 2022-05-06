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

	std::vector<Square*> checkPossibleMoves(Echiquier* const echiquier, bool ennableCheckIfKing) override;
	bool checkIfValidMove(Square* caseToGo, Echiquier* const echiquier, bool ennableCheckIfKing) override;

	//const std::vector<std::shared_ptr<Square>> getVectorPossibleMoves() { return vectorPossibleMoves_; }
	//void clearVectorPossibleMoves() { vectorPossibleMoves_.clear(); }



};


// MASSIVE ERREUR DE CONCEPTION TROUVÉE. Faut pas oublier que APRÈS un move il faut ittérer sur les pièces d'un player et de forcer
// le delete du vecteur de moves. 