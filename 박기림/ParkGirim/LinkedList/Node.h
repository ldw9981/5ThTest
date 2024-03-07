#pragma once

template <typename T>
struct Node
{
	T data;
	Node<T>* prevNode;
	Node<T>* nextNode;
};