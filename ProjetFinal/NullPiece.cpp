#include "NullPiece.h"

NullPiece::NullPiece() : Piece(), vectorPossibleMoves_() {

}

void NullPiece::checkPossibleMoves() {
	// Do nothing for the piece has no possible moves. 
}

bool NullPiece::checkIfValidMove(std::shared_ptr<Case> caseToGo) {
	if (vectorPossibleMoves_.empty()) {
		// si le vecteur est vide le créer. 

	}

	for (auto&& move : vectorPossibleMoves_) {

		if (caseToGo == move) {
			return true;
		}

		else {
			return false;
		}
	}
}