#pragma once
#include <string>
#include "Case.h"

class Piece
{
public:
	Piece();
	~Piece() = default;

	//virtual void movePiece(std::shared_ptr<Case> squareTogo);          // Pas sur qu'on vas garder �a.
	virtual void checkPossibleMoves() = 0;
	virtual bool checkIfValidMove(std::shared_ptr<Case> caseToGo) = 0;
	// H�site � passer � une classe move pour permettre la sauvegarde des positions. 

	void setCase(std::shared_ptr<Case> casePtr) { case_ = casePtr; }

private:
	std::shared_ptr<Case> case_;
};
