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
	~Roi() = default;

	virtual std::vector<std::shared_ptr<Square>> checkPossibleMoves(std::unique_ptr<Echiquier>& echiquier);
	virtual bool checkIfValidMove(std::shared_ptr<Square> squareToGo, std::unique_ptr<Echiquier>& echiquier);

	virtual void setCase(std::shared_ptr<Square> squarePtr) { square_ = squarePtr; }
	virtual const std::string getColor() { return color_;  }
private:
	std::shared_ptr<Square> square_;
	int row_;
	int collumn_;
	std::string color_;

	// cet attribut represente tout les mouvements vectoriels possible d'un roi.
	static std::vector<std::pair<int, int>> vectorMovementVectoriels_;
};