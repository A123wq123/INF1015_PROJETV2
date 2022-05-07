#include "Roi.h"
#include "NullPiece.h"
#include "Echiquier.h"
#include "Debugg.h"

Echiquier::Echiquier() : vectorSquare_() {
	bool isWhite = false;
	
	for (int row = 0; row < getNumberOfRows(); row++) {
		vectorSquare_.emplace_back(std::vector<std::unique_ptr<Square>>());
		isWhite  = !isWhite;           // Alterne le noir blanc à chaque ligne.
		for (int collumn = 0; collumn < getNumberOfCollumns(); collumn++) {
			vectorSquare_[row].emplace_back(std::make_unique<Square>(row, collumn, isWhite));
			isWhite = !isWhite;       // alterne le noir blanc à chaque colonne. 
		}
	}
}

void Echiquier::addPiece(std::shared_ptr<Piece> piece, int row, int collumn) {
	this->getCase(row, collumn)->addPiece(piece);
}

Square* Echiquier::findSquareKing(std::string color) {
	for (int row = 0; row < getNumberOfRows(); row++) {
		for (int collumn = 0; collumn < getNumberOfCollumns(); collumn++) {
			std::shared_ptr<Roi> roiPtr = std::dynamic_pointer_cast<Roi>(vectorSquare_[row][collumn]->getPiece());
			if (roiPtr != nullptr) {
				if (roiPtr->getColor() == color) {
					return vectorSquare_[row][collumn].get();
				}
			}
		}
	}
	return nullptr;
}

Square* Echiquier::getCase(int row, int collumn) { 
	if ((0 <= row) && (row <= 7)) {
		if ((0 <= collumn) && (collumn <= 7)) {
			return vectorSquare_[row][collumn].get();
		}
	}
	throw SquareNotFound("Could not find the square as the parameters are incorect");
}

std::set<Square*> Echiquier::getSetSquaresAttacked(std::string colorOfPieces) {
	std::set<Square*> setOfSquaresAttacked;
	// itere sur toutes les cases
	for (int row = 0; row < getNumberOfRows(); row++) {
		for (int collumn = 0; collumn < getNumberOfCollumns(); collumn++) {
			auto& piece = vectorSquare_[row][collumn]->getPiece();
			// determine si la piece est de la bonne couleur. 
			if (piece->getColor() == colorOfPieces) {
				std::vector<Square*> vectorOfPossibleMoves = piece->checkPossibleMoves(this, false);
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
	Square* squareKingPtr = this->findSquareKing(colorOfKing);
	std::string colorOfEnemies;
	colorOfKing == "White" ? colorOfEnemies = "Black" : colorOfEnemies = "White";
	std::set<Square*> setOfSquaresAttacked = this->getSetSquaresAttacked(colorOfEnemies);
	for (auto&& squarePtr : setOfSquaresAttacked) {
		if (squarePtr == squareKingPtr) {
			return true;
		}
	}
	return false;
}

bool Echiquier::isKingInCheckAfterMove(std::string colorOfKing, Square* currentPos, Square* dest) {
	// sauvegarder les positions originales. 
	std::shared_ptr<Piece> currentPosPiece = currentPos->getPiece();
	std::shared_ptr<Piece> destPiece = dest->getPiece();
	// effectuer le mouvement.
	dest->addPiece(currentPos->getPiece());
	dest->getPiece()->setCase(dest);
	currentPos->removePiece();

	
	// Tester si le roi est en echec. 
	if (this->isKingInCheck(colorOfKing)) {
		// annuler le mouvement. 
		currentPos->addPiece(currentPosPiece);
		currentPos->getPiece()->setCase(currentPos);
		dest->addPiece(destPiece);
		return true;
	}
	else {
		// annuler le mouvement. 
		currentPos->addPiece(currentPosPiece);
		currentPos->getPiece()->setCase(currentPos);
		dest->addPiece(destPiece);
		return false;
	}
}

bool Echiquier::isKingInCheckMate(std::string colorOfKing) {
	// checks if king is even in check. 
	if (false == this->isKingInCheck(colorOfKing)) {
		return false;
	}

	// Altho the name of this method may be confusing, it gives us all the moves the pieces of a color can do.
	if (this->getSetSquaresAttacked(colorOfKing).empty()) {
		return true;
	}
	return false;
}