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

	// test #1, make an move that selects no pieces.
	{
		std::cout << "Test #1" << std::endl;
		std::unique_ptr<Move> movePtr =  this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(2, 2));
		if (movePtr == nullptr) {
			std::cout << "Move was illegal" << std::endl;
		}
		else {
			movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(3, 2));
			movePtr->executeMove(chessGame_.getEchiquier());
		}
		std::cout << "Test passed" << std::endl;
		std::cout << std::endl;
	}

	// test #2, try to kill own piece Tour. 
	{
		std::cout << "Test #2" << std::endl;
		std::unique_ptr<Move> movePtr = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(7, 0));
		if (movePtr == nullptr) {
			std::cout << "Move was illegal" << std::endl;
		}
		else {
			movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(7, 2));
			movePtr->executeMove(chessGame_.getEchiquier());
		}
		std::cout << "Test passed" << std::endl;
		std::cout << std::endl;
	}
	
	// test #3, try to kill own piece Fou. 
	{
		// Move #1
		std::cout << "Test #3" << std::endl;
		std::unique_ptr<Move> movePtr = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(7, 2));
		if (movePtr == nullptr) {
			std::cout << "Move was illegal" << std::endl;
		}
		else {
			movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(6, 1));
			movePtr->executeMove(chessGame_.getEchiquier());
			this->chessGame_.determineNextStates();
		}

		// move #2
		std::unique_ptr<Move> movePtr2 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(0, 0));
		if (movePtr == nullptr) {
			std::cout << "Move was illegal" << std::endl;
		}
		else {
			movePtr2->setEndSquare(chessGame_.getEchiquier()->getCase(1, 0));
			movePtr2->executeMove(chessGame_.getEchiquier());
			this->chessGame_.determineNextStates();
		}

		// move #3
		std::unique_ptr<Move> movePtr3 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(6, 1));
		if (movePtr == nullptr) {
			std::cout << "Move was illegal" << std::endl;
		}
		else {
			movePtr3->setEndSquare(chessGame_.getEchiquier()->getCase(7, 0));
			movePtr3->executeMove(chessGame_.getEchiquier());
			this->chessGame_.determineNextStates();
		}
		std::cout << "Test passed" << std::endl;
		std::cout << std::endl;
		this->resetBoard();
	}

	// Test #4, kill own piece King.
	{
		std::cout << "Test #4" << std::endl;
		std::unique_ptr<Move> movePtr = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(7, 4));
		if (movePtr == nullptr) {
			std::cout << "Move was illegal" << std::endl;
		}
		else {
			movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(7, 5));
			movePtr->executeMove(chessGame_.getEchiquier());
			
		}
		std::cout << "Test passed" << std::endl;
		std::cout << std::endl;
		this->resetBoard();
	}

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
			std::cout << std::endl;
		}
		catch (SquareNotFound& e){
			std::cout << "The move tries to go outside the board and so it has been terminated" << std::endl;
			std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
		}
		this->resetBoard();
	}

	// Test #5.2, tower tries to go out of bounds
	{
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
			std::cout << std::endl;
		}
		catch (SquareNotFound& e) {
			std::cout << "The move tries to go outside the board and so it has been terminated" << std::endl;
			std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
		}
		this->resetBoard();
	}

	// Test #5.3, tower tries to go out of bounds
	{
		try {
			// move #1
			std::cout << "Test #5.3" << std::endl;
			std::unique_ptr<Move> movePtr = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(7, 0));
			if (movePtr == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(6, 0));
				movePtr->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			// move #2
			std::unique_ptr<Move> movePtr2 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(0, 0));
			if (movePtr2 == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr2->setEndSquare(chessGame_.getEchiquier()->getCase(1, 0));
				movePtr2->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			// move #3
			std::unique_ptr<Move> movePtr3 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(6, 0));
			if (movePtr3 == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr3->setEndSquare(chessGame_.getEchiquier()->getCase(6, 1));
				movePtr3->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			// move #4
			std::unique_ptr<Move> movePtr4 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(1, 0));
			if (movePtr4 == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr4->setEndSquare(chessGame_.getEchiquier()->getCase(2, 0));
				movePtr4->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}


			// move #5
			std::unique_ptr<Move> movePtr5 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(6, 1));
			if (movePtr == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr5->setEndSquare(chessGame_.getEchiquier()->getCase(8, 1));
				movePtr5->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}
			std::cout << std::endl;
		}
		catch (SquareNotFound& e) {
			std::cout << "The move tries to go outside the board and so it has been terminated" << std::endl;
			std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
		}
		this->resetBoard();
	}

	// Test #5.4, tower tries to go out of bounds
	{
		try {
			// move #1
			std::cout << "Test #5.4" << std::endl;
			std::unique_ptr<Move> movePtr = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(7, 0));
			if (movePtr == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(6, 0));
				movePtr->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			// move #2
			std::unique_ptr<Move> movePtr2 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(0, 0));
			if (movePtr2 == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr2->setEndSquare(chessGame_.getEchiquier()->getCase(1, 0));
				movePtr2->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			// move #3
			std::unique_ptr<Move> movePtr3 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(6, 0));
			if (movePtr3 == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr3->setEndSquare(chessGame_.getEchiquier()->getCase(6, 1));
				movePtr3->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			// move #4
			std::unique_ptr<Move> movePtr4 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(1, 0));
			if (movePtr4 == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr4->setEndSquare(chessGame_.getEchiquier()->getCase(2, 0));
				movePtr4->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}


			// move #5
			std::unique_ptr<Move> movePtr5 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(6, 1));
			if (movePtr == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr5->setEndSquare(chessGame_.getEchiquier()->getCase(6, 8));
				movePtr5->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}
			std::cout << std::endl;
		}
		catch (SquareNotFound& e) {
			std::cout << "The move tries to go outside the board and so it has been terminated" << std::endl;
			std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
		}
		this->resetBoard();
	}

	// Test #6.1, bishop tries to go out of bounds
	{
		try {
			std::cout << "Test #6.1" << std::endl;
			std::unique_ptr<Move> movePtr = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(7, 2));
			if (movePtr == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(8, 1));
				movePtr->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}
			std::cout << std::endl;
		}
		catch (SquareNotFound& e) {
			std::cout << "The move tries to go outside the board and so it has been terminated" << std::endl;
			std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
		}
		this->resetBoard();
	}

	// Test #6.2, bishop tries to go out of bounds
	{
		try {
			std::cout << "Test #6.2" << std::endl;
			std::unique_ptr<Move> movePtr = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(7, 2));
			if (movePtr == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(4, -1));
				movePtr->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}
			std::cout << std::endl;
		}
		catch (SquareNotFound& e) {
			std::cout << "The move tries to go outside the board and so it has been terminated" << std::endl;
			std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
		}
		this->resetBoard();
	}

	// Test #6.3, bishop tries to go out of bounds
	{
		try {
			std::cout << "Test #6.3" << std::endl;
			std::unique_ptr<Move> movePtr = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(7, 2));
			if (movePtr == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(1, 8));
				movePtr->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}
			std::cout << std::endl;
		}
		catch (SquareNotFound& e) {
			std::cout << "The move tries to go outside the board and so it has been terminated" << std::endl;
			std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
		}
		this->resetBoard();
	}

	// Test #6.4, bishop tries to go out of bounds
	{
		try {
			std::cout << "Test #6.4" << std::endl;
			std::unique_ptr<Move> movePtr = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(7, 2));
			if (movePtr == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(8, 3));
				movePtr->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}
			std::cout << std::endl;
		}
		catch (SquareNotFound& e) {
			std::cout << "The move tries to go outside the board and so it has been terminated" << std::endl;
			std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
		}
		this->resetBoard();
	}

	// Test #7, King tries to go out of bounds
	{
		try {
			std::cout << "Test #7" << std::endl;
			std::unique_ptr<Move> movePtr = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(7, 4));
			if (movePtr == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(8, 4));
				movePtr->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}
			std::cout << std::endl;
		}
		catch (SquareNotFound& e) {
			std::cout << "The move tries to go outside the board and so it has been terminated" << std::endl;
			std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
		}
		this->resetBoard();
	}

	// Test #8.1, bishop eat tower (opposite color).
	{
		try {
			std::cout << "Test #8.1" << std::endl;
			// move #1
			std::unique_ptr<Move> movePtr = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(7, 5));
			if (movePtr == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(6, 6));
				movePtr->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			//move #2
			std::unique_ptr<Move> movePtr2 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(0, 7));
			if (movePtr2 == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr2->setEndSquare(chessGame_.getEchiquier()->getCase(1, 7));
				movePtr2->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			// move #3
			std::unique_ptr<Move> movePtr3 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(6, 6));
			if (movePtr2 == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr3->setEndSquare(chessGame_.getEchiquier()->getCase(0, 0));
				movePtr3->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
		}
		catch (SquareNotFound& e) {
			std::cout << "The move tries to go outside the board and so it has been terminated" << std::endl;
			//std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
		}
		this->resetBoard();
	}

	// Test #8.2, bishop eat bishop (opposite color).
	{
		try {
			std::cout << "Test #8.2" << std::endl;
			// move #1
			std::unique_ptr<Move> movePtr = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(7, 5));
			if (movePtr == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(6, 6));
				movePtr->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			//move #2
			std::unique_ptr<Move> movePtr2 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(0, 2));
			if (movePtr2 == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr2->setEndSquare(chessGame_.getEchiquier()->getCase(1, 1));
				movePtr2->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			// move #3
			std::unique_ptr<Move> movePtr3 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(6, 6));
			if (movePtr2 == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr3->setEndSquare(chessGame_.getEchiquier()->getCase(1, 1));
				movePtr3->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
		}
		catch (SquareNotFound& e) {
			std::cout << "The move tries to go outside the board and so it has been terminated" << std::endl;
			//std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
		}
		this->resetBoard();
	}

	// Test #9.1, tower eat tower (opposite color).
	{
		try {
			std::cout << "Test #9.1" << std::endl;
			// move #1
			std::unique_ptr<Move> movePtr = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(7, 0));
			if (movePtr == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(0, 0));
				movePtr->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}
			std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
		}
		catch (SquareNotFound& e) {
			std::cout << "The move tries to go outside the board and so it has been terminated" << std::endl;
			//std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
		}
		this->resetBoard();
	}

	// Test #9.2, tower eat bishop (opposite color).
	{
		try {
			std::cout << "Test #9.2" << std::endl;
			// move #1
			std::unique_ptr<Move> movePtr = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(7, 0));
			if (movePtr == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(6, 0));
				movePtr->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			//move #2
			std::unique_ptr<Move> movePtr2 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(0, 2));
			if (movePtr2 == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr2->setEndSquare(chessGame_.getEchiquier()->getCase(2, 0));
				movePtr2->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			// move #3
			std::unique_ptr<Move> movePtr3 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(6, 0));
			if (movePtr2 == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr3->setEndSquare(chessGame_.getEchiquier()->getCase(2, 0));
				movePtr3->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
		}
		catch (SquareNotFound& e) {
			std::cout << "The move tries to go outside the board and so it has been terminated" << std::endl;
			//std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
		}
		this->resetBoard();
	}

	// Test #10.1 king eat bishop (opposite color).
	{
		try {
			std::cout << "Test #10.1" << std::endl;
			// move #1
			std::unique_ptr<Move> movePtr = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(7, 4));
			if (movePtr == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(6, 5));
				movePtr->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			//move #2
			std::unique_ptr<Move> movePtr2 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(0, 2));
			if (movePtr2 == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr2->setEndSquare(chessGame_.getEchiquier()->getCase(5, 7));
				movePtr2->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			// move #3
			std::unique_ptr<Move> movePtr3 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(6, 5));
			if (movePtr2 == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr3->setEndSquare(chessGame_.getEchiquier()->getCase(7, 4));
				movePtr3->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			// move #4
			std::unique_ptr<Move> movePtr4 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(5, 7));
			if (movePtr4 == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr4->setEndSquare(chessGame_.getEchiquier()->getCase(7, 5));
				movePtr4->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			// move #5
			std::unique_ptr<Move> movePtr5 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(7, 4));
			if (movePtr2 == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr5->setEndSquare(chessGame_.getEchiquier()->getCase(7, 5));
				movePtr5->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
		}
		catch (SquareNotFound& e) {
			std::cout << "The move tries to go outside the board and so it has been terminated" << std::endl;
			//std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
		}
		this->resetBoard();
	}

	// Test #10.2 king eat tower (opposite color).
	{
		try {
			std::cout << "Test #10.2" << std::endl;
			// move #1
			std::unique_ptr<Move> movePtr = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(7, 4));
			if (movePtr == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(6, 5));
				movePtr->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			//move #2
			std::unique_ptr<Move> movePtr2 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(0, 7));
			if (movePtr2 == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr2->setEndSquare(chessGame_.getEchiquier()->getCase(7, 7));
				movePtr2->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			// move #3
			std::unique_ptr<Move> movePtr3 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(6, 5));
			if (movePtr2 == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr3->setEndSquare(chessGame_.getEchiquier()->getCase(6, 6));
				movePtr3->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			// move #4
			std::unique_ptr<Move> movePtr4 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(0, 0));
			if (movePtr4 == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr4->setEndSquare(chessGame_.getEchiquier()->getCase(7, 0));
				movePtr4->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			// move #5
			std::unique_ptr<Move> movePtr5 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(6, 6));
			if (movePtr2 == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr5->setEndSquare(chessGame_.getEchiquier()->getCase(7, 7));
				movePtr5->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
		}
		catch (SquareNotFound& e) {
			std::cout << "The move tries to go outside the board and so it has been terminated" << std::endl;
			//std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
		}
		this->resetBoard();
	}

	// Test #11 king moves into check.
	{
		try {
			std::cout << "Test #11" << std::endl;
			// move #1
			std::unique_ptr<Move> movePtr = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(7, 0));
			if (movePtr == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(1, 0));
				movePtr->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}

			//move #2
			std::unique_ptr<Move> movePtr2 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(0, 4));
			if (movePtr2 == nullptr) {
				std::cout << "Move was illegal" << std::endl;
			}
			else {
				movePtr2->setEndSquare(chessGame_.getEchiquier()->getCase(1, 4));
				movePtr2->executeMove(chessGame_.getEchiquier());
				this->chessGame_.determineNextStates();
			}
			std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
		}
		catch (SquareNotFound& e) {
			std::cout << "The move tries to go outside the board and so it has been terminated" << std::endl;
			//std::cout << "Test passed" << std::endl;
			std::cout << std::endl;
		}
		this->resetBoard();
	}

	//// Test #12 king eat tower (opposite color).
	//{
	//	try {
	//		std::cout << "Test #12" << std::endl;
	//		// move #1
	//		std::unique_ptr<Move> movePtr = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(7, 4));
	//		if (movePtr == nullptr) {
	//			std::cout << "Move was illegal" << std::endl;
	//		}
	//		else {
	//			movePtr->setEndSquare(chessGame_.getEchiquier()->getCase(6, 5));
	//			movePtr->executeMove(chessGame_.getEchiquier());
	//			this->chessGame_.determineNextStates();
	//		}

	//		//move #2
	//		std::unique_ptr<Move> movePtr2 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(0, 7));
	//		if (movePtr2 == nullptr) {
	//			std::cout << "Move was illegal" << std::endl;
	//		}
	//		else {
	//			movePtr2->setEndSquare(chessGame_.getEchiquier()->getCase(7, 7));
	//			movePtr2->executeMove(chessGame_.getEchiquier());
	//			this->chessGame_.determineNextStates();
	//		}

	//		// move #3
	//		std::unique_ptr<Move> movePtr3 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(6, 5));
	//		if (movePtr2 == nullptr) {
	//			std::cout << "Move was illegal" << std::endl;
	//		}
	//		else {
	//			movePtr3->setEndSquare(chessGame_.getEchiquier()->getCase(6, 6));
	//			movePtr3->executeMove(chessGame_.getEchiquier());
	//			this->chessGame_.determineNextStates();
	//		}

	//		// move #4
	//		std::unique_ptr<Move> movePtr4 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(0, 0));
	//		if (movePtr4 == nullptr) {
	//			std::cout << "Move was illegal" << std::endl;
	//		}
	//		else {
	//			movePtr4->setEndSquare(chessGame_.getEchiquier()->getCase(7, 0));
	//			movePtr4->executeMove(chessGame_.getEchiquier());
	//			this->chessGame_.determineNextStates();
	//		}

	//		// move #5
	//		std::unique_ptr<Move> movePtr5 = this->chessGame_.createMoveObject(chessGame_.getEchiquier()->getCase(6, 6));
	//		if (movePtr2 == nullptr) {
	//			std::cout << "Move was illegal" << std::endl;
	//		}
	//		else {
	//			movePtr5->setEndSquare(chessGame_.getEchiquier()->getCase(7, 7));
	//			movePtr5->executeMove(chessGame_.getEchiquier());
	//			this->chessGame_.determineNextStates();
	//		}

	//		std::cout << "Test passed" << std::endl;
	//		std::cout << std::endl;
	//	}
	//	catch (SquareNotFound& e) {
	//		std::cout << "The move tries to go outside the board and so it has been terminated" << std::endl;
	//		//std::cout << "Test passed" << std::endl;
	//		std::cout << std::endl;
	//	}
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
	echiquier->getCase(7, 4)->addPiece(std::make_shared<Roi>(echiquier->getCase(7, 4), "White"));
	echiquier->getCase(7, 7)->addPiece(std::make_shared<Tour>(echiquier->getCase(7, 7), "White"));
	echiquier->getCase(7, 0)->addPiece(std::make_shared<Tour>(echiquier->getCase(7, 0), "White"));
	echiquier->getCase(7, 2)->addPiece(std::make_shared<Fou>(echiquier->getCase(7, 2), "White"));
	echiquier->getCase(7, 5)->addPiece(std::make_shared<Fou>(echiquier->getCase(7, 5), "White"));

	// add the black peices.
	echiquier->getCase(0, 4)->addPiece(std::make_shared<Roi>(echiquier->getCase(0, 4), "Black"));
	echiquier->getCase(0, 7)->addPiece(std::make_shared<Tour>(echiquier->getCase(0, 7), "Black"));
	echiquier->getCase(0, 0)->addPiece(std::make_shared<Tour>(echiquier->getCase(0, 0), "Black"));
	echiquier->getCase(0, 2)->addPiece(std::make_shared<Fou>(echiquier->getCase(0, 2), "Black"));
	echiquier->getCase(0, 5)->addPiece(std::make_shared<Fou>(echiquier->getCase(0, 5), "Black"));

	this->chessGame_.setPlayerTurn(Chess::PlayerTurn::White);
	this->chessGame_.setGameState(Chess::GameState::Normal);
}