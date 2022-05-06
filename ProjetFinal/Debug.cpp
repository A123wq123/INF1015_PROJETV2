#pragma once
#include "Debugg.h"
#include "Roi.h"
#include "Tour.h"
#include "Fou.h"

//std::unique_ptr<Echiquier> createBasicEchiquier() {
//	// make an empty board
//	std::unique_ptr<Echiquier> echiquier = std::make_unique<Echiquier>();
//
//	// add the white peices.
//	echiquier->getCase(7, 4)->addPiece(std::make_shared<Roi>(echiquier->getCase(7, 4), "White"));
//	echiquier->getCase(7, 7)->addPiece(std::make_shared<Tour>(echiquier->getCase(7, 7), "White"));
//	echiquier->getCase(7, 0)->addPiece(std::make_shared<Tour>(echiquier->getCase(7, 0), "White"));
//	echiquier->getCase(7, 2)->addPiece(std::make_shared<Fou>(echiquier->getCase(7, 2), "White"));
//	echiquier->getCase(7, 5)->addPiece(std::make_shared<Fou>(echiquier->getCase(7, 5), "White"));
//
//	// add the black peices.
//	echiquier->getCase(0, 4)->addPiece(std::make_shared<Roi>(echiquier->getCase(0, 4), "Black"));
//	echiquier->getCase(0, 7)->addPiece(std::make_shared<Tour>(echiquier->getCase(0, 7), "Black"));
//	echiquier->getCase(0, 0)->addPiece(std::make_shared<Tour>(echiquier->getCase(0, 0), "Black"));
//	echiquier->getCase(0, 2)->addPiece(std::make_shared<Fou>(echiquier->getCase(0, 2), "Black"));
//	echiquier->getCase(0, 5)->addPiece(std::make_shared<Fou>(echiquier->getCase(0, 5), "Black"));
//
//	return std::move(echiquier);
//}

void Debugg::printBoardState(std::string nameOftest) {
	auto&& echiquier = chessGame_.getEchiquier();
	// Iterate on all possible squares. 
	std::cout << nameOftest << std::endl;
	for (int row = 0; row < echiquier->getNumberOfRows(); row++) {
		for (int collumn = 0; collumn < echiquier->getNumberOfCollumns(); collumn++) {
			// The null piece doesn't have a name to not interfere with regualr UI
			// We then have to give it a fictiionnal one here for debugg.
			if (echiquier->getCase(row, collumn)->getPiece()->getName() == "") {
				std::cout << "           " << "|";
			}

			else if (echiquier->getCase(row, collumn)->getPiece()->getName().length() == 8) {
				std::cout << " " << echiquier->getCase(row, collumn)->getPiece()->getName() << "  |";
			}

			else {
				std::cout << " " << echiquier->getCase(row, collumn)->getPiece()->getName() << " |";
			}
		}
		std::cout << std::endl;
		std::cout << "--------------------------------------------------------------------------------------"
			"----------" << std::endl;
	}
	std::cout << "///////////////////////////////////////////////////////////////////////////////////////"
		"/////////" << std::endl;
}

void Debugg::lancerSerieTests() {

	//this->printBoardState("test #0");

	//// test #1, make an move that selects no pieces.
	//{
	//	std::cout << "Test #1" << std::endl;
	//	std::unique_ptr<Move> movePtr =  this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(2, 2));
	//	if (movePtr == nullptr) {
	//		std::cout << "Move was illegal" << std::endl;
	//	}
	//	else {
	//		movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(3, 2));
	//		movePtr->executeMove(chessGame_.getEchiquier());
	//	}
	//	std::cout << "Test passed" << std::endl;
	//	std::cout << std::endl;
	//}

	//// test #2, try to kill own piece Tour. 
	//{
	//	std::cout << "Test #2" << std::endl;
	//	std::unique_ptr<Move> movePtr = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(7, 0));
	//	if (movePtr == nullptr) {
	//		std::cout << "Move was illegal" << std::endl;
	//	}
	//	else {
	//		movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(7, 2));
	//		movePtr->executeMove(chessGame_.getEchiquier());
	//	}
	//	std::cout << "Test passed" << std::endl;
	//	std::cout << std::endl;
	//}
	//
	//// test #3, try to kill own piece Fou. 
	//{
	//	// Move #1
	//	std::cout << "Test #3" << std::endl;
	//	std::unique_ptr<Move> movePtr = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(7, 2));
	//	if (movePtr == nullptr) {
	//		std::cout << "Move was illegal" << std::endl;
	//	}
	//	else {
	//		movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(6, 1));
	//		movePtr->executeMove(chessGame_.getEchiquier());
	//		this->chessGame_.determineNextStates();
	//	}

	//	// move #2
	//	std::unique_ptr<Move> movePtr2 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(0, 0));
	//	if (movePtr == nullptr) {
	//		std::cout << "Move was illegal" << std::endl;
	//	}
	//	else {
	//		movePtr2->setEndSquare(chessGame_.getEchiquier()->getCase(1, 0));
	//		movePtr2->executeMove(chessGame_.getEchiquier());
	//		this->chessGame_.determineNextStates();
	//	}

	//	// move #3
	//	std::unique_ptr<Move> movePtr3 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(6, 1));
	//	if (movePtr == nullptr) {
	//		std::cout << "Move was illegal" << std::endl;
	//	}
	//	else {
	//		movePtr3->setEndSquare(chessGame_.getEchiquier()->getCase(7, 0));
	//		movePtr3->executeMove(chessGame_.getEchiquier());
	//		this->chessGame_.determineNextStates();
	//	}
	//	std::cout << "Test passed" << std::endl;
	//	std::cout << std::endl;
	//	this->resetBoard();
	//}

	//// Test #4, kill own piece King.
	//{
	//	std::cout << "Test #4" << std::endl;
	//	std::unique_ptr<Move> movePtr = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(7, 4));
	//	if (movePtr == nullptr) {
	//		std::cout << "Move was illegal" << std::endl;
	//	}
	//	else {
	//		movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(7, 5));
	//		movePtr->executeMove(chessGame_.getEchiquier());
	//		
	//	}
	//	std::cout << "Test passed" << std::endl;
	//	std::cout << std::endl;
	//	this->resetBoard();
	//}

	// Test #5.1, tower tries to go out of bounds
	{
		try {
			std::cout << "Test #5.1" << std::endl;
			std::unique_ptr<Move> movePtr = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(7, 0));
			if (movePtr == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(7, -1));
				movePtr->executeMove(chessGame_.getEchiquier());
			}
			std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
			this->resetBoard();
		}
		catch (SquareNotFound& e){
			std::cout << "The move tries to go outside the board and so it has been terminated" << std::endl;
			std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
			this->resetBoard();
		}
	}

	// Test #5.2, tower tries to go out of bounds
	{
		this->printBoardState("test debugg");
		try {
			std::cout << "Test #5.2" << std::endl;
			std::unique_ptr<Move> movePtr = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(7, 0));
			if (movePtr == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(8, 0));
				movePtr->executeMove(chessGame_.getEchiquier());
			}
			std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
			this->resetBoard();
		}
		catch (SquareNotFound& e) {
			std::cout << "The move tries to go outside the board and so it has been terminated" << std::endl;
			std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
			this->resetBoard();
		}
	}

	//// Test #5.3, tower tries to go out of bounds
	//{
	//	// move #1
	//	std::cout << "Test #5.3" << std::endl;
	//	std::unique_ptr<Move> movePtr = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(0, 0));
	//	if (movePtr == nullptr) {
	//		std::cout << "Move was illegal" << std::endl;
	//	}
	//	else {
	//		movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(3, 0));
	//		movePtr->executeMove(chessGame_.getEchiquier());

	//	}

	//	// move #2
	//	std::unique_ptr<Move> movePtr2 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(7, 0));
	//	if (movePtr2 == nullptr) {
	//		std::cout << "Move was illegal" << std::endl;
	//	}
	//	else {
	//		movePtr2->setEndSquare(chessGame_.getEchiquier()->getCase(6, 0));
	//		movePtr2->executeMove(chessGame_.getEchiquier());
	//	}

	//	// move #3
	//	std::unique_ptr<Move> movePtr3 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(3, 0));
	//	if (movePtr3 == nullptr) {
	//		std::cout << "Move was illegal" << std::endl;
	//	}
	//	else {
	//		movePtr3->setEndSquare(chessGame_.getEchiquier()->getCase(3, 1));
	//		movePtr3->executeMove(chessGame_.getEchiquier());
	//	}

	//	// move #4
	//	std::unique_ptr<Move> movePtr4 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(6, 0));
	//	if (movePtr4 == nullptr) {
	//		std::cout << "Move was illegal" << std::endl;
	//	}
	//	else {
	//		movePtr4->setEndSquare(chessGame_.getEchiquier()->getCase(5, 0));
	//		movePtr4->executeMove(chessGame_.getEchiquier());
	//	}


	//	// move #5
	//	std::unique_ptr<Move> movePtr5 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(3, 1));
	//	if (movePtr == nullptr) {
	//		std::cout << "Move was illegal" << std::endl;
	//	}
	//	else {
	//		movePtr5->setEndSquare(chessGame_.getEchiquier()->getCase(8, 1));
	//		movePtr5->executeMove(chessGame_.getEchiquier());
	//	}

	//	std::cout << "Test passed" << std::endl;
	//	std::cout << std::endl;
	//	this->resetBoard();
	//}

	//// Test #6.1, bishop tries to go out of bounds
	//{
	//	std::cout << "Test #6.1" << std::endl;
	//	std::unique_ptr<Move> movePtr = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(0, 2));
	//	if (movePtr == nullptr) {
	//		std::cout << "Move was illegal" << std::endl;
	//	}
	//	else {
	//		movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(-1, 1));
	//		movePtr->executeMove(chessGame_.getEchiquier());

	//	}
	//	std::cout << "Test passed" << std::endl;
	//	std::cout << std::endl;
	//	this->resetBoard();
	//}
}

void Debugg::resetBoard() {
	Echiquier* echiquier = this->chessGame_.getEchiquier();
	// iterate on all squares;
	for (int row = 0; row < echiquier->getNumberOfRows(); row++) {
		for (int collumn = 0; collumn < echiquier->getNumberOfCollumns(); collumn++) {
			echiquier->getCase(row, collumn)->removePiece();
		}
	}

	// add the white peices.
	echiquier->getCase(7, 4)->addPiece(std::make_shared<Roi>(echiquier->getCase(7, 4), "white"));
	echiquier->getCase(7, 7)->addPiece(std::make_shared<Tour>(echiquier->getCase(7, 7), "white"));
	echiquier->getCase(7, 0)->addPiece(std::make_shared<Tour>(echiquier->getCase(7, 0), "white"));
	echiquier->getCase(7, 2)->addPiece(std::make_shared<Fou>(echiquier->getCase(7, 2), "white"));
	echiquier->getCase(7, 5)->addPiece(std::make_shared<Fou>(echiquier->getCase(7, 5), "white"));

	// add the black peices.
	echiquier->getCase(0, 4)->addPiece(std::make_shared<Roi>(echiquier->getCase(0, 4), "black"));
	echiquier->getCase(0, 7)->addPiece(std::make_shared<Tour>(echiquier->getCase(0, 7), "black"));
	echiquier->getCase(0, 0)->addPiece(std::make_shared<Tour>(echiquier->getCase(0, 0), "black"));
	echiquier->getCase(0, 2)->addPiece(std::make_shared<Fou>(echiquier->getCase(0, 2), "black"));
	echiquier->getCase(0, 5)->addPiece(std::make_shared<Fou>(echiquier->getCase(0, 5), "black"));

	this->chessGame_.setPlayerTurn(Chess::PlayerTurn::White);
	this->chessGame_.setGameState(Chess::GameState::Normal);
}