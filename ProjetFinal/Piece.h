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
	//virtual std::shared_ptr<Piece> copy(const std::shared_ptr<Piece> piece) = 0;
	//virtual void movePiece(std::shared_ptr<Case> squareTogo);          // Pas sur qu'on vas garder ca.
	virtual std::vector<Square*> checkPossibleMoves(Echiquier* const echiquier, bool ennableCheckIfKing) = 0;
	virtual bool checkIfValidMove(Square* squareToGo, Echiquier* const echiquier, bool ennableCheckIfKing) = 0;
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