#ifndef TLISTS_HPP
# define TLISTS_HPP

#include "TListNode.hpp"

template <class T>
class	TList {
public:
	TList();
	~TList();
	void addNode(T data);
	T removeNode(TListNode<Bullet *> *ptr);
	TListNode<T> *getStart() const;
	void setStart(TListNode<T> *start);
	TListNode<T> *getTail() const;
	void setTail(TListNode<T> *tail);
private:
	TListNode<T> *start, *tail;
};

template <class T>
TList<T>::TList() : start(nullptr), tail(nullptr) {}

template <class T>
TList<T>::~TList() {}

template <class T>
void TList<T>::addNode(T data) {
	if (data != nullptr)
	{
		if (start == nullptr) {
			start =  new TListNode<T>;
			start->setPrev(nullptr);
			start->setNext(nullptr);
			start->setData(data);
			tail = start;
			tail->setPrev(start);
		} else {
			TListNode<T> *tmp = new TListNode<T>;
			tmp->setData(data);
			tmp->setNext(nullptr);
			tmp->setPrev(tail);
			tail->setNext(tmp);
			tail = tmp;
		}
	}
}

template <class T>
T TList<T>::removeNode(TListNode<Bullet *> *ptr) {
	if (ptr->getPrev() != nullptr && ptr->getNext() != nullptr) {
		ptr->getPrev()->setNext(ptr->getNext());
		ptr->getNext()->setPrev(ptr->getPrev());
	}
	else if (ptr->getPrev() != nullptr) {
		ptr->getPrev()->setNext(nullptr);
		start = ptr->getNext();
		if (start != nullptr)
		start->setPrev(nullptr);
	}else if (ptr->getNext() != nullptr) {
		ptr->getNext()->setPrev(nullptr);
		tail = ptr->getPrev();
		tail->setNext(nullptr);
	}
	return ptr->getData();
}

template <class T>
TListNode<T> *TList<T>::getStart() const {
	return start;
}

template <class T>
void TList<T>::setStart(TListNode<T> *start) {
	TList<T>::start = start;
}

template <class T>
TListNode<T> *TList<T>::getTail() const {
	return tail;
}
template <class T>
void TList<T>::setTail(TListNode<T> *tail) {
	TList<T>::tail = tail;
}

#endif
