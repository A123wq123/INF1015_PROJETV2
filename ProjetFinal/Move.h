#pragma once
#include <vector>
#include <memory>
#include "Echiquier.h"
#include "Square.h"
#include <iostream>

// Ce header sert à définir la classe qui est en charge de gèrer un mouvement de piece sur le board. 

class Move {
public:
	Move(Square* startSquare) : startSquare_(startSquare) {}
	~Move() = default;

	std::vector<Square*> checkPossibleMoves(Echiquier* const echiquier);
	bool checkIfValidMove(Echiquier* const echiquier);


	void setEndSquare(Square* square) { endSquare_ = square; }
	const std::shared_ptr<Piece> getPiece() { return startSquare_->getPiece(); }

	void executeMove(Echiquier* const echiquier); 

private:
	//std::vector<std::shared_ptr<Square>> vecteurSquareKingInCheck;
	Square* startSquare_;
	Square* endSquare_;
};