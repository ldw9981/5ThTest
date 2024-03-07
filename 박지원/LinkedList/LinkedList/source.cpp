#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
	Node(T input) :data(input) {}
	Node* prevNode = nullptr;
	Node* nextNode = nullptr;
	T data;
};

template <typename T>
class LinkedList
{
public:
	void InsertBack(T input)
	{
		size++;
		if (lastNode)
		{
			Node<T>* temp = new Node<T>(input);
			lastNode->nextNode = temp;
			temp->prevNode = lastNode;
			lastNode = temp;
		}
		else
		{
			lastNode = new Node<T>(input);
			firstNode = lastNode;
		}
	}

	void DeleteBack()
	{
		if (lastNode)
		{
			size--;

			// 한개밖에 없을때 예외처리
			if (firstNode == lastNode)
			{
				delete lastNode;
				firstNode = nullptr;
				lastNode = nullptr;
				return;
			}

			Node<T>* temp = lastNode;
			lastNode = lastNode->prevNode;
			lastNode->nextNode = nullptr;
			delete temp;
		}
	}

	void DeleteFront()
	{
		if (firstNode)
		{
			size--;

			// 한개밖에 없을때 예외처리
			if (firstNode == lastNode)
			{
				delete lastNode;
				firstNode = nullptr;
				lastNode = nullptr;
				return;
			}

			Node<T>* temp = firstNode;
			firstNode = firstNode->nextNode;
			firstNode->prevNode = nullptr;
			delete temp;
		}
	}

	// 중간에 있는거 삭제
	void DeleteByIndex(int n)
	{
		if (n < 0 || n >= size) return;
		if (!firstNode) return;

		Node<T>* temp = firstNode;
		for (int i = 0; i < n; i++) { temp = temp->nextNode; }

		if (temp == firstNode) { DeleteFront(); }
		else if (temp == lastNode) { DeleteBack(); }
		else
		{
			size--;
			temp->prevNode->nextNode = temp->nextNode;
			temp->nextNode->prevNode = temp->prevNode;
			delete temp;
		}
	}

	Node<T>* GetByIndex(int n)
	{
		if (n < 0 || n >= size) return nullptr;
		if (!firstNode) return nullptr;

		Node<T>* temp = firstNode;
		for (int i = 0; i < n; i++) { temp = temp->nextNode; }
		return temp;
	}

	void PrintAll()
	{
		for (Node<T>* i = firstNode; i; i = i->nextNode)
		{
			cout << i->data << " ";
		}
		cout << " [size: " << size << "]" << endl;
	}

private:
	Node<T>* firstNode = nullptr;
	Node<T>* lastNode = nullptr;
	int size = 0;
};

int main()
{
	LinkedList<int> myList;

	myList.InsertBack(10);
	myList.InsertBack(20);
	myList.InsertBack(30);
	myList.InsertBack(40);
	myList.InsertBack(50);
	myList.PrintAll();		//10 20 30 40 50  [size: 5]
	cout << myList.GetByIndex(3)->data << endl;	//4번째에 저장된것 출력

	myList.DeleteFront();	//20 30 40 50  [size: 4]
	myList.PrintAll();

	myList.DeleteByIndex(2);// 3번째에 저장된 40 값을 지움
	myList.PrintAll();		//20 30 50  [size: 3]

	myList.DeleteBack();
	myList.DeleteBack();
	myList.PrintAll();		//20  [size: 1]

	myList.DeleteFront();
	myList.PrintAll();		// [size: 0]

	myList.DeleteBack();	// 비웠을때 지워도 예외처리되어 문제없음
	myList.DeleteFront();

	myList.InsertBack(14);	// 다시 채워도 문제없이 작동
	myList.InsertBack(5);
	myList.PrintAll();		//14 5  [size: 2]
}