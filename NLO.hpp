#ifndef NLO_HPP
# define NLO_HPP

#include "ncurses.h"

class NLO {
public:
	NLO(int, int,int,int);
	~NLO();

	int getPosX() const;

	void setPosX(int posX);

	int getPosY() const;

	void setPosY(int posY);

	int getMaxX() const;

	void setMaxX(int maxX);

	int getMaxY() const;

	void setMaxY(int maxY);

protected:
	int posX;
	int posY;
	int maxX;
	int maxY;
};


#endif
