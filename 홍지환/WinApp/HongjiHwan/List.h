#pragma once
#include <cassert>

template <typename T>
struct Node
{
	T Data;
	Node<T>* Prev;
	Node<T>* Next;
};

template <typename T>
class List
{
public:
	class Iterator
	{
		friend class List;

	public:
		Iterator(Node<T>* raw) : mRaw{ raw } {}

		Iterator& operator++()
		{
			assert(mRaw->Next != nullptr);
			mRaw = mRaw->Next;

			return *this;
		}
		Iterator& operator--()
		{
			assert(mRaw->Prev != nullptr);
			assert(mRaw->Prev->Prev != nullptr);
			mRaw = mRaw->Prev;

			return *this;
		}
		Iterator operator++(int)
		{
			Iterator temp = *this;
			++(*this);

			return temp;
		}
		Iterator operator--(int)
		{
			Iterator temp = *this;
			--(*this);

			return temp;
		}
		T& operator*() const
		{
			return mRaw->Data;
		}
		T* operator->() const
		{
			return &(mRaw->Data);
		}
		bool operator==(const Iterator& rhs)
		{
			return this->mRaw == rhs.mRaw;
		}
		bool operator!=(const Iterator& rhs)
		{
			return !this->operator==(rhs);
		}

	private:
		Node<T>* mRaw;
	};

public:
	List()
		: mHead{}
		, mTail{}
		, mCount{ 0u }
	{
		linkNode(mHead, mTail);
		mHead.Prev = nullptr;
		mTail.Next = nullptr;
	}
	~List()
	{
		Clear();
	}

	// create
	void PushBack(const T& data)
	{
		Node<T>* newNode = new Node<T>();
		Node<T>* prevNode = mTail.Prev;

		newNode->Data = data;
		++mCount;

		linkNode(*prevNode, *newNode);
		linkNode(*newNode, mTail);
	}
	void PushFront(const T& data)
	{
		Node<T>* newNode = new Node<T>();
		Node<T>* nextNode = mHead.Next;

		newNode->Data = data;
		++mCount;

		linkNode(mHead, *newNode);
		linkNode(*newNode, *nextNode);
	}
	Iterator Insert(Iterator iter, const T& data)
	{
		Node<T>* newNode = new Node<T>();
		Node<T>* nextNode = iter.mRaw->Next;

		newNode->Data = data;
		++mCount;

		linkNode(*iter.mRaw, *newNode);
		linkNode(*newNode, *nextNode);

		return Iterator(newNode);
	}

	// delete
	void PopBack()
	{
		assert(mCount > 0);

		Node<T>* deleteNode = mTail.Prev;
		Node<T>* prevNode = deleteNode->Prev;

		delete deleteNode;
		--mCount;

		linkNode(*prevNode, mTail);
	}
	void PopFront()
	{
		assert(mCount > 0);

		Node<T>* deleteNode = mHead.Next;
		Node<T>* nextNode = deleteNode->Next;

		delete deleteNode;
		--mCount;

		linkNode(mHead, *nextNode);
	}
	Iterator Erase(Iterator iter)
	{
		Node<T>* deleteNode = iter.mRaw;
		Node<T>* prevNode = deleteNode->Prev;
		Node<T>* nextNode = deleteNode->Next;

		delete deleteNode;
		--mCount;

		linkNode(*prevNode, *nextNode);

		return Iterator(nextNode);
	}
	void Clear()
	{
		Node<T>* nodePtr = mHead.Next;

		while (nodePtr != &mTail)
		{
			Node<T>* deleteNode = nodePtr;
			nodePtr = nodePtr->Next;

			delete deleteNode;
		}

		linkNode(mHead, mTail);
		mCount = 0u;
	};

	// getter
	size_t GetCount() const { return mCount; }
	Iterator Begin() const { return Iterator(mHead.Next); }
	Iterator End() { return Iterator(&mTail); }
	T& Front() const { return mHead.Next->Data; }
	T& Back() const { return mTail.Prev->Data; }

private:
	void linkNode(Node<T>& lhs, Node<T>& rhs)
	{
		lhs.Next = &rhs;
		rhs.Prev = &lhs;
	}

private:
	Node<T> mHead;
	Node<T> mTail;
	size_t mCount;
};