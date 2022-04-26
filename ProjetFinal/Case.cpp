#include "Case.h"
Case::Case(int posX, int posY, bool isWhite) : posX_(posX), posY_(posY), isWhite_(isWhite)
{
	piecePtr_ = std::make_shared<NullPiece>(NullPiece());
}

void Case::addPiece(std::shared_ptr<Piece> piecePtr) {
	removePiece();
	piecePtr_ = piecePtr;
}

void Case::removePiece() {
	piecePtr_ = std::make_shared<NullPiece>(NullPiece());
}