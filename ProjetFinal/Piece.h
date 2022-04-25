#pragma once
#include <string>

class ABSPiece
{
public:

	virtual void movePiece() = 0;
	virtual void checkPossibleMoves() = 0;
	virtual bool checkIfValidMove(int posX, int posY) = 0;

};
