#ifndef PIECE_H
#define PIECE_H
#include <vector>
#include <memory>
#include <string>
#include "Square.h"
#include "Echiquier.h"

class Echiquier;
class Square;
class Piece
{
public:
	Piece(Square* square, std::string color, std::string name) : square_(square), color_(color), name_(name) {}
	virtual ~Piece() = default;
	//virtual void movePiece(std::shared_ptr<Case> squareTogo);          // Pas sur qu'on vas garder ca.
	virtual std::vector<std::shared_ptr<Square>> checkPossibleMoves(std::unique_ptr<Echiquier>& echiquier) = 0;
	virtual bool checkIfValidMove(std::shared_ptr<Square> squareToGo, std::unique_ptr<Echiquier>& echiquier) = 0;
	// Hesite a passer a une classe move pour permettre la sauvegarde des positions. 

	virtual void setCase(Square* squarePtr) {
		square_ = squarePtr;
	};

	virtual const std::string getColor() { return color_; };
	virtual const std::string getName() { return name_; };

	// dependament de comment le code évolue il serait interessant de rajouter une methode virtuelle pure move(). 

protected:

	int row();
	int collumn();

	Square* square_;
	std::string color_;
	std::string name_;
};

#endif