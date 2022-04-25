#pragma once
#pragma once
#include "Piece.h"
#include "Case.h"
#include "Echiquier.h"
#include <vector>
class Tour : public ABSPiece {

public:
	Tour();
	~Tour();
	void checkPossibleMoves() override;
	void movePiece() override;
	bool checkIfValidMove(int posX, int posY) override;

private:
	std::unique_ptr<Case> case_;
	std::string name_;
	std::unique_ptr<Echiquier> echiquier_;
	std::vector<std::unique_ptr<Case>> vectorLegalMoves_;
	bool vectorLegalMovesGenerated_;
};