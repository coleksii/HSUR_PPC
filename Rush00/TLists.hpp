#ifndef TLISTS_HPP
# define TLISTS_HPP

#include "TListNode.hpp"

template <class T>
class	TList {
public:
	TList();
	~TList();
	bool addNode(T);
	bool removeNode();
protected:
	TListNode<T> *start;
	TListNode<T> *end;
};

template <class T>
TList<T>::TList() : start(nullptr), end(nullptr) {}
template <class T>
TList<T>::~TList() {}

template <class T>
bool TList<T>::addNode(T&data) {
	TListNode<T> node = new <T>;
	node = data;
	if (start == nullptr)
		start = node;
	return false;
}

#endif
