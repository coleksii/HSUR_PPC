#ifndef CONTORLS_HPP
#define CONTORLS_HPP

#include "Bullet.hpp"
#include "Spaceship.hpp"
#include "TLists.hpp"
#include "TListNode.hpp"
#include "Enemy.hpp"
#include "Fps.hpp"
#include "ncurses.h"

class	Game {
public:
	Game(Spaceship *ship, TList<Bullet*> *bullets);
	~Game();
	Game & operator=(Game const&);
	Game(Game const &);
	void checkControl(const int key);
	void doBullets();
	void doEnemy();
	void checkFps();
	void bornEneme();
	int checkColl(int loop);
	int gameAll(int loop);
protected:
	Spaceship		*ship;
	TList<Bullet*>	*bullets;
	TList<Enemy*>	enemyList;
	Fps 			fps;
private:
	int 			score;
	int				bornEnemyCount;
};


#endif
