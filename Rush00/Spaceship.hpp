#ifndef SPACESHIP_HPP
# define SPACESHIP_HPP

#include "NLO.hpp"
#include "Bullet.hpp"

class Spaceship : public  NLO {
public:
	Spaceship(int, int, int, int);
	~Spaceship();
	void drawShip();
	void moveRight();
	void moveLeft();
	void moveDown();
	void moveUp();
	Bullet* attack();
};


#endif
