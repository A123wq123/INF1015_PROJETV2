#pragma once
#include "Piece.h"

class Tour : public Piece {

public:
	Tour(Square* square, std::string color);
	~Tour() override = default;
	std::vector<Square*> checkPossibleMoves(Echiquier* const echiquier, bool ennableCheckIfKing) override;
	bool checkIfValidMove(Square* caseToGo, Echiquier* const echiquier, bool ennableCheckIfKing) override;
	bool checkIfMoveLinear(Square* caseToGo, Echiquier* const echiquier);
};