#pragma once
#pragma once
#include <Vector>
#include <memory>
#include "Case.h"
#include "Piece.h"
class Echiquier
{
public:
	Echiquier();
	~Echiquier();
	void addPiece(ABSPiece& piece, int row, int collumn);
	std::vector<std::vector<std::unique_ptr<Case>>> getVectorCase() const {
		return vectorCase_;
	}

	// faire une fonction getcase AVEC row et collonne valeur de retour case*
private:
	std::vector<std::vector<std::unique_ptr<Case>>>  vectorCase_;
};
