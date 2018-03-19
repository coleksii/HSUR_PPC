#include "Fps.hpp"


Fps::Fps() : current(0), old(0), delta(0), fps(0) {}

Fps::~Fps() {}

Fps &Fps::operator=(Fps const & src) {
	this->current = src.current;
	this->old = src.old;
	this->delta = src.delta;
	this->fps = src.fps;
	return (*this);
}

Fps::Fps(Fps const &src) {
	*this = src;
}

void	Fps::smooth_delta()
{
	current = (current * SMOOTH) + (old) * (1.0 - SMOOTH);
}

void	Fps::calcFps() {
	old = current;
	current = clock();
	smooth_delta();
	delta = ((current - old) / CLOCKS_PER_SEC);
	fps = (int)(1 / delta);
	if (fps > 100)
		fps = 100;
	mvprintw(0, 0, "FPS: %d", fps);refresh();

}

bool		Fps::counter(int *storage, int limit)
{
	*storage += fps;
	if (*storage >= limit)
	{
		*storage = 0;
		return (true);
	}
	else
		return (false);
}

int Fps::getFps() const {
	return fps;
}

double Fps::getCurrent() const {
	return current;
}

void Fps::setCurrent(double current) {
	Fps::current = current;
}

double Fps::getOld() const {
	return old;
}

void Fps::setOld(double old) {
	Fps::old = old;
}

double Fps::getDelta() const {
	return delta;
}

void Fps::setDelta(double delta) {
	Fps::delta = delta;
}
