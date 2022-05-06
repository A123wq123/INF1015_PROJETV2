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
	//Roi(const Roi& roi);
	std::vector<Square*> checkPossibleMoves(Echiquier* const echiquier, bool ennableCheckIfKing) override;
	bool checkIfValidMove(Square* squareToGo, Echiquier* const echiquier, bool ennableCheckIfKing) override;
	const Square* getSquare() { return square_; }
	std::vector<Square*> returnVectorMovements(Echiquier* const echiquier);
	
	// This method checks if a move is further than 2 squares away from king.
	bool checkIfMoveToFar(Square* squareToGo, Echiquier* const echiquier); 


	// cet attribut represente tout les mouvements vectoriels possible d'un roi.
	//static std::vector<std::pair<int, int>> vectorMovementVectoriels_;
};