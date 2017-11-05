#include <zconf.h>
#include "Game.hpp"

Game::Game(Spaceship *ship, TList<Bullet*> *bullets) : ship(ship), bullets(bullets) {}

Game::~Game() {}

void	Game::checkControl(const int key) {
	if (key == 261)
		ship->moveRight();
	if (key == 260)
		ship->moveLeft();
	if (key == 259)
		ship->moveUp();
	if (key == 258)
		ship->moveDown();
	if (key == 32)
		bullets->addNode(ship->attack());
	if (key != -1)
		werase(stdscr);
}

void	Game::doBullets() {
	TListNode<Bullet*> *ptr;
	ptr = bullets->getStart();
	Bullet *free;
	erase();
	while (ptr != nullptr)
	{
		if (ptr->getData() != nullptr && ptr->getData()->doAction() == false)
		{
			free = bullets->removeNode(ptr);
			//	delete(free);
		}
		ptr = ptr->getNext();
	}
}