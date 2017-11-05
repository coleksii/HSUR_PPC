#include "Window.hpp"
#include "Spaceship.hpp"
#include "Game.hpp"
#include "TListNode.hpp"
#include "TLists.hpp"
#include <stdio.h>

void	scrColor()
{
	start_color();

	init_pair(1,COLOR_YELLOW,COLOR_BLUE);
	init_pair(2,COLOR_BLUE,COLOR_YELLOW);
	init_pair(3,COLOR_BLUE,COLOR_WHITE);
	wbkgd(stdscr, COLOR_PAIR((3)));
}

int		ft_loop(Window win) {
	int loop = true;
	Spaceship ship(100, 50, win.getW(), win.getH());
	TList<Bullet*> list;
	Game game(&ship, &list);

	while(loop)
	{
		loop = win.keyHook();
		game.checkControl(loop);
		game.doBullets();
		ship.drawShip();
		refresh();
		usleep(19999);
	}
	return (1);
}

int		main() {

	Window win;
	ft_loop(win);
	return 0;
}