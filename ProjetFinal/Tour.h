#pragma once
#pragma once
#include "Piece.h"
#include "Square.h"
#include "Echiquier.h"
#include <vector>
class Tour : public Piece {

public:
	Tour(std::shared_ptr<Square>& square, std::string color);
	~Tour() = default;
	std::vector<std::shared_ptr<Square>> checkPossibleMoves(std::unique_ptr<Echiquier>& echiquier) override;
	bool checkIfValidMove(std::shared_ptr<Square> caseToGo, std::unique_ptr<Echiquier>& echiquier) override;

private:
	std::shared_ptr<Square> square_;
	int row_;
	int collomn_;
	std::string color_;
};