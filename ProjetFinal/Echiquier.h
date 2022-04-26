#pragma once
#pragma once
#include <Vector>
#include <memory>
#include "Case.h"
#include "NullPiece.h"
class Echiquier
{
public:
	Echiquier();
	~Echiquier() = default;
	void addPiece(std::shared_ptr<Piece> piece, int row, int collumn);
	void movePiece(std::shared_ptr<Case> caseSelected, std::shared_ptr<Case> caseToGo);

	std::vector<std::vector<std::shared_ptr<Case>>> getVectorCase() const {
		return vectorCase_;
	}

	const int getNumberOfRows() { numberOfRows_ = 8; return numberOfRows_; }
	const int getNumberOfCollumns() { numberOfCollumns_ = 8; return numberOfCollumns_; }

	// faire une fonction getcase AVEC row et collonne valeur de retour case*
	// might have to define des opperateur begin et end pour permettre l'ittération facile. 
private:
	std::vector<std::vector<std::shared_ptr<Case>>>  vectorCase_;
	static int numberOfRows_;
	static int numberOfCollumns_;
};
