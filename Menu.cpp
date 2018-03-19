//
// Created by Chechuha Oleksii on 11/4/17.
//

#include "Menu.hpp"

Menu::Menu(){

	getmaxyx(stdscr, h, w);
	h /= 2;
	w /= 2;
	numberMenu = 0;
	men[0] = (char *)"  GAME  ";
	men[1] = (char *)"CREDITS ";
	men[2] = (char *)"  EXIT  ";
}

Menu::~Menu() {
}

Menu &Menu::operator=(Menu const & src) {
	this->numberMenu = src.numberMenu;
	this->w = src.w;
	this->h = src.h;
	return (*this);
}

Menu::Menu(Menu const &src) {
	*this = src;
}

int Menu::startMenu() {
	int selMen;
	drawMenu();
	selMen = select();
	erase();
	return selMen;
}

void Menu::drawMenu(){
	int i = 0;

	getmaxyx(stdscr, h, w);
	h /= 2;
	w /= 2;
	draw(numberMenu, w, h);
	while (i < 50){
		mvprintw(h - 10, w - 25 + i, "__");
		mvprintw(h + 5, w - 25 + i, "__");
		mvprintw(h - 5, w - 25 + i, "__");
		mvprintw(h, w - 25 + i, "__");
		i++;
	}
	if (numberMenu != 0)
	mvprintw(h - 7 + 0, w - 24, "                     %s                    ", men[0]);
	if (numberMenu != 1)
	mvprintw(h - 7 + 5, w - 24, "                     %s                    ", men[1]);
	if (numberMenu != 2)
	mvprintw(h - 7 + 10, w - 24, "                     %s                    ", men[2]);
	i = 1;
	while (i < 16) {
		mvprintw(h - 10 + i, w - 25, "|");
		mvprintw(h - 10 + i, w + 25, "|");
		i++;
	}
	refresh();
}

void	Menu::draw(int me, int w, int h){
	int sel = me * 5;
	attron(COLOR_PAIR(1));
	for (int i = 0; i < 48; i++){
		mvprintw(h - 9 + sel , w - 24 + i, "  ");
		mvprintw(h - 8 + sel, w - 24 + i, "  ");
		mvprintw(h - 6 + sel, w - 24 + i, "  ");


	}
	mvprintw(h - 7 + sel, w - 24, "                     %s                    ", men[me]);
	attrset(A_NORMAL);
}

void	Menu::clean(int me, int w, int h){
	int sel = me * 5;
	for (int i = 0; i < 48; i++){
		mvprintw(h - 9 + sel , w - 24 + i, "  ");
		mvprintw(h - 8 + sel, w - 24 + i, "  ");
		mvprintw(h - 7 + sel, w - 24 + i, "  ");
		mvprintw(h - 6 + sel, w - 24 + i, "  ");
	}
	mvprintw(h - 7 + sel, w - 24, "                     %s                    ", men[me]);
}

int Menu::select() {
	int ch;
	while ((ch = getch())){
		if (ch == 258) {
			clean(numberMenu, w, h);
			setNumberMenu(numberMenu + 1);
			draw(numberMenu, w, h);
		}
		else if (ch == 259) {
			clean(numberMenu, w, h);
			setNumberMenu(numberMenu - 1);
			draw(numberMenu, w, h);
		}
		else if (ch == 10)
			return (numberMenu + 1);
		else if (ch == 27)
			exit(0);
		erase();
		drawMenu();
	}
	return (numberMenu);
}

int Menu::getNumberMenu() const {
	return numberMenu;
}

void Menu::setNumberMenu(int numberMenu) {
	if (numberMenu > 2)
		Menu::numberMenu = 0;
	else if (numberMenu < 0)
		Menu::numberMenu = 2;
	else
		Menu::numberMenu = numberMenu;
}
