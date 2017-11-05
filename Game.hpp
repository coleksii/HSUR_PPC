#ifndef CONTORLS_HPP
#define CONTORLS_HPP

#include "Bullet.hpp"
#include "Spaceship.hpp"
#include "TLists.hpp"
#include "TListNode.hpp"

class	Game {
public:
	Game(Spaceship *ship, TList<Bullet*> *bullets);
	~Game();
	void checkControl(const int key);
	void doBullets();
protected:
	Spaceship		*ship;
	TList<Bullet*>	*bullets;
};


#endif
