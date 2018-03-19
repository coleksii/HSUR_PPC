#ifndef SPACESHIP_HPP
# define SPACESHIP_HPP

#include "NLO.hpp"
#include "Bullet.hpp"

typedef struct s_v2d t_v2d;

struct s_v2d{
	int x1;
	int x2;
	int y;
};

class Spaceship : public  NLO {
public:
	Spaceship(int, int, int, int);
	~Spaceship();
	Spaceship & operator=(Spaceship const&);
	Spaceship(Spaceship const &);
	void drawShip();
	void moveRight();
	void moveLeft();
	void moveDown();
	void moveUp();
	Bullet* attack();
	void	getColl();
	bool	checkColl(int x, int y);
protected:
	t_v2d	colision[4];

};


#endif
