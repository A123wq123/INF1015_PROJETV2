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


// MASSIVE ERREUR DE CONCEPTION TROUV�E. Faut pas oublier que APR�S un move il faut itt�rer sur les pi�ces d'un player et de forcer
// le delete du vecteur de moves. 