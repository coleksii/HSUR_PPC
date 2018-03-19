#include "Spaceship.hpp"

Spaceship::Spaceship(int posX, int posY,int maxX,int maxY) : NLO(posX, posY, maxX, maxY) {
}

Spaceship::~Spaceship() {

}

Spaceship &Spaceship::operator=(Spaceship const & src) {
	this->posX = src.posX;
	this->posY = src.posY;
	this->maxX = src.maxX;
	this->maxY = src.maxY;
	return (*this);
}

Spaceship::Spaceship(Spaceship const &src) {
	*this = src;
}


void	Spaceship::drawShip() {
	attron(COLOR_PAIR(2));
	mvprintw(posY -3, posX - 2, "/^\\");
	mvprintw(posY -2, posX - 3, "| 0 |");
	mvprintw(posY -1, posX - 4, "< /_\\ >");
	attron(COLOR_PAIR(3));
	mvprintw(posY, posX - 3, "^^^^^");
	attrset(A_NORMAL);
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

void Spaceship::getColl() {
	colision[0] = (t_v2d){posX - 2, posX + 2, posY};
	colision[1] = (t_v2d){posX - 2, posX + 2, posY - 1};
	colision[2] = (t_v2d){posX - 2, posX + 2, posY - 2};
	colision[3] = (t_v2d){posX - 2, posX + 2, posY - 3};
}

bool Spaceship::checkColl(int x, int y) {

	getColl();

	for (int i = 0; i < 4; i++)
	{
		if (colision[i].y == y && x >= colision[i].x1 && x <= colision->x2)
			return true;
	}
	return false;
}



