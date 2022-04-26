#include "Echiquier.h"


Echiquier::Echiquier() : vectorCase_() {
	bool isWhite = false;
	for (int row = 0; row < getNumberOfRows(); row++) {
		!isWhite;           // Alterne le noir blanc à chaque ligne.
		for (int collumn = 0; collumn < getNumberOfCollumns(); collumn++) {
			vectorCase_[row][collumn] = std::make_shared<Case>(Case(row, collumn, isWhite));
			!isWhite;       // alterne le noir blanc à chaque colonne. 
		}
	}
}

void Echiquier::addPiece(std::shared_ptr<Piece> piece, int row, int collumn) {
	getVectorCase()[row][collumn]->addPiece(piece);
}


void Echiquier::movePiece(std::shared_ptr<Case> caseOfPiece, std::shared_ptr<Case> caseToGo) {
	//std::shared_ptr<Piece> pieceToMove = caseOfPiece->getPiece();
	//caseToGo->addPiece(pieceToMove);
	//caseOfPiece->removePiece();

	if (caseOfPiece->getPiece()->checkIfValidMove(caseToGo)) {
		std::shared_ptr<Piece> pieceToMove = caseOfPiece->getPiece();
		caseToGo->addPiece(pieceToMove);
		caseOfPiece->removePiece();

		// probablement trouver le moyen d'envoyer un signal ici pour dire que le board à changer.
	}

	else {
		// do nothing, probablement turn off des indicateurs visuels à faire ici. 
	}

}