#pragma once
#include "Roi.h"

Roi::Roi(Square* square, std::string color) : Piece(square,color, color + "King") {

}

const std::vector<std::pair<int, int>> Roi::returnVectorMovementVectoriels() {
	static std::vector<std::pair<int, int>> vectorMovementVectoriels_ = { std::make_pair(-1, -1), std::make_pair(-1, 0), std::make_pair(-1, 1),
	std::make_pair(0, -1), std::make_pair(0, 1), std::make_pair(1, -1), std::make_pair(1, 0), std::make_pair(1, 1) };
	return vectorMovementVectoriels_;
}

std::vector<std::shared_ptr<Square>> Roi::checkPossibleMoves(std::unique_ptr<Echiquier>& echiquier) {
	std::vector<std::shared_ptr<Square>> vectorPossibleMoves{};

	// Iterate over all possible vectorial moves 
	for (auto&& mouvement : returnVectorMovementVectoriels()) {
		int destRow = row() + mouvement.first;
		int destCollumn = collumn() + mouvement.second;

		// s'assurer que le deplacement de depasse pas l'echiquier. 
		if ((0 <= destRow <= 7) && (0 <= destCollumn <= 7)) {
			// s'assurer que l'on ne tente pas de manger une piece de la meme couleur. 
			if (echiquier->getCase(destRow, destCollumn)->getPiece()->getColor() != color_) {
				// Ajouter un test pour si board en echec. 
				if (false == echiquier->isKingInCheckAfterMove(color_, square_, echiquier->getCase(destRow, destCollumn).get())) {
					vectorPossibleMoves.push_back(echiquier->getCase(destRow, destCollumn));
				}
			}
		}
	}

	return vectorPossibleMoves;

}

bool Roi::checkIfValidMove(std::shared_ptr<Square> squareToGo, std::unique_ptr<Echiquier>& echiquier) {
	// Ne pas manger une piece de sa couleur.

	if (squareToGo->getPiece()->getColor() != color_) {
		for (auto&& squarePtr : this->checkPossibleMoves(echiquier)) {
			if (squarePtr == squareToGo) {
				return true;
			}
		}
	}
	// ajouter la condition de si king not in check.

	return false;
}