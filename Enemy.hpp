#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "NLO.hpp"

class Enemy : public NLO {
public:
	Enemy(int y, int x,int mY, int mX, int dir);
	~Enemy();
	bool doAction();
protected:
	bool moveEnemy();
	void drawEnemy();
	void attakEnemy();
	int dirY;
	int dirX;
	static int count;
};


#endif
