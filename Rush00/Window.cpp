#include "Window.hpp"

Window::Window() {
	initscr();
	noecho();
	curs_set(0);
	keypad(stdscr, true);
//	halfdelay(1); // getch return -1;
	nodelay(stdscr, true);
	getmaxyx(stdscr, h, w);
}

Window::~Window() {
  	sleep(1);
	endwin();

}

int	Window::keyHook() {
	key = getch();
	if (key == 27)
	{
		werase(stdscr);
		mvprintw(h / 2, w /2 - 4, "%s", "GOOD BYE!");
		return false;
	}
	else
		return key;
}

///SETTER GETTER
void Window::setW(int w) {
	Window::w = w;
}

void Window::setH(int h) {
	Window::h = h;
}

void Window::setKey(int key) {
	Window::key = key;
}

int Window::getW() const {
	return w;
}

int Window::getH() const {
	return h;
}

int Window::getKey() const {
	return key;
}
