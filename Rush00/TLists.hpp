#ifndef TLISTS_HPP
# define TLISTS_HPP

#include "TListNode.hpp"

template <class T>
class	TList {
public:
	TList();
	~TList();
	bool addNode();
	bool removeNode();

protected:
	TListNode<T> *start;
	TListNode<T> *end;
};

TList<T>::TList() : start(nullptr), end(nullptr) {}
TList<T>::~TList() {}

template <class T>
bool TList<T>::addNode() {
	<T> node = new <T>;
	if (start == nullptr)
		start = node;
	return false;
}

#endif
