#include "Echiquier.h"
#include "Piece.h"


class Case {
public:
	Case(int posX, int posy, bool isWhite);
	~Case() = default;

	const std::shared_ptr<Piece> getPiece() { return piecePtr_; }

	void addPiece(std::shared_ptr<Piece> piecePtr);
	void removePiece();
private:
	bool isWhite_;
	int posX_;
	int posY_;
	std::shared_ptr<Piece> piecePtr_;
};