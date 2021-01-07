#include "Game.h"
#include "Player.h"

int main() {

	Game game;

	while (game.Play()) {
		game.menu();
		
	}
	return 0;
}