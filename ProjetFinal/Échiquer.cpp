#include "Roi.h"
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

std::shared_ptr<Square> Echiquier::findSquareKing(std::string color) {
	for (int row = 0; row < getNumberOfRows(); row++) {
		for (int collumn = 0; collumn < getNumberOfCollumns(); collumn++) {
			std::shared_ptr<Roi> roiPtr = std::dynamic_pointer_cast<Roi>(vectorSquare_[row][collumn]->getPiece());
			if (roiPtr != nullptr) {
				if (roiPtr->getColor() == color) {
					return vectorSquare_[row][collumn];
				}
			}
		}
	}
	return nullptr;
}

std::set<std::shared_ptr<Square>> Echiquier::getSetSquaresAttacked(std::string colorOfPieces) {
	std::set<std::shared_ptr<Square>> setOfSquaresAttacked;
	// itere sur toutes les cases
	for (int row = 0; row < getNumberOfRows(); row++) {
		for (int collumn = 0; collumn < getNumberOfCollumns(); collumn++) {
			auto& piece = vectorSquare_[row][collumn]->getPiece();
			// determine si la piece est de la bonne couleur. 
			if (piece->getColor() == colorOfPieces) {
				std::unique_ptr<Echiquier> echiquier = std::unique_ptr<Echiquier>(this);
				std::vector<std::shared_ptr<Square>> vectorOfPossibleMoves = piece->checkPossibleMoves(echiquier);
				// ajoute les mouvements au set (evite les duplicats).
				for (auto&& squarePtr : vectorOfPossibleMoves) {
					setOfSquaresAttacked.insert(squarePtr);
				}
			}
		}
	}
	return setOfSquaresAttacked;
}

bool Echiquier::isKingInCheck(std::string colorOfKing) {
	// obtenir la couleur des pieces enemies. 
	std::shared_ptr<Square> squareKingPtr = this->findSquareKing(colorOfKing);
	std::string colorOfEnemies;
	colorOfKing == "white" ? colorOfEnemies = "black" : colorOfEnemies = "white";
	std::set<std::shared_ptr<Square>> setOfSquaresAttacked = this->getSetSquaresAttacked(colorOfEnemies);
	for (auto&& squarePtr : setOfSquaresAttacked) {
		if (squarePtr == squareKingPtr) {
			return true;
		}
	}
	return false;
}

bool Echiquier::isKingInCheckAfterMove(std::string colorOfKing, std::shared_ptr<Square> currentPos, std::shared_ptr<Square> dest) {
	std::shared_ptr<Piece> currentPosPiece = currentPos->getPiece();
	std::shared_ptr<Piece> destPiece = dest->getPiece();
	dest->addPiece(currentPos->getPiece());
	currentPos->removePiece();
	if (this->isKingInCheck(colorOfKing)) {
		currentPos->addPiece(currentPosPiece);
		dest->addPiece(destPiece);
		return true;
	}
	else {
		currentPos->addPiece(currentPosPiece);
		dest->addPiece(destPiece);
		return false;
	}
}

// La méthode move piece est sujette a disparaître car on vas passer par la création d'un objet
// move qui lui se charge de gèrer le move. 

//void Echiquier::movePiece(std::shared_ptr<Square> squareOfPiece, std::shared_ptr<Square> squareToGo) {
//	//std::shared_ptr<Piece> pieceToMove = caseOfPiece->getPiece();
//	//caseToGo->addPiece(pieceToMove);
//	//caseOfPiece->removePiece();
//
//	if (squareOfPiece->getPiece()->checkIfValidMove(squareToGo)) {
//		std::shared_ptr<Piece> pieceToMove = squareOfPiece->getPiece();
//		squareToGo->addPiece(pieceToMove);
//		squareOfPiece->removePiece();
//
//		// probablement trouver le moyen d'envoyer un signal ici pour dire que le board à changer.
//	}
//
//	else {
//		// do nothing, probablement turn off des indicateurs visuels à faire ici. 
//	}
//
//}