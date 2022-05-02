#ifndef MOVE_H
#define MOVE_H
#include "Move.h"
#endif

std::vector<std::shared_ptr<Square>> Move::checkPossibleMoves(std::unique_ptr<Echiquier>& echiquier) {
	// Ajouter ici que si king en check IMMÉDIATEMENT retourner un vecteur vide. 
	// Ne pas oublier que cette if statement dois être invalid si la piece est un ROI. 
	return this->getPiece()->checkPossibleMoves(echiquier);
}

bool Move::checkIfValidMove(std::unique_ptr<Echiquier>& echiquier) {
	return this->getPiece()->checkIfValidMove(endSquare_, echiquier);
}

void Move::executeMove(std::unique_ptr<Echiquier>& echiquier) {
	// Cette méthode ne fait qu'executer le déplacement, TOUT test doit être fait AVANT l'exécution de cette méthode. 
	endSquare_->addPiece(startSquare_->getPiece());
	startSquare_->removePiece();
}