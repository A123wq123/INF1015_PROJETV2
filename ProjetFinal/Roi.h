#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Piece.h"
#include "Square.h"
#include "Echiquier.h"

// Fichier ou sera défini la classe Roi

class Roi : Piece {
public:
	Roi(std::shared_ptr<Square>& square, std::string color);
	~Roi() override = default;

	std::vector<std::shared_ptr<Square>> checkPossibleMoves(std::unique_ptr<Echiquier>& echiquier) override;
	bool checkIfValidMove(std::shared_ptr<Square> squareToGo, std::unique_ptr<Echiquier>& echiquier) override;

	void setCase(std::shared_ptr<Square> squarePtr) override { square_ = squarePtr; }
	const std::string getColor() override { return color_;  }
	const std::shared_ptr<Square> getSquare() { return square_; }

	const std::vector<std::pair<int, int>> returnVectorMovementVectoriels() ;
	const std::string getName() override { return name_; }

private:
	std::shared_ptr<Square> square_;
	int row_;
	int collumn_;
	std::string color_;
	std::string name_;

	// cet attribut represente tout les mouvements vectoriels possible d'un roi.
	//static std::vector<std::pair<int, int>> vectorMovementVectoriels_;
};