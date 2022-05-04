#include "Square.h"
#include "NullPiece.h"

Square::Square(int row, int colloumn, bool isWhite) : row_(row), colloumn_(colloumn), isWhite_(isWhite)
{
	
	piecePtr_ = std::make_shared<NullPiece>(NullPiece(this));
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
	/*removePiece();*/
	piecePtr_ = piecePtr;
}

void Square::removePiece() {
	
	piecePtr_ = std::make_shared<NullPiece>(NullPiece(this));
}