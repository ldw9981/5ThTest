#include <iostream>
using namespace std;

template<typename T>
class Node
{
public:
	Node(T _data) 
	{ 
		data = _data; 
		nextNode = nullptr;
		prevNode = nullptr;
	}
	~Node() {}
public:
	T data;
	Node<T>* nextNode;
	Node<T>* prevNode;
};

template<typename T>
class MyList
{
public:
	MyList() 
	{
		startNode = new Node<T>(0);
		endNode = new Node<T>(0);
		startNode->prevNode = startNode;
		startNode->nextNode = endNode;
		endNode->prevNode = startNode;
		endNode->nextNode = endNode;
		size = 0;
	}
	~MyList() {}
public:
	Node<T>* startNode;
	Node<T>* endNode;
	int size;

public:
	void push_back(Node<T>* _node)
	{
		AddNode(endNode->prevNode, _node);
	}
	void push(int index ,Node<T>* _node)
	{
		if (size < index)
		{
			cout << " 오류입니다. " << endl;
		}
		Node<T>* TargetNode = startNode;
		for (int i = 0; i < index; i++)
		{
			TargetNode = TargetNode->nextNode;
		}
		AddNode(TargetNode, _node);
	}
	void AddNode(Node<T>* parents, Node<T>* _node)
	{
		_node->nextNode = parents->nextNode;
		_node->prevNode = parents;
		parents->nextNode->prevNode = _node;
		parents->nextNode = _node;

		size++;
	}
	void erase(int index)
	{
		if (size < index)
		{
			cout << " 오류입니다. " << endl;
		}
		Node<T>* TargetNode = startNode;
		for (int i = 0; i < index; i++)
		{
			TargetNode = TargetNode->nextNode;
		}
		TargetNode->prevNode->nextNode = TargetNode->nextNode;
		TargetNode->nextNode->prevNode = TargetNode->prevNode;
		delete TargetNode;
		size--;
	}
	void clear()
	{
		Node<T>* TargetNode = startNode->nextNode;
		for (TargetNode = startNode->nextNode; TargetNode != endNode; )
		{
			Node<T>* tempNextTarget = TargetNode->nextNode;
			delete TargetNode;
			TargetNode = tempNextTarget;
		}
		startNode->nextNode = endNode;
		endNode->prevNode = startNode;
		size = 0;
	}


	void printAll()
	{
		Node<T>* TargetNode = startNode->nextNode;
		for (TargetNode = startNode->nextNode; TargetNode != endNode; TargetNode = TargetNode->nextNode)
			cout << TargetNode->data << " ";
		cout << endl;
	}
	void printAllReverse()
	{
		Node<T>* TargetNode = endNode->prevNode;
		for (TargetNode = endNode->prevNode; TargetNode != startNode; TargetNode = TargetNode->prevNode)
			cout << TargetNode->data << " ";
		cout << endl;
	}
};

int main()
{
	cout << "------list<int> 예시------" << endl;
	MyList<int> myList;
	for (int i = 1; i <= 8; i++)
	{
		cout << "list<int>.push_back("<<i<<")" << endl;
		myList.push_back(new Node<int>(i));
	}
	cout << "list<int>.printAll" << endl;
	myList.printAll();
	cout << "list<int>.printAllReverse" << endl;
	myList.printAllReverse();

	cout << "list<int>.erase(1번째 노드 지우기)" << endl;
	myList.erase(1);
	myList.printAll();

	cout << "list<int>.erase(1번째 노드 지우기)" << endl;
	myList.erase(1);
	myList.printAll();

	cout << "list<int>.push(3번째 노드 다음에 새로운 노드 추가)" << endl;
	myList.push(3, new Node<int>(100));
	myList.printAll();

	cout << "list<int>.erase(5번째 노드 지우기)" << endl;
	myList.erase(5);
	myList.printAll();
	cout << "list<int>.clear" << endl;
	myList.clear();
	myList.printAll();
	//--------------------------------------------------------------------------
	cout << "------list<float>------ 예시" << endl;
	MyList<float> myList2;
	for (int i = 1; i <= 8; i++)
	{
		cout << "list<int>.push_back(" << i / 0.4 << ")" << endl;
		myList2.push_back(new Node<float>(i/0.4));
	}
	cout << "list<float>.printAll" << endl;
	myList2.printAll();
	cout << "list<float>.printAllReverse" << endl;
	myList2.printAllReverse();

	cout << "list<float>.erase(1번째 노드 지우기)" << endl;
	myList2.erase(1);
	myList2.printAll();

	cout << "list<float>.erase(1번째 노드 지우기)" << endl;
	myList.erase(1);
	myList.printAll();

	cout << "list<float>.push(3번째 노드 다음에 새로운 노드 추가)" << endl;
	myList2.push(3, new Node<float>(99.9999));
	myList2.printAll();

	cout << "list<int>.erase(5번째 노드 지우기)" << endl;
	myList2.erase(5);
	myList2.printAll();
	cout << "list<int>.clear" << endl;
	myList2.clear();
	myList2.printAll();

	int a = 0;
	cin >> a;
}