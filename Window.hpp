#ifndef WINDOW_HPP
# define WINDOW_HPP

#include <ncurses.h>
#include <zconf.h>

class Window {
public:
	Window();
	~Window();

	int	keyHook();

///SETTER GETTER
	void setW(int w);
	void setH(int h);
	void setKey(int key);
	int getW() const;
	int getH() const;
	int getKey() const;
protected:
	int w;
	int h;
	int key;
};


#endif
