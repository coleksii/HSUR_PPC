#include "Bullet.hpp"

Bullet::Bullet(int y, int x, int mY, int mX, int dir) : NLO(y, x, mY, mX), direction(dir){
}

Bullet::~Bullet() {}

void	Bullet::moveBullet() {
	if (this->posY + direction < maxY && this->posY + direction)
		this->posY += direction;
}

void	Bullet::drawBullet() {
	mvprintw(posY, posX - 1, "тиж");

}
