#pragma once
#include "Node.h"

template <typename T>
class LinaIter
{
public:
	Node<T>* current;

	LinaIter(Node<T>* node = 0) : current(node) {};

	LinaIter& operator++()
	{
		current = current->next;
		return *this;
	}

	LinaIter& operator--()
	{
		current = current->prev;
		return *this;
	}

	bool operator!=(const LinaIter& i)
	{
		return (current != i.current);
	}

	Node<T>* operator&()
	{
		return current;
	}

	T& operator*()
	{
		return current->data;
	}

	bool operator==(const LinaIter& i)
	{
		return (current == i.current);
	}
};

