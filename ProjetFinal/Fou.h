#pragma once
#include "Piece.h"

// Fichier ou sera défini la classe Fou
class Fou : public Piece {
public:
	Fou(Square* square, std::string color);
	~Fou() override = default;
	/*std::shared_ptr<Piece> copy(const std::shared_ptr<Piece> piece) override;
	Fou(const Fou& fou);*/
	std::vector<Square*> checkPossibleMoves(Echiquier* const echiquier, bool ennableCheckIfKing) override;
	bool checkIfValidMove(Square* caseToGo, Echiquier* const echiquier, bool ennableCheckIfKing) override;
	bool checkIfMoveDIagonal(Square* caseToGo, Echiquier* const echiquier);
};