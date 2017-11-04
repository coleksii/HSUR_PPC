#include "Game.hpp"

Game::Game(Spaceship &ship, TList &bullets) : ship(ship), bullets(bullets) {}

Game::~Game() {}

void	Game::checkControl(const int key) {
	if (key == 261)
		ship.moveRight();
	else if (key == 260)
		ship.moveLeft();
	else if (key == 259)
		ship.moveUp();
	else if (key == 258)
		ship.moveDown();
	else if (key == 32)
		bullets.addNode(ship.attack());
	if (key != -1)
		werase(stdscr);
}