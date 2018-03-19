#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <iomanip>

template  <class T>
class TListNode {
public:
	TListNode();
	~TListNode();
	void setPrev(TListNode<T> *prev);
	void setNext(TListNode<T> *next);
	void setData(T data);
	TListNode<T> *getPrev() const;
	TListNode<T> *getNext() const;
	T getData() const;
private:
	TListNode *prev;
	TListNode *next;
	T data;
};

template  <class T>
TListNode<T>::TListNode() : prev(nullptr), next(nullptr), data(nullptr) {}

template  <class T>
TListNode<T>::~TListNode() {}

template <class T>
void TListNode<T>::setPrev(TListNode<T> *prev) {
	TListNode<T>::prev = prev;
}

template <class T>
void TListNode<T>::setNext(TListNode<T> *next) {
	TListNode<T>::next = next;
}

template <class T>
void TListNode<T>::setData(T data) {
	TListNode<T>::data = data;
}

template <class T>
TListNode<T> *TListNode<T>::getPrev() const {
	return prev;
}

template <class T>
TListNode<T> *TListNode<T>::getNext() const {
	if (next != nullptr)
		return next;
	else
		return nullptr;
}

template <class T>
T TListNode<T>::getData() const {
	if (data != nullptr)
		return data;
	return nullptr;
}

#endif
