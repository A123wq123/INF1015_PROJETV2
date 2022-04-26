#include "Echiquier.h"
#include "Piece.h"
#include <utility>


class Case {
public:
	Case(int posX, int posy, bool isWhite);
	~Case() = default;

	const std::shared_ptr<Piece> getPiece() { return piecePtr_; }
	bool isCaseWhite() { return isWhite_; }

	std::pair<const int, const int> getCoordinates() { return std::make_pair(posX_, posY_); }

	void addPiece(std::shared_ptr<Piece> piecePtr);
	void removePiece();

private:
	bool isWhite_;
	int posX_;
	int posY_;
	std::shared_ptr<Piece> piecePtr_;
};