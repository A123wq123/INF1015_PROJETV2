#pragma once
#include <string>
#include "Square.h"

class Piece
{
public:

	virtual ~Piece() = default;
	//virtual void movePiece(std::shared_ptr<Case> squareTogo);          // Pas sur qu'on vas garder ça.
	virtual std::vector<std::shared_ptr<Square>> checkPossibleMoves(std::unique_ptr<Echiquier>& echiquier) = 0;
	virtual bool checkIfValidMove(std::shared_ptr<Square> squareToGo, std::unique_ptr<Echiquier>& echiquier) = 0;
	// Hésite à passer à une classe move pour permettre la sauvegarde des positions. 

	virtual void setCase(std::shared_ptr<Square> squarePtr) { square_ = squarePtr; }

	virtual const std::string getColor() {
		return color_;
	};

	// dépendament de comment le code évolue il serait intéressant de rajouter une méthode virtuelle pure move(). 

private:
	//std::vector<std::shared_ptr<Square>> vectorPossibleMoves_;
	std::shared_ptr<Square> square_;
	int row_;
	int collomn_;
	std::string color_;
};
