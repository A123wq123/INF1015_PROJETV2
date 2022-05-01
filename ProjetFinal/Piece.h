#pragma once
#include <string>
#include "Square.h"

class Piece
{
public:

	//virtual void movePiece(std::shared_ptr<Case> squareTogo);          // Pas sur qu'on vas garder �a.
	virtual void checkPossibleMoves() = 0;
	virtual bool checkIfValidMove(std::shared_ptr<Square> squareToGo) = 0;
	// H�site � passer � une classe move pour permettre la sauvegarde des positions. 

	virtual void setCase(std::shared_ptr<Square> squarePtr) = 0;

	virtual const std::string getColor() = 0;

	// d�pendament de comment le code �volue il serait int�ressant de rajouter une m�thode virtuelle pure move(). 

private:
};
