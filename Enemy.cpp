#include "Enemy.hpp"

int Enemy::count = 0;

Enemy::Enemy(int y, int x, int mY, int mX, int dir) : NLO(x - 1, y, mX, mY), dirY(dir), dirX(2){
	count++;
}

Enemy::~Enemy() {
	count--;
}

Enemy &Enemy::operator=(Enemy const & src) {
	this->dirX = src.dirX;
	this->dirY = src.dirY;
	this->posX = src.posX;
	this->posY = src.posY;
	this->maxX = src.maxX;
	this->maxY = src.maxY;
	return (*this);
}

Enemy::Enemy(Enemy const &src) {
	*this = src;
}

bool	Enemy::doAction(){
	bool ret;
	ret = moveEnemy();
	drawEnemy();
	return ret;
}
bool	Enemy::moveEnemy() {
	bool flag = false;
	if (this->posY + dirY < maxY && this->posY + dirY > 0)
	{
		this->posY += dirY;
		flag = true;
	} else {
		this->posY = -1;
	}
	if (dirX == 1 && this->posX + dirX < maxX)
	{
		this->posX += dirX;
	} else
		dirX = -1;
	if (dirX == -1 && this->posX + dirX > 0)
	{
		this->posX += dirX;
	} else
		dirX = 1;
	return flag;
}

void	Enemy::drawEnemy() {
	mvprintw(posY , posX, "#");
}
