#pragma once
#include "Roi.h"

Roi::Roi(std::shared_ptr<Square>& square, std::string color) : square_(square), row_(square->getCoordinates().first), 
	collumn_(square->getCoordinates().second), color_(color) {
	// Create vector of all possible vectorial moves. 
}

const std::vector<std::pair<int, int>> Roi::returnVectorMovementVectoriels() {
	static std::vector<std::pair<int, int>> vectorMovementVectoriels_ = { std::make_pair(-1, -1), std::make_pair(-1, 0), std::make_pair(-1, 1),
	std::make_pair(0, -1), std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(1, -1), std::make_pair(1, 0), std::make_pair(1, 1) };
	return vectorMovementVectoriels_;
}

std::vector<std::shared_ptr<Square>> Roi::checkPossibleMoves(std::unique_ptr<Echiquier>& echiquier) {
	std::vector<std::shared_ptr<Square>> vectorPossibleMoves{};

	// Iterate over all possible vectorial moves 
	for (auto&& mouvement : returnVectorMovementVectoriels()) {
		int destRow = row_ + mouvement.first;
		int destCollumn = collumn_ + mouvement.second;

		// s'assurer que le deplacement de depasse pas l'echiquier. 
		if ((0 <= destRow <= 7) & (0 <= destCollumn <= 7)) {
			// s'assurer que l'on ne tente pas de manger une piece de la meme couleur. 
			if (echiquier->getCase(destRow, destCollumn)->getPiece()->getColor() != color_) {
				vectorPossibleMoves.push_back(echiquier->getCase(destRow, destCollumn));
			}
		}
	}

	return vectorPossibleMoves;

}

bool Roi::checkIfValidMove(std::shared_ptr<Square> squareToGo, std::unique_ptr<Echiquier>& echiquier) {
	return false;
}