#pragma once
#include <memory>
#include "Echiquier.h"

namespace Chess {

	enum class PlayerTurn
	{
		White,
		Black
	};

	enum class GameState 
	{
		Normal,     // Normal state of a game.
		WhiteInCheckMate,
		BlackInCheckmate
	};

	class ChessGame {
	public:
		ChessGame(std::unique_ptr<Echiquier>& echiquier);
		~ChessGame() = default; 
		void determineNextStates();
		const PlayerTurn getPlayerTurn() { return playerTurn_; }
		const GameState getGameState() { return gameState_; }
		Echiquier* getEchiquier() { return echiquer_; }

	private:
		Echiquier* echiquer_;
		PlayerTurn playerTurn_;
		GameState gameState_;
	};
}