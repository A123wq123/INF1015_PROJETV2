#include "ChessGame.h"

//enum class PlayerTurn
//{
//	White,
//	Black
//};

void Chess::ChessGame::determineNextStates() {
	switch (playerTurn_) {
	case PlayerTurn::White:
		playerTurn_ = PlayerTurn::Black;
		break;
	case PlayerTurn::Black:
		playerTurn_ = PlayerTurn::White;
		break;
	}

	switch (gameState_) {
	case GameState::Normal:
	{
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

	case GameState::BlackInCheckMate:
	{
		// End the game? Yet to figure out how.
	}
	}
}