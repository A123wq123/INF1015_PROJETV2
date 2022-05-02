#pragma once
#include <vector>
#include <memory>
#include "Echiquier.h"
#include "Square.h"

// Ce header sert à définir la classe qui est en charge de gèrer un mouvement de piece sur le board. 

class Move {
public:
	Move(std::shared_ptr<Square> startSquare) : startSquare_(startSquare) {}
	~Move() = default;

	std::vector<std::shared_ptr<Square>> checkPossibleMoves(std::unique_ptr<Echiquier>& echiquier);
	bool checkIfValidMove(std::unique_ptr<Echiquier>& echiquier);


	void setEndSquare(std::shared_ptr<Square> square) { endSquare_ = square; }
	const std::shared_ptr<Piece> getPiece() { return startSquare_->getPiece(); }

	void executeMove(std::unique_ptr<Echiquier>& echiquier); // méthode qui permet d'effectuer le mouvement une fois que les paramètres ont étés remplis. 

private:
	//std::vector<std::shared_ptr<Square>> vecteurSquareKingInCheck;
	std::shared_ptr<Square> startSquare_;
	std::shared_ptr<Square> endSquare_;
};