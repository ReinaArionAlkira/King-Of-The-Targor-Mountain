#include "Game.h"
#include "Player.h"

int main() {

	Game game;

	while (game.Play()) {
		Player player1;
		player1.getStats();
		game.menu();
		
	}
	return 0;
}