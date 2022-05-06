#pragma once
#include <memory>
#include "Echiquier.h"
#include "Move.h"

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
		ChessGame(Echiquier* const echiquier);
		~ChessGame() = default; 
		void determineNextStates();
		const PlayerTurn getPlayerTurn() { return playerTurn_; }
		const GameState getGameState() { return gameState_; }
		Echiquier* getEchiquier() { return echiquer_; }
		std::unique_ptr<Move> createMoveObject(Square* startSquare);

		// Methods usefull in debugg.
		void setEchiquier(Echiquier* echiquier) { echiquer_ = echiquier; }
		void setPlayerTurn(PlayerTurn playerturn) { playerTurn_ = playerturn; }
		void setGameState(GameState gameState) { gameState_ = gameState; }

	private:

		Echiquier* echiquer_;
		PlayerTurn playerTurn_;
		GameState gameState_;
	};
}