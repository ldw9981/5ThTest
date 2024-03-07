#pragma once

#include <algorithm>
#include <cassert>

template <typename T>
struct Node
{
	T _data;
	Node<T>* _prev = nullptr;
	Node<T>* _next = nullptr;

	Node(const T& data) : _data(std::move(data)) {}
	Node(T&& data) : _data(std::forward<T>(data)) {}

	template <typename... Args>
	Node(Args&&... args) : _data(std::forward<Args>(args)...) {}
};

template <typename T>
class List
{
public:
	class Iterator
	{
	public:
		Iterator(Node<T>* node, Node<T>* head) : _node(node), _head(head) {}

		T& operator*() const
		{
			return _node->_data;
		}

		T* operator->() const
		{
			return &_node->_data;
		}

		Iterator operator++(int)
		{
			assert(_node != _head); // end iterator increment

			Iterator temp = *this;
			_node = _node->_next;
			return temp;
		}

		Iterator operator--(int)
		{
			assert(_node->_prev != _head); // begin iterator decrement

			Iterator temp = *this;
			_node = _node->_prev;
			return temp;
		}

		bool operator==(const Iterator& rhs) const
		{
			return _node == rhs._node;
		}

		bool operator!=(const Iterator& rhs) const
		{
			return _node != rhs._node;
		}

	private:
		Node<T>* _node;
		Node<T>* _head;

		friend class List;
	};

	List()
	{
		_head = (Node<T>*)malloc(sizeof(Node<T>));

		_head->_next = _head;
		_head->_prev = _head;
	}

	~List()
	{
		clear();
		free(_head);
	}

	void push_back(T&& value)
	{
		Node<T>* newNode = new Node{ std::forward<T>(value) };

		newNode->_next = _head;
		newNode->_prev = _head->_prev;

		_head->_prev->_next = newNode;
		_head->_prev = newNode;

		_size++;
	}

	template <typename... Args>
	T& emplace_back(Args&&... args)
	{
		Node<T>* newNode = new Node<T>{ std::forward<Args>(args)... };
		

		newNode->_next = _head;	
		newNode->_prev = _head->_prev;

		_head->_prev->_next = newNode;
		_head->_prev = newNode;

		_size++;

		return newNode->_data;
	}


	Iterator insert(const Iterator& pos, T&& value)
	{
		assert(pos._head == _head); // check iterator from this container

		Node<T>* newNode = new Node{ std::forward<T>(value) };

		newNode->_next = pos._node->_next;
		newNode->_prev = pos._node;

		pos._node->_next->_prev = newNode;
		pos._node->_next = newNode;

		_size++;

		return Iterator{ pos._node->_next, _head };
	}

	Iterator insert(const Iterator& pos, const T& value)
	{
		assert(pos._head == _head); // check iterator from this container

		Node<T>* newNode = new Node{ value };

		newNode->_next = pos._node->_next;
		newNode->_prev = pos._node;

		pos._node->_next->_prev = newNode;
		pos._node->_next = newNode;

		_size++;

		return Iterator{ pos._node->_next, _head };
	}

	Iterator insert(const Iterator& pos, size_t count, const T& value)
	{
		assert(pos._head == _head); // check iterator from this container

		for (size_t i = 0; i < count; i++)
		{
			insert(pos, value);
		}

		return Iterator{ pos._node, _head };
	}

	Iterator erase(const Iterator& pos)
	{
		assert(pos._head == _head); // check iterator from this container

		pos._node->_prev->_next = pos._node->_next;
		pos._node->_next->_prev = pos._node->_prev;

		_size--;
		Iterator current{ pos._node->_next, _head };

		delete pos._node;

		return current;
	}

	Iterator erase(const Iterator& first, const Iterator& last)
	{
		// todo : operator overloading < and <=
	}

	bool empty()
	{
		return _size == 0;
	}

	void clear()
	{
		Node<T>* current = _head->_next;

		while (current != _head)
		{
			Node<T>* next = current->_next;
			delete current;
			current = next;
		}

		_size = 0;
		_head->_next = _head;
		_head->_prev = _head;
	}

	Iterator begin()
	{
		return Iterator{ _head->_next, _head };
	}

	Iterator end()
	{
		return Iterator{ _head, _head };
	}

private:
	Node<T>* _head = nullptr;
	size_t _size = 0;
};