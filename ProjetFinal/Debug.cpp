#pragma once
#include "Debugg.h"

void Debugg::printBoardState() {
	auto&& echiquier = chessGame_.getEchiquier();
	// Iterate on all possible squares. 
	for (int row = 0; row < echiquier->getNumberOfRows(); row++) {
		for (int collumn = 0; collumn < echiquier->getNumberOfCollumns(); collumn++) {
			// The null piece doesn't have a name to not interfere with regualr UI
			// We then have to give it a fictiionnal one here for debugg.
			if (echiquier->getCase(row, collumn)->getPiece()->getName() == "") {
				std::cout << "           " << "|";
			}
			else {
				std::cout << " " << echiquier->getCase(row, collumn)->getPiece()->getName() << " |";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------------------"
		"------------" << std::endl;
}

void Debugg::lancerSerieTests() {
	// test #1
	{
		this->printBoardState();
		Move moveObject = Move(chessGame_.getEchiquier()->getCase(2, 2));
		moveObject.setEndSquare(chessGame_.getEchiquier()->getCase(3, 2));
		moveObject.executeMove(chessGame_.getEchiquier());
		this->printBoardState();
	}
	

}