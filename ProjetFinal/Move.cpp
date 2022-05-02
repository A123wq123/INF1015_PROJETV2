#ifndef MOVE_H
#define MOVE_H
#include "Move.h"
#endif

std::vector<std::shared_ptr<Square>> Move::checkPossibleMoves(std::unique_ptr<Echiquier>& echiquier) {
	// Ajouter ici que si king en check IMM�DIATEMENT retourner un vecteur vide. 
	// Ne pas oublier que cette if statement dois �tre invalid si la piece est un ROI. 
	return this->getPiece()->checkPossibleMoves(echiquier);
}

bool Move::checkIfValidMove(std::unique_ptr<Echiquier>& echiquier) {
	return this->getPiece()->checkIfValidMove(endSquare_, echiquier);
}

void Move::executeMove(std::unique_ptr<Echiquier>& echiquier) {
	// Cette m�thode ne fait qu'executer le d�placement, TOUT test doit �tre fait AVANT l'ex�cution de cette m�thode. 
	endSquare_->addPiece(startSquare_->getPiece());
	startSquare_->removePiece();
}