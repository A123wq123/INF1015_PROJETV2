#pragma once
#include "Piece.h"

// Fichier ou sera défini la classe Fou
class Fou : Piece {
public:
	Fou(Square* square, std::string color);
	~Fou() override = default;
	std::vector<std::shared_ptr<Square>> checkPossibleMoves(std::unique_ptr<Echiquier>&echiquier) override;
	bool checkIfValidMove(std::shared_ptr<Square> caseToGo, std::unique_ptr<Echiquier>&echiquier) override;
	bool checkIfMoveDIagonal(std::shared_ptr<Square> caseToGo, std::unique_ptr<Echiquier>& echiquier);
};