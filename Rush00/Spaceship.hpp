#ifndef SPACESHIP_HPP
# define SPACESHIP_HPP

#include "NLO.hpp"
#include "ncurses.h"

class Spaceship : public  NLO {
public:
	Spaceship(int, int, int, int);
	~Spaceship();
	void drawShip();
	void checkControl(const int key);

private:
	void moveRight();
	void moveLeft();
	void moveDown();
	void moveUp();
	void attack();
};


#endif
