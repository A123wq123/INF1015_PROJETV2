#pragma once
#include "Debugg.h"

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
	// test #1, make an move that selects no pieces.
	{
		std::cout << "Test #1" << std::endl;
		Move moveObject = Move(chessGame_.getEchiquier()->getCase(2, 2));
		moveObject.setEndSquare(chessGame_.getEchiquier()->getCase(3, 2));
		moveObject.executeMove(chessGame_.getEchiquier());
		std::cout << "Test passed" << std::endl;
		std::cout << std::endl;
	}

	// test #2, try to kill own piece Tour. 
	{
		std::cout << "Test #2" << std::endl;
		Move moveObject = Move(chessGame_.getEchiquier()->getCase(7, 0));
		moveObject.setEndSquare(chessGame_.getEchiquier()->getCase(7, 2));
		moveObject.executeMove(chessGame_.getEchiquier());
		std::cout << "Test passed" << std::endl;
		std::cout << std::endl;
	}
	
	// test #3, try to kill own piece Fou. 
	{
		std::cout << "Test #3" << std::endl;
		Move moveObject = Move(chessGame_.getEchiquier()->getCase(7, 2));
		moveObject.setEndSquare(chessGame_.getEchiquier()->getCase(6, 1));
		moveObject.executeMove(chessGame_.getEchiquier());

		Move moveObject2 = Move(chessGame_.getEchiquier()->getCase(6, 1));
		moveObject2.setEndSquare(chessGame_.getEchiquier()->getCase(7, 0));
		moveObject2.executeMove(chessGame_.getEchiquier());

		std::cout << "Test passed" << std::endl;
		std::cout << std::endl;
	}

}