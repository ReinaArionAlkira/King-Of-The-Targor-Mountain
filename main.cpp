#include "Game.h"

int main() {

	Game game;

	while (game.Play()) {
		game.menu();
		
	}
	return 0;
}