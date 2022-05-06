#include "NullPiece.h"

NullPiece::NullPiece(Square* square) : Piece(square,"","") {

}

std::vector<Square*> NullPiece::checkPossibleMoves(Echiquier* const echiquier) {
	// Do nothing for the piece has no possible moves. But initialise an empty vector to still have the rest of the code work. 
	std::vector<Square*> vectorPossibleMoves{};
	return vectorPossibleMoves;
}

bool NullPiece::checkIfValidMove(Square* squareToGo, Echiquier* const echiquier) {
	// Aucun déplacement ne devrait être valide pour une piece nulle. 
	return false;
}