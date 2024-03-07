#pragma once
#include <iostream>

template <typename T>
class Node
{
public:
	T value;
	int count = 0;

	Node<T>* next;
	Node<T>* prev;
};


template <typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

public:
	void Add(T val);
	void Delete(int cnt);
	
	Node<T>* Find(int cnt);

	void PrintAll();

private:
	Node<T>* header;


};

template<typename T>
inline LinkedList<T>::LinkedList()
{
	header = new Node<T>();


}

template<typename T>
inline LinkedList<T>::~LinkedList()
{

}

template<typename T>
inline void LinkedList<T>::Add(T val)
{
	//header->next = header;
	header->value = val;

	header->next = new Node<T>();
	//std::cout << "이전" << std::endl;
	//std::cout << header->value << std::endl;
	//std::cout << header->count << std::endl;

	header->next->count = header->count + 1;

	header->next->prev = header;
	header = header->next;

	//std::cout << "이후" << std::endl;
	//std::cout << header->value << std::endl;
	//std::cout << header->count << std::endl;

	//std::cout << "이전단계" << std::endl;
	//std::cout << header->prev->value << std::endl;
	//std::cout << header->prev->count << std::endl;

}

template<typename T>
inline void LinkedList<T>::Delete(int cnt)
{
	header = header->prev;
	delete header->next;
}

template<typename T>
inline Node<T>* LinkedList<T>::Find(int cnt)
{
	while (1)
	{
		if (!header)
		{
			while (1)
			{
				if (!header->next)
				{
					break;
				}
				header = header->next;

			}
			std::cout << "못 찾음" << std::endl;
			return 0;
		}
		if (header->count == cnt)
		{
			Node<T>* found = header;
			while (1)
			{
				if (!header->next)
				{
					break;
				}
				header = header->next;

			}
			std::cout << found->value << std::endl;
			return found;
		}
		else
		{
			header = header->prev;
		}
	}

}

template<typename T>
inline void LinkedList<T>::PrintAll()
{
	while (1)
	{
		if (!header->prev)
		{
			while (1)
			{
				if (!header->next)
				{
					return;
				}
				std::cout << "순서" << std::endl;
				std::cout << header->count << std::endl;
				std::cout << "값" << std::endl;
				std::cout << header->value << std::endl;
				header = header->next;
			}
		}
		else
		{
			header = header->prev;
		}

	}

}