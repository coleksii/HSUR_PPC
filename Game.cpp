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
		bullets->add(ship->attack());
	if (key != -1)
		werase(stdscr);
}

void	Game::doBullets() {
	TListNode<Bullet*> *ptr;
	ptr = bullets->getStart();
//	TListNode<Bullet*> *free;
	while (ptr != nullptr)
	{
		if (ptr->getData()->doAction() == false)
		{
//			free = ptr->remove();
//			delete(free->getData());
//			delete(free);
//			ptr->getPrev()->setNext(nullptr);
//			delete(ptr);
//			break ;
		}
		ptr = ptr->getNext();
	}
}