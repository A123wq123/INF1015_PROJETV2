#include "Echiquier.h"


Echiquier::Echiquier() : vectorSquare_() {
	bool isWhite = false;
	for (int row = 0; row < getNumberOfRows(); row++) {
		!isWhite;           // Alterne le noir blanc à chaque ligne.
		for (int collumn = 0; collumn < getNumberOfCollumns(); collumn++) {
			vectorSquare_[row][collumn] = std::make_shared<Square>(Square(row, collumn, isWhite));
			!isWhite;       // alterne le noir blanc à chaque colonne. 
		}
	}
}

void Echiquier::addPiece(std::shared_ptr<Piece> piece, int row, int collumn) {
	getVectorSquare()[row][collumn]->addPiece(piece);
}


// La méthode move piece est sujette a disparaître car on vas passer par la création d'un objet
// move qui lui se charge de gèrer le move. 

void Echiquier::movePiece(std::shared_ptr<Square> squareOfPiece, std::shared_ptr<Square> squareToGo) {
	//std::shared_ptr<Piece> pieceToMove = caseOfPiece->getPiece();
	//caseToGo->addPiece(pieceToMove);
	//caseOfPiece->removePiece();

	if (squareOfPiece->getPiece()->checkIfValidMove(squareToGo)) {
		std::shared_ptr<Piece> pieceToMove = squareOfPiece->getPiece();
		squareToGo->addPiece(pieceToMove);
		squareOfPiece->removePiece();

		// probablement trouver le moyen d'envoyer un signal ici pour dire que le board à changer.
	}

	else {
		// do nothing, probablement turn off des indicateurs visuels à faire ici. 
	}

}