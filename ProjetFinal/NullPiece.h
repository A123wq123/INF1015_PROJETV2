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


// MASSIVE ERREUR DE CONCEPTION TROUV�E. Faut pas oublier que APR�S un move il faut itt�rer sur les pi�ces d'un player et de forcer
// le delete du vecteur de moves. 