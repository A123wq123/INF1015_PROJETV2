#include "Tour.h"

//#pragma once
//#include "Tour.h"
//#pragma once

static const int numberofRowOrCollumn = 8;
Tour::Tour(std::shared_ptr<Square>& square, std::string color) : square_(square), row_(square->getCoordinates().first)
, collomn_(square->getCoordinates().second), color_(color) {
	if (color_ == "White") {
		name_ = "WhiteTower";
	}
	else {
		name_ = "BlackTower";
	}
}

std::vector<std::shared_ptr<Square>> Tour::checkPossibleMoves(std::unique_ptr<Echiquier>& echiquier) {
	std::vector<std::shared_ptr<Square>> vectorPossibleMoves{};

	// regarde pour les déplacements verticaux 
	for (int counter = 0; counter < numberofRowOrCollumn; counter++)
	{
		std::shared_ptr<Square> squareBeingChecked = echiquier->getCase(square_->getCoordinates().first, counter);
		if (checkIfValidMove(squareBeingChecked, echiquier))
		{
			vectorPossibleMoves.push_back(squareBeingChecked);
		}

	}

	// regarde pour les déplacements horizontaux
	for (int counter = 0; counter < numberofRowOrCollumn; counter++)
	{
		std::shared_ptr<Square> squareBeingChecked = echiquier->getCase(counter, square_->getCoordinates().second);
		if (checkIfValidMove(squareBeingChecked, echiquier))
		{
			vectorPossibleMoves.push_back(squareBeingChecked);

		}
	}
	return vectorPossibleMoves;
}


bool Tour::checkIfValidMove(std::shared_ptr<Square> squareDest, std::unique_ptr<Echiquier>& echiquier) {
	int currentRow = square_->getCoordinates().first;
	int destRow = squareDest->getCoordinates().first;
	int currentCollumn = square_->getCoordinates().second;
	int destCollumn = squareDest->getCoordinates().second;

	// check if end pos is same as start.
	if (square_ == squareDest) {
		return false;
	}

	// check if we are trying to eat a same collored piece. 
	else if (squareDest->getPiece()->getColor() == color_) {
		return false;
	}

	// check if move is horizontal
	else if (currentRow == destRow) {
		int diff = currentCollumn - destCollumn;

		// check if piece in the way of move
		if (diff > 0) {
			for (int i = 1; i <= diff; i++) {
				if (echiquier->getCase(currentRow, currentCollumn - i)->isOccupied()) {
					return false;
				}
			}
		}

		else if (diff < 0) {
			for (int i = 1; i <= abs(diff); i++) {
				if (echiquier->getCase(currentRow, currentCollumn + i)->isOccupied()) {
					return false;
				}
			}
		}

		// check si le déplacement mets notre roi en echec. 
		if (false == echiquier->isKingInCheckAfterMove(color_, square_, squareDest)) {
			return true;
		}
		return false;
	}

	// Check if move is vectical.
	else if (currentCollumn == destCollumn) {
		int diff = currentRow - destRow;

		// Check if piece in way of move. 
		if (diff > 0) {
			for (int i = 1; i <= diff; i++) {
				if (echiquier->getCase(currentRow - i, currentCollumn)->isOccupied()) {
					return false;
				}
			}
		}

		else if (diff < 0) {
			for (int i = 1; i <= abs(diff); i++) {
				if (echiquier->getCase(currentRow + i, currentCollumn)->isOccupied()) {
					return false;
				}
			}
		}

		// check si le déplacement mets notre roi en echec. 
		if (false == echiquier->isKingInCheckAfterMove(color_, square_, squareDest)) {
			return true;
		}
		return false;
	}
}