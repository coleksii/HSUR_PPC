#include <iostream>
#include <zconf.h>
#include "Window.hpp"
#include "Spaceship.hpp"

void	scrColor()
{
	start_color();

	init_pair(1,COLOR_YELLOW,COLOR_BLUE);
	init_pair(2,COLOR_BLUE,COLOR_YELLOW);
	init_pair(3,COLOR_BLUE,COLOR_WHITE);
	wbkgd(stdscr, COLOR_PAIR((3)));
}

int	ft_loop(Window win) {
	int loop = true;
	int x = 0;
	int y = 0;
	Spaceship ship(20, 20, win.getW(), win.getH());
	while(loop)
	{
		loop = win.keyHook();
		ship.checkControl(loop);
		ship.drawShip();
		refresh();
		x++;
		y++;
	}
	return (1);
}

int main() {

	Window win;
	ft_loop(win);
	return 0;
}