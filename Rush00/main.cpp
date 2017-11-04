#include "Window.hpp"
#include "Spaceship.hpp"
#include "Game.hpp"
#include "TListNode.hpp"

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
	Spaceship ship(20, 20, win.getW(), win.getH());
	TListNode<Bullet> list();
	Game game(ship, list);
	while(loop)
	{
		loop = win.keyHook();
		game.checkControl(loop);
		ship.drawShip();
		refresh();
	}
	return (1);
}

int		main() {

	Window win;
	ft_loop(win);
	return 0;
}