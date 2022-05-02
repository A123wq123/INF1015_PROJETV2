#include "Tour.h"
static const int numberofRowOrCollumn = 8;
Tour::Tour(std::shared_ptr<Square>& square, std::string color) : square_(square), row_(square->getCoordinates().first)
, collomn_(square->getCoordinates().second), color_(color) {

}
std::vector<std::shared_ptr<Square>> Tour::checkPossibleMoves(std::unique_ptr<Echiquier>& echiquier) {
	std::vector<std::shared_ptr<Square>> vectorPossibleMoves{};

	// regarde pour les déplacements verticaux 
	for (int counter = 0; counter < numberofRowOrCollumn; counter++)
	{
		std::shared_ptr<Square> squareBeingChecked = echiquier->getCase(square_->getCoordinates().first, counter);
		if (checkIfValidMove(squareBeingChecked, echiquier))
		{
			vectorPossibleMoves.push_back(squareBeingChecked);
		}

	}

	// regarde pour les déplacements horizontaux
	for (int counter = 0; counter < numberofRowOrCollumn; counter++)
	{
		std::shared_ptr<Square> squareBeingChecked = echiquier->getCase(counter, square_->getCoordinates().second);
		if (checkIfValidMove(squareBeingChecked, echiquier))
		{
			vectorPossibleMoves.push_back(squareBeingChecked);

		}
	}
	return vectorPossibleMoves;
}


bool Tour::checkIfValidMove(std::shared_ptr<Square> squareDest, std::unique_ptr<Echiquier>& echiquier) {
	int currentRow = square_->getCoordinates().first;
	int destRow = squareDest->getCoordinates().first;
	int currentCollumn = square_->getCoordinates().second;
	int destCollumn = squareDest->getCoordinates().second;

	if (square_ == squareDest) {
		return false;
		// might want to return true vus que c'est un déplacement de la case A vers elle même mais vas falloir voir avec le code. 
	}

	else if (currentRow == destRow) {

	}



	/*if (case_->getCollumn() == posX)
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
	}*/
}