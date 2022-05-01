#pragma once
#include <string>
#include "Square.h"

class Piece
{
public:

	//virtual void movePiece(std::shared_ptr<Case> squareTogo);          // Pas sur qu'on vas garder ça.
	virtual void checkPossibleMoves() = 0;
	virtual bool checkIfValidMove(std::shared_ptr<Square> squareToGo) = 0;
	// Hésite à passer à une classe move pour permettre la sauvegarde des positions. 

	virtual void setCase(std::shared_ptr<Square> squarePtr) = 0;

	virtual const std::string getColor() = 0;

	// dépendament de comment le code évolue il serait intéressant de rajouter une méthode virtuelle pure move(). 

private:
};
