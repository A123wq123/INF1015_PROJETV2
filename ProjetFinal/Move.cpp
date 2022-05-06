#include "Move.h"

std::vector<Square*> Move::checkPossibleMoves(Echiquier* const echiquier) {
	// Ajouter ici que si king en check IMM�DIATEMENT retourner un vecteur vide. 
	// Ne pas oublier que cette if statement dois �tre invalid si la piece est un ROI. 
	return this->getPiece()->checkPossibleMoves(echiquier);
}

bool Move::checkIfValidMove(Echiquier* const echiquier) {
	return this->getPiece()->checkIfValidMove(endSquare_, echiquier);
}

void Move::executeMove(Echiquier* const echiquier) {
	// m�thode qui se charge de faire un mouvement. 
	if (checkIfValidMove(echiquier)) {
		endSquare_->addPiece(startSquare_->getPiece());
		endSquare_->getPiece()->setCase(endSquare_);
		startSquare_->removePiece();
	}
	// otherwise do not execute move. 
}