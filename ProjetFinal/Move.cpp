#include "Move.h"

std::vector<std::shared_ptr<Square>> Move::checkPossibleMoves(std::unique_ptr<Echiquier>& echiquier) {
	return this->getPiece()->checkPossibleMoves(echiquier);
}

bool Move::checkIfValidMove(std::unique_ptr<Echiquier>& echiquier) {
	return this->getPiece()->checkIfValidMove(endSquare_, echiquier);
}

void Move::executeMove(std::unique_ptr<Echiquier>& echiquier) {
	if (checkIfValidMove(echiquier)) {
		endSquare_->addPiece(startSquare_->getPiece());
		startSquare_->removePiece();
	}
	else {
		// the move is invalid, send info in console to signify?
	}

	// Ajouter signal to update UI?
}