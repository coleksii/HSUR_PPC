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
	attron(COLOR_PAIR(4));
	mvprintw(posY , posX, "^");
	attrset(A_NORMAL);
}

Bullet &Bullet::operator=(Bullet const & src) {
	this->direction = src.direction;
	this->posX = src.posX;
	this->posY = src.posY;
	this->maxX = src.maxX;
	this->maxY = src.maxY;
	return (*this);
}

Bullet::Bullet(Bullet const &src) {
	*this = src;
}


