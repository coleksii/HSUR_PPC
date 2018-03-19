#include "Window.hpp"
#include "Spaceship.hpp"
#include "Game.hpp"
#include "TListNode.hpp"
#include "TLists.hpp"
#include <stdio.h>
#include "Menu.hpp"

void	scrColor()
{
	start_color();

	init_pair(1,COLOR_YELLOW,COLOR_BLUE);
	init_pair(2,COLOR_BLUE,COLOR_BLACK);
	init_pair(3,COLOR_RED,COLOR_BLACK);
	init_pair(4,COLOR_YELLOW,COLOR_BLACK);
//	wbkgd(stdscr, COLOR_PAIR((3)));
}

int		ft_loop(Window win) {
	int loop = true;
	int x;
	int y;
	getmaxyx(stdscr, y, x);
	scrColor();
	Menu men;
	if(men.startMenu() == 3)
		exit(0);
	Spaceship ship(x/2, y/2, win.getW(), win.getH());
	TList<Bullet*>	bulletList;
	Game game(&ship, &bulletList);
	while(loop)
	{
		loop = win.keyHook();
		loop = game.gameAll(loop);
		ship.drawShip();
		refresh();
		usleep(20000);
	}
//	GameOver();
	return (1);
}

int		main() {

	Window win;
	ft_loop(win);
	return 0;
}