#pragma once
#include "Piece.h"

// Fichier ou sera défini la classe Fou
class Fou : Piece {
public:
	Fou(std::shared_ptr<Square>& square, std::string color);
	~Fou() = default;
	std::vector<std::shared_ptr<Square>> checkPossibleMoves(std::unique_ptr<Echiquier>&echiquier) override;
	bool checkIfValidMove(std::shared_ptr<Square> caseToGo, std::unique_ptr<Echiquier>&echiquier) override;

	void setCase(std::shared_ptr<Square> squarePtr) override { square_ = squarePtr; };
	const std::string getColor() override { return color_; };
	const std::string getName() { return name_; }

private:
	std::shared_ptr<Square> square_;
	int row_;
	int collomn_;
	std::string color_;
	std::string name_;
};