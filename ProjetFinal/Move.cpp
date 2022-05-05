#include "Move.h"

std::vector<std::shared_ptr<Square>> Move::checkPossibleMoves(std::unique_ptr<Echiquier>& echiquier) {
	// Ajouter ici que si king en check IMMÉDIATEMENT retourner un vecteur vide. 
	// Ne pas oublier que cette if statement dois être invalid si la piece est un ROI. 
	return this->getPiece()->checkPossibleMoves(echiquier);
}

bool Move::checkIfValidMove(std::unique_ptr<Echiquier>& echiquier) {
	return this->getPiece()->checkIfValidMove(std::shared_ptr<Square>(endSquare_), echiquier);
}

void Move::executeMove(std::unique_ptr<Echiquier>& echiquier) {
	// méthode qui se charge de faire un mouvement. 
	if (checkIfValidMove(echiquier)) {
		endSquare_->addPiece(startSquare_->getPiece());
		endSquare_->getPiece()->setCase(endSquare_);
		startSquare_->removePiece();
	}
	// otherwise do not execute move. 
}