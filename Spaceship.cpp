#include "Spaceship.hpp"

Spaceship::Spaceship(int posX, int posY,int maxX,int maxY) : NLO(posX, posY, maxX, maxY) {
}

Spaceship::~Spaceship() {

}

void	Spaceship::drawShip() {
	mvprintw(posY -3, posX - 2, "/^\\");
	mvprintw(posY -2, posX - 3, "| 0 |");
	mvprintw(posY -1, posX - 4, "< /_\\ >");
	mvprintw(posY, posX - 3, "^^^^^");
}

void Spaceship::moveRight() {
	if (posX + 2 + 2 < this->maxX)
	this->posX += 2;
}


void Spaceship::moveLeft() {
	if (posX -2 - 2 > 0)
	this->posX -= 2;
}

void Spaceship::moveUp() {
	if (posY - 3 > 0)
		this->posY -= 1;
}

void Spaceship::moveDown() {
	if (posY + 1 < this->maxY) {
//		mvprintw(0, 0, "%d", posY);
		this->posY += 1;
	}
}

Bullet *Spaceship::attack() {
	Bullet *ret = new Bullet(posY, posX, maxY, maxX, -1);
	return (ret);
}



