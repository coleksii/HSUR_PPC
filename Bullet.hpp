#ifndef BULLET_HPP
# define BULLET_HPP

#include "NLO.hpp"

class Bullet : public NLO {
public:
	Bullet(int y, int x,int mY, int mX, int dir);
	~Bullet();
	Bullet & operator=(Bullet const&);
	Bullet(Bullet const &);
	bool doAction();
protected:
	bool moveBullet();
	void drawBullet();
	int direction;
};


#endif
