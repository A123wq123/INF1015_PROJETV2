#ifndef TOUR_H
#define TOUR_H
#include "Tour.h"
#endif

//#pragma once
//#include "Tour.h"
//#pragma once

static const int numberofRowOrCollumn = 8;
Tour::Tour(std::shared_ptr<Square>& square, std::string color) : square_(square), row_(square->getCoordinates().first)
, collomn_(square->getCoordinates().second), color_(color) {

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
		// might want to return true vus que c'est un déplacement de la case A vers elle même mais vas falloir voir avec le code. 
	}

	// check we are tried to eat a same collored piece. 
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
			return true;
		}

		else if (diff < 0) {
			for (int i = 1; i <= abs(diff); i++) {
				if (echiquier->getCase(currentRow, currentCollumn + i)->isOccupied()) {
					return false;
				}
			}
			return true;
		}
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
			return true;
		}

		else if (diff < 0) {
			for (int i = 1; i <= abs(diff); i++) {
				if (echiquier->getCase(currentRow + i, currentCollumn)->isOccupied()) {
					return false;
				}
			}
			return true;
		}
	}
}