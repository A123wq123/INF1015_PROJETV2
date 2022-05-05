#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Piece.h"
#include "Square.h"
#include "Echiquier.h"

// Fichier ou sera défini la classe Roi

class Roi : public Piece {
public:
	Roi(Square* square, std::string color);
	~Roi() override = default;
	std::vector<std::shared_ptr<Square>> checkPossibleMoves(std::unique_ptr<Echiquier>& echiquier) override;
	bool checkIfValidMove(std::shared_ptr<Square> squareToGo, std::unique_ptr<Echiquier>& echiquier) override;
	const Square* getSquare() { return square_; }
	const std::vector<std::shared_ptr<Square>> returnVectorMovements(std::unique_ptr<Echiquier>& echiquier);
	
	// This method checks if a move is further than 2 squares away from king.
	bool checkIfMoveToFar(std::shared_ptr<Square> squareToGo, std::unique_ptr<Echiquier>& echiquier); 


	// cet attribut represente tout les mouvements vectoriels possible d'un roi.
	//static std::vector<std::pair<int, int>> vectorMovementVectoriels_;
};