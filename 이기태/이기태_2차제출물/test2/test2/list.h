#pragma once
#include "assert.h"

namespace my
{

	template <typename T>
	class list
	{
	private:
		struct node
		{
			node(node* next, node* prev, T val)
				:next(next), prev(prev), value(val)
			{}

			node* next;
			node* prev;
			T value;
		};
	public:
		class iterator
		{
			friend class my::list<T>;

		public:
			iterator(list* owner, node* current)
				:owner(owner), current(current), isEnd(false)
			{}

			iterator& operator++()
			{
				assert(current);

				current = current->next;

				return *this;
			}

			bool operator==(const iterator& other)const
			{
				if (this->current == other.current
					&& this->owner == other.owner)
				{
					return true;
				}

				if (this->isEnd && other.isEnd)
				{
					return true;
				}

				return false;
			}

			bool operator!=(const iterator& other)const
			{
				return !(*this == other);
			}

			T& operator*()
			{
				return current->value;
			}

			bool is_end()const
			{
				return (isEnd || current == nullptr);
			}

		private:
			list* owner;
			node* current;
			bool isEnd;
		};

	public:
		list()
			:front(nullptr), back(nullptr), size(0)
		{}
		~list()
		{
			clear();
		}

		void push_back(T val)
		{
			if (size == 0)
			{
				node* tmp = new node(nullptr, nullptr, val);
				front = tmp;
				back = tmp;
			}
			else
			{
				node* tmp = new node(nullptr, back, val);
				back->next = tmp;
				back = tmp;
			}

			++size;
		}

		iterator& erase(iterator& iter)
		{
			assert(!iter.is_end());

			node* tmp = iter.current;
			iter.current = iter.current->next;

			if (tmp->next)
			{
				tmp->next->prev = tmp->prev;
			}
			
			if (tmp->prev)
			{
				tmp->prev->next = tmp->next;
			}
			
			if (tmp == front)
			{
				front = tmp->next;
			}
			else if (tmp == back)
			{
				back = tmp->prev;
			}

			delete tmp;
			

			--size;
			
			// 새로운 iterator를 반환

			return iter;
		}

		iterator begin()
		{
			return iterator(this, front);
		}

		iterator end()
		{
			return iterator(this, nullptr);
		}

		size_t get_size()
		{
			return size;
		}

		void clear()
		{
			size = 0;

			node* tmp = front;

			while (tmp)
			{
				front = front->next;
				delete tmp;
				tmp = front;
			}
		}
		

	private:
		node* front;
		node* back;
		size_t size;
	};


}
