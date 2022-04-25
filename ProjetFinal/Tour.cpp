#include "Tour.h"
static const int numberofRowOrCollumn = 8;
Tour::Tour() {

}

Tour::~Tour() {

}
void Tour::checkPossibleMoves() {
	if (vectorLegalMovesGenerated_ )
	{

	}
	else
	{
		for (int counter = 0; counter < numberofRowOrCollumn; counter++)
		{
			if (checkIfValidMove(case_->getRow(), counter))
			{
				vectorLegalMoves_.push_back((echiquier_->getVectorCase())[counter][case_->getRow()]);

			}

		}
		for (int counter = 0; counter < numberofRowOrCollumn; counter++)
		{
			if (checkIfValidMove(counter, case_->getCollumn()))
			{
				vectorLegalMoves_.push_back((echiquier_->getVectorCase())[case_->getCollumn()][counter]);

			}
		}
		vectorLegalMovesGenerated_ = true; // il faut "output" les mouvements légales sur le UI
	}

}



void Tour::movePiece() {





}



bool Tour::checkIfValidMove(int posX, int posY) {
	if (case_->getCollumn() == posX)
	{
		if (posY > case_->getRow())
		{
			int difference = posY - case_->getRow();
			for (int counter = 0; counter < difference; counter++)
			{
				if (echiquier_->getVectorCase()[case_->getCollumn()][(case_->getRow() + counter)]->getIsOccupied())
				{
					return false;
				}

			}
			return true;
		}
		if (posY < case_->getRow())
		{
			int difference = case_->getRow() - posY;
			for (int counter = 0; counter < difference; counter++)
			{
				if (echiquier_->getVectorCase()[case_->getCollumn()][(case_->getRow() - counter)]->getIsOccupied())
				{
					return false;
				}

			}
			return true;
		}
	}


	else if (case_->getRow() == posY) {
		if (posX > case_->getCollumn())
		{
			int difference = posX - case_->getCollumn();
			for (int counter = 0; counter < difference; counter++)
			{
				if (echiquier_->getVectorCase()[case_->getRow()][(case_->getCollumn() + counter)]->getIsOccupied())
				{
					return false;
				}

			}
			return true;
		}
		if (posX < case_->getCollumn())
		{
			int difference = case_->getCollumn() - posX;
			for (int counter = 0; counter < difference; counter++)
			{
				if (echiquier_->getVectorCase()[case_->getRow()][(case_->getCollumn() - counter)]->getIsOccupied())
				{
					return false;
				}

			}
			return true;
		}
	}
}