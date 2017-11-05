#ifndef CONTORLS_HPP
#define CONTORLS_HPP

#include "Bullet.hpp"
#include "Spaceship.hpp"
#include "TLists.hpp"
#include "TListNode.hpp"
#include "Enemy.hpp"
#include "Fps.hpp"

class	Game {
public:
	Game(Spaceship *ship, TList<Bullet*> *bullets);
	~Game();
	void checkControl(const int key);
	void doBullets();
	void doEnemy();
	void checkFps();
	void bornEneme();
	void gameAll(int loop);
protected:
	Spaceship		*ship;
	TList<Bullet*>	*bullets;
	TList<Enemy*>	enemyList;
	Fps 			fps;
private:
	int				bornEnemyCount;
};


#endif
