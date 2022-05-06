#pragma once
#include "Piece.h"

class Tour : public Piece {

public:
	Tour(Square* square, std::string color);
	~Tour() override = default;
	std::vector<Square*> checkPossibleMoves(Echiquier* const echiquier) override;
	bool checkIfValidMove(Square* caseToGo, Echiquier* const echiquier) override;
	bool checkIfMoveLinear(Square* caseToGo, Echiquier* const echiquier);
};