#ifndef RUSH00_MENU_HPP
#define RUSH00_MENU_HPP

#include <iostream>
#include "ncurses.h"


class Menu {

protected:
	int numberMenu;
	int w;
	int h;
	char* men[3];



public:
	int startMenu();
	Menu();
	~Menu();
	void 	drawMenu();
	void 	draw(int menu, int w, int h);
	void	clean(int me, int w, int h);
	int select();

	int getNumberMenu() const;

	void setNumberMenu(int numberMenu);

};


#endif
