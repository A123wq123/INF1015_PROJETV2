#pragma once
#include "Roi.h"

Roi::Roi(Square* square, std::string color) : Piece(square,color, color + "King") {

}

//Roi::Roi(const Roi& roi) : Piece(roi) {
//	this->setCase(nullptr);
//}

std::vector<Square*> Roi::returnVectorMovements(Echiquier* const echiquier) {

	std::vector<Square*> vectorSquares{};

	// Vector of all possible mouvements. 
	static std::vector<std::pair<int, int>> vectorMovementVectoriels_ = { std::make_pair(-1, -1), std::make_pair(-1, 0), std::make_pair(-1, 1),
	std::make_pair(0, -1), std::make_pair(0, 1), std::make_pair(1, -1), std::make_pair(1, 0), std::make_pair(1, 1)};

	// Return all squares resulting from the application of the above vector.
	for (auto&& mouvement : vectorMovementVectoriels_) {
		int destRow = row() + mouvement.first;
		int destCollumn = collumn() + mouvement.second;

		// s'assurer que le deplacement de depasse pas l'echiquier. 
		if ((0 <= destRow <= 7) && (0 <= destCollumn <= 7)) {
			// check if trying to eat same collored piece. 
			if (echiquier->getCase(destRow, destCollumn)->getPiece()->getColor() != color_) {
				vectorSquares.push_back(echiquier->getCase(destRow, destCollumn));
			}
		}
	}
	return vectorSquares;
}

std::vector<Square*> Roi::checkPossibleMoves(Echiquier* const echiquier) {
	std::vector<Square*> vectorPossibleMoves{};

	// Iterate over all squares.
	for (int row = 0; row < echiquier->getNumberOfRows(); row++) {
		for (int collumn = 0; collumn < echiquier->getNumberOfCollumns(); collumn++) {
			if (this->checkIfValidMove(echiquier->getCase(row, collumn), echiquier)) {
				vectorPossibleMoves.push_back(echiquier->getCase(row, collumn));
			}
		}
	}

	return vectorPossibleMoves;

}

bool Roi::checkIfValidMove(Square* squareToGo, Echiquier* const echiquier) {
	// check if dest is same as current.
	if (squareToGo == square_) { return false; }

	// Ne pas manger une piece de sa couleur.
	if (squareToGo->getPiece()->getColor() == color_) { return false; }

	// check if move outside range king. 
	if (false == this->checkIfMoveToFar(squareToGo, echiquier)) { return false; }

	// check if move from vectorMouvements vectoriels.
	for (auto&& square : this->returnVectorMovements(echiquier)) {
		// check if dest is in the squares around the king. 
		if (squareToGo == square) {
			// check if king in check after move.
			if (false == echiquier->isKingInCheckAfterMove(color_, square_, squareToGo)) {
				return true;
			}
		}
	}
	return false;
}

bool Roi::checkIfMoveToFar(Square* squareToGo, Echiquier* const echiquier) {
	int diffRow = abs(squareToGo->getCoordinates().first - this->row());
	int diffCollumn = abs(squareToGo->getCoordinates().second - this->collumn());
	if ((diffRow < 2) && (diffCollumn < 2)) {
		return true;
	}
	return false;
}