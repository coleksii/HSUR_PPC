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

void Game::checkFps() {
	fps.getFps();
}

void	Game::doEnemy() {
	TListNode<Enemy*> *ptr;

	ptr = enemyList.getStart();
	Bullet *free;
	erase();
	while (ptr != nullptr)
	{
		if (ptr->getData() != nullptr && ptr->getData()->doAction() == false)
		{
			free = enemyList.removeNode(ptr);
			//	delete(free);
		}
		ptr = ptr->getNext();
	}
}

void Game::checkFps() {
	fps.getFps();
}

void Game::bornEneme() {

	bornEnemyCount += fps.getFps();
	if (bornEnemyCount >= 1000)
	{
		int x = rand() % ship->getMaxX();
		Enemy *enemy = new Enemy(0, x, ship->getPosY(), ship->getMaxX(), 1);
		enemyList.addNode(enemy);
	}
}

void Game::gameAll(int loop) {
	checkFps();
	checkControl(loop);
	bornEneme();
	doBullets();
	doEnemy();
}
