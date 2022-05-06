#include "Move.h"

std::vector<Square*> Move::checkPossibleMoves(Echiquier* const echiquier) {
	// Ajouter ici que si king en check IMMÉDIATEMENT retourner un vecteur vide. 
	// Ne pas oublier que cette if statement dois être invalid si la piece est un ROI. 
	return this->getPiece()->checkPossibleMoves(echiquier, true);
}

bool Move::checkIfValidMove(Echiquier* const echiquier) {
	return this->getPiece()->checkIfValidMove(endSquare_, echiquier, true);
}

void Move::executeMove(Echiquier* const echiquier) {
	// méthode qui se charge de faire un mouvement. 
	try {
		if (checkIfValidMove(echiquier)) {
			endSquare_->addPiece(startSquare_->getPiece());
			endSquare_->getPiece()->setCase(endSquare_);
			startSquare_->removePiece();
			std::cout << " Move was legal. " << std::endl;
		}
		else {
			std::cout << " Move was not legal. " << std::endl;
		}
	}
	catch (...) {
		std::cout << "The move was illigal for some unknown reason and has been terminated" << std::endl;
	}
	
}