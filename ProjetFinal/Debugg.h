#pragma once
#include <stdexcept>
#include <iostream>
#include "ChessGame.h"
#include "Move.h"

// File in wich we create the different errors and methods necessary to debug. 

// Error associated with to many kings created
class InvalidCreationOfKing : public std::logic_error {
public:
	using logic_error::logic_error;
};

// Error associated with square not found. 
class SquareNotFound : public std::runtime_error {
public:
	using runtime_error::runtime_error;
};

// Error associated with piece not found
class PieceNotFound : public std::runtime_error {
public:
	using runtime_error::runtime_error;
};

// Error associated with king not found.
class KingNotFound : PieceNotFound {
public:
	//using PieceNotFound::runtime_error;
};

// Class associated with debugging the state of a board (print it in console).

class Debugg {
public:
	Debugg(Chess::ChessGame chessGame) : chessGame_(chessGame) {}
	~Debugg() = default;
	void printBoardState(std::string nameOftest);
	void lancerSerieTests();
private:
	Chess::ChessGame chessGame_; // Might be no need for a pointer here.
};