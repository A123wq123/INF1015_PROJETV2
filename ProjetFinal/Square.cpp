#include "Square.h"
#include "NullPiece.h"

Square::Square(int row, int colloumn, bool isWhite) : row_(row), colloumn_(colloumn), isWhite_(isWhite)
{
	std::shared_ptr<Square> square = std::make_shared<Square>(this);
	piecePtr_ = std::make_shared<NullPiece>(NullPiece(square));
}

void Square::addPiece(std::shared_ptr<Piece> piecePtr) {
	removePiece();
	piecePtr_ = piecePtr;
}

void Square::removePiece() {
	std::shared_ptr<Square> square = std::make_shared<Square>(this);
	piecePtr_ = std::make_shared<NullPiece>(NullPiece(square));
}