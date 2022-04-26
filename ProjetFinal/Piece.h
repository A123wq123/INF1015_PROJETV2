#pragma once
#include <string>
#include "Case.h"

class Piece
{
public:
	Piece();
	~Piece();

	//virtual void movePiece(std::shared_ptr<Case> squareTogo);          // Pas sur qu'on vas garder ça.
	virtual void checkPossibleMoves();
	virtual bool checkIfValidMove(int posX, int posY);

private:
	std::string color;
	std::shared_ptr<Case> case_;
	std::vector<std::shared_ptr<Case>> vectorPossibleMoves_;
};
