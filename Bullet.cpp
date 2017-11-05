#include "Bullet.hpp"

Bullet::Bullet(int y, int x, int mY, int mX, int dir) : NLO(y, x, mY, mX), direction(dir){
}

Bullet::~Bullet() {}

bool	Bullet::doAction(){
	bool ret = false;
	werase(stdscr);
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
	return false;
}

void	Bullet::drawBullet() {
	mvprintw(posY , posX, "*");
}


