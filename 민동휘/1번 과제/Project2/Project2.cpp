#include <vector>
#include <iostream>
#include <string.h>


struct Node
{
    const char* name;
    Node* headNode;
    Node* tailNode;
};

class LinkedList
{
public:
    Node* CreateNode(const char* name);
    void PushNode(Node* node);
    void ShowNode();
    void CutNode(Node* node);
    void Finalize();

public:
    std::vector<Node*> m_nodes;
};


template <class T>
void LinkNode(T a, T b)
{

}
template <>
void LinkNode(Node* a, Node* b)
{
    a->tailNode = b;
    b->headNode = a;
}


int main()
{
    LinkedList linkedList;
    
    Node* node1 = linkedList.CreateNode("node1");
    Node* node2 = linkedList.CreateNode("node2");
    Node* node3 = linkedList.CreateNode("node3");

    LinkNode(node1, node2);
    LinkNode(node2, node3);

    linkedList.PushNode(node1);
    linkedList.PushNode(node2);
    linkedList.PushNode(node3);

    linkedList.ShowNode();

    Node* node4 = linkedList.CreateNode("node4");
    LinkNode(node3, node4);
    linkedList.PushNode(node4);
    linkedList.CutNode(node3);

    linkedList.ShowNode();

    int a = 0;
    std::cin >> a;
}

Node* LinkedList::CreateNode(const char* name)
{
    Node* node = new Node;
    node->headNode = nullptr;
    node->tailNode = nullptr;
    node->name = name;
    return node;
}

void LinkedList::PushNode(Node* node)
{
    m_nodes.push_back(node);
}

void LinkedList::ShowNode()
{
    for (auto e : m_nodes)
    {
        if (e->headNode == nullptr && e->tailNode == nullptr)
            continue;
        else if (e->headNode == nullptr && e->tailNode != nullptr)
        {
            std::cout << e->name << " is HeadNode. " << e->name << "'s TailNode : " << e->tailNode->name << std::endl;
        }
        else if (e->tailNode == nullptr && e->headNode != nullptr)
        {
            std::cout << e->name << "'s HeadNode : " << e->headNode->name << " " << e->name << " is TailNode." << std::endl;
        }
        else
        {
            std::cout << e->name << "'s HeadNode : " << e->headNode->name << " " << e->name << "'s TailNode : " << e->tailNode->name << std::endl;
        }
    }
}

void LinkedList::CutNode(Node* node)
{
    node->headNode->tailNode = node->tailNode;
    node->tailNode->headNode = node->headNode;
    node->headNode = nullptr;
    node->tailNode = nullptr;
    std::cout << node->name << " has deleted." << std::endl;
}

void LinkedList::Finalize()
{
    for (auto e : m_nodes)
    {
        if (e != nullptr)
        {
            delete e;
        }
    }
}
