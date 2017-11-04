#ifndef BULLET_HPP
# define BULLET_HPP

#include "NLO.hpp"

class Bullet : public NLO {
public:
	Bullet(int y, int x,int mY, int mX, int dir);
	~Bullet();
	void moveBullet();
	void drawBullet();
protected:
	int direction;
};


#endif
