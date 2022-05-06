#pragma once
#include "Fou.h"

Fou::Fou(Square* square, std::string color) : Piece(square, color, color + "Fou") {

}

//std::shared_ptr<Piece> copy(const std::shared_ptr<Piece> piece)
//
//Fou::Fou(const Fou& fou) : Piece(fou) {
//	this->setCase(nullptr);
//}

std::vector<Square*> Fou::checkPossibleMoves(Echiquier* const echiquier) {
	std::vector<Square*> vectorPossibleMoves{};

	for (int row = 0; row < echiquier->getNumberOfRows(); row++) {
		for (int collumn = 0; collumn < echiquier->getNumberOfCollumns(); collumn++) {
			if (this->checkIfValidMove(echiquier->getCase(row, collumn), echiquier)) {
				vectorPossibleMoves.push_back(echiquier->getCase(row, collumn));
			}
		}
	}
	return vectorPossibleMoves;
}

bool Fou::checkIfValidMove(Square* caseToGo, Echiquier* const echiquier) {
	// check if dest is same as start. 
	if (caseToGo == square_) { return false; }

	// check if we are trying to eat a same collored piece.
	if (caseToGo->getPiece()->getColor() == color_) { return false; }

	// check if move diagonal.
	if (false == this->checkIfMoveDIagonal(caseToGo, echiquier)) { return false; }

	int diffRow = this->row() - caseToGo->getCoordinates().first;
	int diffCollumn = this->collumn() - caseToGo->getCoordinates().second;

	// check for move "North"
	if (diffRow > 0) {
		// check for move "North-West".
		if (diffCollumn > 0) {
			// check if piece in way of move.
			for (int i = 1; i < diffRow; i++) {
				if (echiquier->getCase(this->row() - i, this->collumn() - i)->isOccupied()) {
					return false;
				}
			}
		}

		// check if move "North-East"
		else if (diffCollumn > 0) {
			// check if piece in way of move.
			for (int i = 1; i < diffRow; i++) {
				if (echiquier->getCase(this->row() - i, this->collumn() + i)->isOccupied()) {
					return false;
				}
			}
		}
	}

	// check if move "South"
	else if (diffRow < 0) {
		// check if move "South-West"
		if (diffCollumn > 0) {
			// check if piece in way of move.
			for (int i = 1; i < abs(diffRow); i++) {
				if (echiquier->getCase(this->row() + i, this->collumn() - i)->isOccupied()) {
					return false;
				}
			}
		}

		// check if move "South-East"
		else if (diffCollumn < 0) {
			// check if piece in way of move.
			for (int i = 1; i < abs(diffRow); i++) {
				if (echiquier->getCase(this->row() + i, this->collumn() + i)->isOccupied()) {
					return false;
				}
			}
		}
	}

	// check if own king in check after move
	if (echiquier->isKingInCheckAfterMove(color_, square_, caseToGo)) {
		return false;
	}
	return true; 
}

bool Fou::checkIfMoveDIagonal(Square* caseToGo, Echiquier* const echiquier) {
	int diffRow = abs(caseToGo->getCoordinates().first - this->row());
	int diffCollumn = abs(caseToGo->getCoordinates().second - this->collumn());
	if (diffCollumn == diffRow) { return true; }
	return false;
}