#include "Enemy.hpp"

int Enemy::count = 0;

Enemy::Enemy(int y, int x, int mY, int mX, int dir) : NLO(x - 1, y, mX, mY), dirY(dir), dirX(1){
	count++;
}

Enemy::~Enemy() {
	count--;
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
	}
	if (dirX == 1 && this->posX + dirX < maxX)
	{
		this->posX += dirX;
	} else
		dirY = -1;
	if (dirX == 1 && this->posX + dirX > 0)
	{
		this->posX += dirX;
	} else
		dirY = -1;
	return flag;
}

void	Enemy::drawEnemy() {
	mvprintw(posY , posX, "#");
}
