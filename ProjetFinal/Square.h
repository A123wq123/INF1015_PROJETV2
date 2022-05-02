#ifndef PIECE_H
#define PIECE_H
#include "Piece.h"
#endif

#ifndef MEMORY_H
#define MEMORY_H
#include <memory>
#endif

#ifndef UTILITY_H
#define UTILITY_H
#include <utility>
#endif



//#pragma once
//#include "Echiquier.h"
//#include "Piece.h"
//#include <utility>
//#include <memory>
//#pragma once

class Square {
public:
	Square(int row, int colloumn, bool isWhite);
	~Square() = default;

	const std::shared_ptr<Piece> getPiece() { return piecePtr_; }
	bool isOccupied();
	bool isCaseWhite() { return isWhite_; }


	// could be useless but idk yet
	std::pair<const int, const int> getCoordinates() { return std::make_pair(row_, colloumn_); }

	void addPiece(std::shared_ptr<Piece> piecePtr);
	void removePiece();

private:
	bool isWhite_;
	int row_;
	int colloumn_;
	std::shared_ptr<Piece> piecePtr_;
};