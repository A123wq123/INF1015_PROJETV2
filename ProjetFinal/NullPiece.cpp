#include "NullPiece.h"

NullPiece::NullPiece(std::shared_ptr<Square>& square) : Piece(), vectorPossibleMoves_(), square_(square), color_("Null") {

}

void NullPiece::checkPossibleMoves() {
	// Do nothing for the piece has no possible moves. 
}

bool NullPiece::checkIfValidMove(std::shared_ptr<Square> squareToGo) {

	return false;
}