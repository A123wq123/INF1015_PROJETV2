#include "Tour.h"
#include <iostream>

//#pragma once
//#include "Tour.h"
//#pragma once

static const int numberofRowOrCollumn = 8;
Tour::Tour(Square* square, std::string color) : Piece(square,color, color + "Tour") {

}

std::vector<Square*> Tour::checkPossibleMoves(Echiquier* const echiquier, bool ennableCheckIfKing) {
	std::vector<Square*> vectorPossibleMoves{};
	
	// itterate on all squares: 
	for (int row = 0; row < echiquier->getNumberOfRows(); row++) {
		for (int collumn = 0; collumn < echiquier->getNumberOfCollumns(); collumn++) {
			if (this->checkIfValidMove(echiquier->getCase(row, collumn), echiquier, ennableCheckIfKing)) {
				vectorPossibleMoves.push_back(echiquier->getCase(row, collumn));
			}
		}
	}

	return vectorPossibleMoves;
}


bool Tour::checkIfValidMove(Square* squareDest, Echiquier* const echiquier, bool ennableCheckIfKing) {
	int currentRow = square_->getCoordinates().first;
	int destRow = squareDest->getCoordinates().first;
	int currentCollumn = square_->getCoordinates().second;
	int destCollumn = squareDest->getCoordinates().second;

	// check if end pos is same as start.
	if (square_ == squareDest) { return false; }

	// check if we are trying to eat a same collored piece. 
	else if (squareDest->getPiece()->getColor() == color_) { return false; }

	// check if move is linear (not diagonal or like a kight).
	else if (false == this->checkIfMoveLinear(squareDest, echiquier)) { return false; }

	// check if move is horizontal
	else if (currentRow == destRow) {
		int diff = currentCollumn - destCollumn;

		// check if piece in the way of move
		if (diff > 0) {
			for (int i = 1; i < diff; i++) {
				if (echiquier->getCase(currentRow, currentCollumn - i)->isOccupied()) {
					return false;
				}
			}
		}

		else if (diff < 0) {
			for (int i = 1; i < abs(diff); i++) {
				if (echiquier->getCase(currentRow, currentCollumn + i)->isOccupied()) {
					return false;
				}
			}
		}
	}

	// Check if move is vectical.
	else if (currentCollumn == destCollumn) {
		int diff = currentRow - destRow;

		// Check if piece in way of move. 
		if (diff > 0) {
			for (int i = 1; i < diff; i++) {
				if (echiquier->getCase(currentRow - i, currentCollumn)->isOccupied()) {
					return false;
				}
			}
		}

		else if (diff < 0) {
			for (int i = 1; i < abs(diff); i++) {
				if (echiquier->getCase(currentRow + i, currentCollumn)->isOccupied()) {
					return false;
				}
			}
		}
	}

	// check si le déplacement mets notre roi en echec. 
	if (ennableCheckIfKing) {
		if (false == echiquier->isKingInCheckAfterMove(color_, square_, squareDest)) {
			return true;
		}
		return false;
	}
	else {
		return true;
	}
}

bool Tour::checkIfMoveLinear(Square* caseToGo, Echiquier* const echiquier) {
	if ((this->row() == caseToGo->getCoordinates().first) || (this->collumn() == caseToGo->getCoordinates().second)) {
		return true;
	}
	return false;
}