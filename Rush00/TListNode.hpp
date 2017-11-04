#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <iomanip>

///HEADER
template  <class T>
class TListNode {
public:
	TListNode(T);
	~TListNode();
protected:
	T *prev;
	T *next;
	T data;
};
#endif
