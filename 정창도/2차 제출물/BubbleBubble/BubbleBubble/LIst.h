#pragma once

#include <cassert>

namespace Changdo
{

	template <typename T>
	struct Node
	{
		T _data;

		Node<T>* _prev = nullptr;
		Node<T>* _next = nullptr;

		Node(T data) : _data(data) { }
	};

	template <typename T>
	class List
	{
	public:
		class Iterator
		{
		public:
			Iterator(Node<T>* head, Node<T>* ptr) :
				_head(head),
				_ptr(ptr) {}

			T& operator*()
			{
				return _ptr->_data;
			}

			T* operator->()
			{
				return &_ptr->data;
			}

			Iterator& operator++()
			{
				assert(_head != _ptr && "cannot increment end iterator");
				_ptr = _ptr->_next;
				return *this;
			}

			Iterator& operator--()
			{
				assert(_head->_next != _ptr && "cannot decrement begin iterator");
				_ptr = _ptr->_prev;
				return *this;
			}

			bool operator==(const Iterator& rhs)
			{
				return this->_ptr == rhs._ptr;
			}

			bool operator!=(const Iterator& rhs)
			{
				return this->_ptr != rhs._ptr;
			}

			Node<T>* _head;
			Node<T>* _ptr;

		};

		List() : _head(nullptr), _size(0)
		{
			_head = (Node<T>*)malloc(sizeof(Node<T>));
			assert(_head);
			_head->_next = _head;
			_head->_prev = _head;
		}

		~List()
		{
			clear();
			delete _head;
		}

		void clear()
		{
			erase(begin(), end());
		}

		void push_back(T data)
		{
			Node<T>* newNode = new Node<T>(data);
			_head->_prev->_next = newNode;
			newNode->_prev = _head->_prev;
			newNode->_next = _head;
			_head->_prev = newNode;
			++_size;
		}

		template <typename... Ts>
		Iterator emplace_back(Ts... args)
		{
			return emplace(end(), args...);
		}

		template <typename... Ts>
		Iterator emplace(Iterator pos, Ts... args)
		{
			assert(_head == pos._head);

			Node<T>* newNode = new Node<T>(T(args...));
			newNode->_next = pos._ptr;
			newNode->_prev = pos._ptr->_prev;
			pos._ptr->_prev->_next = newNode;
			pos._ptr->_prev = newNode;
			++_size;

			return Iterator{ _head, newNode };
		}

		Iterator Insert(Iterator pos, T data, size_t count = 1)
		{
			Iterator ret{ nullptr, nullptr };

			while (count)
			{
				Node<T>* newNode = new Node<T>(data);
				newNode->_next = pos._ptr;
				newNode->_prev = pos._ptr->_prev;
				pos._ptr->_prev->_next = newNode;
				pos._ptr->_prev = newNode;
				if (ret._ptr == nullptr)
				{
					ret._head = _head;
					ret._ptr = newNode;
				}
				count--;
				_size++;
			}

			return ret;

		}

		Iterator erase(Iterator pos)
		{
			assert(pos._ptr != pos._head && "cannot erase end iterator");
			Iterator next{ _head, pos._ptr->_next };
			pos._ptr->_next->_prev = pos._ptr->_prev;
			pos._ptr->_prev->_next = pos._ptr->_next;
			delete pos._ptr;
			--_size;

			return next;
		}

		Iterator erase(Iterator first, Iterator last)
		{
			assert(first._head == last._head && "both iterator is in same list");

			bool isValid = false;
			Iterator temp = first;
			Iterator ret{ nullptr, nullptr };
			if (last == end())
			{
				isValid = true;
				temp = end();
			}
			while (temp != end())
			{
				if (temp == last)
				{
					isValid = true;
				}
				++temp;
			}
			temp = first;
			if (isValid == false)
			{
				return ret;
			}
			while (temp != last)
			{
				ret = erase(temp);
				temp = ret;
			}

			return ret;

		}

		template <typename Pred>
		Iterator find_if(Iterator first, Iterator last, Pred pred) 
		{
			assert(first._head == last._head && "both iterator is in same list");

			bool isValid = false;
			Iterator temp = first;
			Iterator ret{ nullptr, nullptr };
			if (last == end())
			{
				isValid = true;
				temp = end();
			}
			while (temp != end())
			{
				if (temp == last)
				{
					isValid = true;
				}
				++temp;
			}
			temp = first;
			if (isValid == false)
			{
				return end();
			}
			while (temp != last)
			{
				if (pred(*temp))
				{
					return temp;
				}
				++temp;
			}
			return end();

		}

		Iterator begin()
		{
			Iterator iter{ _head, _head->_next };
			return iter;
		}

		Iterator end()
		{
			Iterator iter{ _head, _head };
			return iter;
		}


	private:
		Node<T>* _head;
		size_t _size;

	};
}