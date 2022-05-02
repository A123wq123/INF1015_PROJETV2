#ifndef SQUARE_H
#define SQUARE_H
#include "Square.h"
#endif

#ifndef NULLPIECE_H
#define NULLPIECE_H
#include "NullPiece.h"
#endif

Square::Square(int row, int colloumn, bool isWhite) : row_(row), colloumn_(colloumn), isWhite_(isWhite)
{
	std::shared_ptr<Square> square = std::make_shared<Square>(this);
	piecePtr_ = std::make_shared<NullPiece>(NullPiece(square));
}

bool Square::isOccupied() {
	//std::shared_ptr<NullPiece> nullPieceptr = std::dynamic_pointer_cast<NullPiece>(piecePtr_);
	NullPiece* nullPiecePtr = dynamic_cast<NullPiece*>(piecePtr_.get());
	if (nullPiecePtr == nullptr) {
		return true;
	}
	return false;
}

void Square::addPiece(std::shared_ptr<Piece> piecePtr) {
	removePiece();
	piecePtr_ = piecePtr;
}

void Square::removePiece() {
	std::shared_ptr<Square> square = std::make_shared<Square>(this);
	piecePtr_ = std::make_shared<NullPiece>(NullPiece(square));
}