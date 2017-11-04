#ifndef CONTORLS_HPP
#define CONTORLS_HPP

#include "Bullet.hpp"
#include "Spaceship.hpp"
#include "TLists.hpp"

class	Game {
public:
	Game(Spaceship &ship, TList &bullets);
	~Game();
	void checkControl(const int key);
protected:
	Spaceship	&ship;
	TList		&bullets;
};


#endif
