#include "Bullet.hpp"

Bullet::Bullet(int y, int x, int mY, int mX, int dir) : NLO(x - 1, y, mX, mY), direction(dir){
}

Bullet::~Bullet() {}

bool	Bullet::doAction(){
	bool ret;
	ret = moveBullet();
	drawBullet();
	return ret;
}
bool	Bullet::moveBullet() {
	if (this->posY + direction < maxY && this->posY + direction > 0)
	{
		this->posY += direction;
		return true;
	}
	this->posY = -1;
	return false;
}

void	Bullet::drawBullet() {
	mvprintw(posY , posX, "^");
}


