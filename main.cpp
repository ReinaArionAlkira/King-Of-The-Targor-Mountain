#include "Game.h"

int main() {
	Game game;
	srand(time(NULL));
	game.start();
	game.menu();
	while (game.Play()) {
		game.menuInGame();
	}
	return 0;
}