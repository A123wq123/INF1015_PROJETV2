#ifndef PIECE_H
#define PIECE_H
#include <vector>
#include <memory>
#include <string>
#include "Square.h"
#include "Echiquier.h"

class Echiquier;

class Piece
{
public:

	virtual ~Piece() = default;
	//virtual void movePiece(std::shared_ptr<Case> squareTogo);          // Pas sur qu'on vas garder ca.
	virtual std::vector<std::shared_ptr<Square>> checkPossibleMoves(std::unique_ptr<Echiquier>& echiquier) = 0;
	virtual bool checkIfValidMove(std::shared_ptr<Square> squareToGo, std::unique_ptr<Echiquier>& echiquier) = 0;
	// Hesite a passer a une classe move pour permettre la sauvegarde des positions. 

	virtual void setCase(std::shared_ptr<Square> squarePtr) = 0;

	virtual const std::string getColor() = 0;

	// dependament de comment le code évolue il serait interessant de rajouter une methode virtuelle pure move(). 

private:
	//std::vector<std::shared_ptr<Square>> vectorPossibleMoves_;
	/*std::shared_ptr<Square> square_;
	int row_;
	int collomn_;
	std::string color_;*/
};

#endif