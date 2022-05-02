#ifndef NULLPIECE_H
#define NULLPIECE_H
#include "NullPiece.h"
#endif

NullPiece::NullPiece(std::shared_ptr<Square>& square) : Piece(), square_(square), row_(square->getCoordinates().first) 
, collomn_(square->getCoordinates().second), color_("Null") {

}

std::vector<std::shared_ptr<Square>> NullPiece::checkPossibleMoves(std::unique_ptr<Echiquier>& echiquier) {
	// Do nothing for the piece has no possible moves. But initialise an empty vector to still have the rest of the code work. 
	std::vector<std::shared_ptr<Square>> vectorPossibleMoves{};
	return vectorPossibleMoves;
}

bool NullPiece::checkIfValidMove(std::shared_ptr<Square> squareToGo, std::unique_ptr<Echiquier>& echiquier) {
	// Aucun d�placement ne devrait �tre valide pour une piece nulle. 
	return false;
}