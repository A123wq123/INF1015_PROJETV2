#pragma once
#include <string>
#include "Square.h"

class Piece
{
public:

	virtual ~Piece() = default;
	//virtual void movePiece(std::shared_ptr<Case> squareTogo);          // Pas sur qu'on vas garder �a.
	virtual std::vector<std::shared_ptr<Square>> checkPossibleMoves(std::unique_ptr<Echiquier>& echiquier) = 0;
	virtual bool checkIfValidMove(std::shared_ptr<Square> squareToGo, std::unique_ptr<Echiquier>& echiquier) = 0;
	// H�site � passer � une classe move pour permettre la sauvegarde des positions. 

	virtual void setCase(std::shared_ptr<Square> squarePtr) { square_ = squarePtr; }

	virtual const std::string getColor() {
		return color_;
	};

	// d�pendament de comment le code �volue il serait int�ressant de rajouter une m�thode virtuelle pure move(). 

private:
	//std::vector<std::shared_ptr<Square>> vectorPossibleMoves_;
	std::shared_ptr<Square> square_;
	int row_;
	int collomn_;
	std::string color_;
};
