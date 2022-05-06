#include "ChessGame.h"

Chess::ChessGame::ChessGame(Echiquier* const echiquier) : echiquer_(echiquier), 
	playerTurn_(PlayerTurn::White), gameState_(GameState::Normal)
{
	// As per chess rules white is alwasy the one to start.
}

void Chess::ChessGame::determineNextStates() {
	switch (playerTurn_) {
	case PlayerTurn::White:
		playerTurn_ = PlayerTurn::Black;
		// Wonder if we ask what the move is here.
		break;
	case PlayerTurn::Black:
		playerTurn_ = PlayerTurn::White;
		break;
	}

	switch (gameState_) {
	case GameState::Normal:
	{
		// Or if we ask for the move here instead.
		std::string color;
		playerTurn_ == PlayerTurn::White ? color = "White" : color = "Black";
		if (echiquer_->isKingInCheckMate(color)) {
			color == "White" ? gameState_ = GameState::WhiteInCheckMate : gameState_ = GameState::BlackInCheckmate;
		}
		break;
	}

	case GameState::WhiteInCheckMate:
	{
		// End the game? Yet to figure out how.
	}

	case GameState::BlackInCheckmate:
	{
		// End the game? Yet to figure out how.
	}
	}
}

std::unique_ptr<Move> Chess::ChessGame::createMoveObject(Square* startSquare) {
	std::string colorOfPiece = startSquare->getPiece()->getColor();
	if (this->getPlayerTurn() == PlayerTurn::White) {
		if (colorOfPiece == "White") {
			return std::make_unique<Move>(startSquare);
		}
		else {
			std::cout << "Not your turn!" << std::endl;
			return nullptr;
		}
	}
	else if (this->getPlayerTurn() == PlayerTurn::Black) {
		if (colorOfPiece == "Black") {
			return std::make_unique<Move>(startSquare);
		}
		else {
			std::cout << "Not your turn!" << std::endl;
			return nullptr;
		}
	}
}