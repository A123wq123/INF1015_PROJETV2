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
				std::cout << " NullPiece " << "|";
			}
			else {
				std::cout << " " << echiquier->getCase(row, collumn)->getPiece()->getName() << " |";
			}
		}
		std::cout << std::endl;
	}
}