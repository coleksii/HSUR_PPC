#include <zconf.h>
#include "Game.hpp"

Game::Game(Spaceship *ship, TList<Bullet*> *bullets) : ship(ship), bullets(bullets) {
	score = 0;
}

Game::~Game() {}

Game &Game::operator=(Game const & src) {
	this->score = src.score;
	this->bornEnemyCount = src.bornEnemyCount;
	this->enemyList = src.enemyList;
	this->fps = src.fps;
	return (*this);
}

Game::Game(Game const &src) {
	*this = src;
}

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
}

void	Game::doBullets() {
	TListNode<Bullet*> *ptr;
	ptr = bullets->getStart();
	Bullet *free;
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
	fps.calcFps();
}

void	Game::doEnemy() {
	TListNode<Enemy*> *ptr;

	ptr = enemyList.getStart();
	Enemy *free;
	while (ptr != nullptr)
	{
		if (ptr->getData() != nullptr && ptr->getData()->doAction() == false)
		{
			free = enemyList.removeNode(ptr);
//				delete(free);
		}
		ptr = ptr->getNext();
	}
}

void Game::bornEneme() {

	bornEnemyCount += fps.getFps();
	if (bornEnemyCount >= 2000)
	{
		int x = rand() % ship->getMaxX();
		Enemy *enemy = new Enemy(0, x, ship->getMaxY(), ship->getMaxX(), 1);
		enemyList.addNode(enemy);
		bornEnemyCount = 0;
	}
}

int	Game::gameAll(int loop) {
	erase();
	checkControl(loop);
	checkFps();
	bornEneme();
	doBullets();
	doEnemy();
	loop = checkColl(loop);
	mvprintw(0, ship->getMaxX() - 10, "Score: %d", score);refresh();
	return loop;
}

int Game::checkColl(int loop) {
	TListNode<Enemy*> *enemyPtr;
	TListNode<Bullet*> *bullePtr;

	enemyPtr = enemyList.getStart();
	while(enemyPtr != nullptr)
	{
		if (ship->checkColl(enemyPtr->getData()->getPosX(), enemyPtr->getData()->getPosY()))
			loop = false;
		bullePtr = bullets->getStart();
		while (bullePtr != nullptr)
		{
			if (bullePtr->getData()->getPosX() == enemyPtr->getData()->getPosX())
				if (bullePtr->getData()->getPosY() == enemyPtr->getData()->getPosY())
				{
					bullePtr->getData()->setPosY(-1);
					enemyPtr->getData()->setPosY(-1);
					score++;
				}
			bullePtr = bullePtr->getNext();
		}
		enemyPtr = enemyPtr->getNext();
	}
	return loop;
}
