#include "Game.h"

int main() {
	Game game;
	srand( time_t(NULL) );
	game.board();
	game.menu();

	while (game.Play()) {
		game.menuInGame();
	}
	game.end();
	return 0;
}