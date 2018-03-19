#include "NLO.hpp"

NLO::NLO(int x, int y, int maxX,int maxY) : posX(x), posY(y), maxX(maxX), maxY(maxY)  {}

NLO::~NLO() {}

NLO::NLO() : posX(0), posY(0), maxX(0), maxY(0) {}

NLO &NLO::operator=(NLO const & src) {
	this->posX = src.posX;
	this->posY = src.posY;
	this->maxX = src.maxX;
	this->maxY = src.maxY;
	return (*this);
}

NLO::NLO(NLO const &src) {
	*this = src;
}


int NLO::getPosX() const {
	return posX;
}

void NLO::setPosX(int posX) {
	NLO::posX = posX;
}

int NLO::getPosY() const {
	return posY;
}

void NLO::setPosY(int posY) {
	NLO::posY = posY;
}

int NLO::getMaxX() const {
	return maxX;
}

void NLO::setMaxX(int maxX) {
	NLO::maxX = maxX;
}

int NLO::getMaxY() const {
	return maxY;
}

void NLO::setMaxY(int maxY) {
	NLO::maxY = maxY;
}

