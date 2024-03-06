#pragma once
template<typename T>
class Mylist
{
private:

	struct Node
	{
		T data;
		Node* nextNode=NULL;
		Node* prevNode = NULL;
		Node(T newdata)
		{
			data = newdata;
			nextNode = NULL;
			prevNode = NULL;
		}
		Node()
		{
			//data = 0;
			nextNode = NULL;
			prevNode = NULL;
		}
	};
	Node* head;	//앞부분
	Node* tail;	//뒷부분	
	Node* fin;	//end 부분
	int num = 0;

    class Myiterator {
        Node* currentNode;
    public:
        Myiterator(Node* node) : currentNode(node) {}

        Myiterator& operator++() 
        {
            currentNode = currentNode->nextNode;
            return *this;
        }
        Myiterator& operator--() 
        {
            currentNode = currentNode->prevNode;
            return *this;
		}

		Node* operator&()                           { return currentNode; }
		T& operator*()                              { return currentNode->data; }
		bool operator !=(const Myiterator& iter)    { return (currentNode != iter.currentNode); }
		bool operator ==(const Myiterator& iter)    { return (currentNode == iter.currentNode); }
	};


public:
	Mylist() 
    {
        head = NULL;
        tail = NULL;
        fin = new Node();
    };
	~Mylist() {};

	void push_back(T data)
	{
		if (num == 0)
		{
			head = new Node(data);
			tail = head;
			head->nextNode = fin;
			head->prevNode = fin;

			fin->prevNode = head;
            fin->nextNode = head;
		}
		else
		{
			tail->nextNode = new Node(data);
			tail->nextNode->prevNode = tail;
			tail = tail->nextNode;
			tail->nextNode = fin;

			fin->prevNode = tail;
		}
		num++;
	}

	void push_front(T data) 
    {
        if (num == 0)
        {
            head = new Node(data);
            tail = head;
            head->nextNode = fin;
            head->prevNode = fin;

            fin->prevNode = head;
            fin->nextNode = head;
        }
        else
        {
            head->prevNode = new Node(data);
            head->prevNode->nextNode = head;
            head = head->prevNode;
            head->prevNode = fin;

            fin->nextNode = head;
        }
        num++;
    }

	void pop_back()
    {
        if (num == 1) 
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else 
        {
            Node* temp = tail->prevNode;
            temp->nextNode = fin;
            fin->prevNode = temp;
            delete tail;
            tail = temp;
        }
        num--;
    }
    void pop_front() 
    {
        if (num == 1) 
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else 
        {
            Node* temp = head->nextNode;
            delete head;
            head = temp;
            head->prevNode = fin;
            fin->nextNode = head;
        }
        num--;
    }
    Myiterator begin() { return Myiterator(head); }
    Myiterator end() { return  Myiterator(fin); }
	Myiterator erase(Myiterator iter)
    {
		Node* temp = &iter;
		Node* returnNode = temp->nextNode;
        temp->prevNode->nextNode = temp->nextNode;
        temp->nextNode->prevNode = temp->prevNode;
		if (temp == head)
            temp->nextNode = head;
		if (temp == tail)
            temp->prevNode = tail;
		delete temp;
        /// 오류 발견하여 수정
        num--;
		return Myiterator(returnNode);
	}


	int size() { return num; }
	bool empty()
	{
		if (num)
			return false;
		else
			return true;
	}


};
