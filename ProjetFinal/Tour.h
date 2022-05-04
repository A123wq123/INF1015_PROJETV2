#pragma once
#include "Piece.h"

class Tour : public Piece {

public:
	Tour(Square* square, std::string color);
	~Tour() override = default;
	std::vector<std::shared_ptr<Square>> checkPossibleMoves(std::unique_ptr<Echiquier>& echiquier) override;
	bool checkIfValidMove(std::shared_ptr<Square> caseToGo, std::unique_ptr<Echiquier>& echiquier) override;
};