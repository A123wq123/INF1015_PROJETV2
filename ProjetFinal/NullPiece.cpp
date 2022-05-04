#include "NullPiece.h"

NullPiece::NullPiece(Square* square) : Piece(square,"","") {

}

std::vector<std::shared_ptr<Square>> NullPiece::checkPossibleMoves(std::unique_ptr<Echiquier>& echiquier) {
	// Do nothing for the piece has no possible moves. But initialise an empty vector to still have the rest of the code work. 
	std::vector<std::shared_ptr<Square>> vectorPossibleMoves{};
	return vectorPossibleMoves;
}

bool NullPiece::checkIfValidMove(std::shared_ptr<Square> squareToGo, std::unique_ptr<Echiquier>& echiquier) {
	// Aucun déplacement ne devrait être valide pour une piece nulle. 
	return false;
}