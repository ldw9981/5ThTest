#include <iostream>
#include "LinekdList.h"
using namespace std;

template<typename T>
LinkedList<T>::LinkedList()
    : head(nullptr)
    , tail(nullptr)
    , count(0)
{

}

template<typename T>
LinkedList<T>::~LinkedList()
{
}

//새로운 값은 언제나 가장 뒤에 추가되도록 한다.
template<typename T>
int LinkedList<T>::Add(T _data, T _data2)
{
    //먼저 새 노드를 만들어준다.
    Node<T>* newNode = new Node<T>();

    //만든 노드에 대해 값을 할당하고 초기화도 해준다.
    newNode->data1 = _data;
    newNode->data2 = _data2;
    newNode->pNode = nullptr;
    newNode->nNode = nullptr;

    //만약 처음 추가하는거면
    if (count == 0)
    {
        head = newNode;
        tail = newNode;
    }

    //가 아니면 tail에 새로운 값 넣어주기
    else
    {
        //tail의 next는 이제 newNode의 값이 된다
        tail->nNode = newNode;
        //newNode의 이전값은 tail이 된다.
        newNode->pNode = tail;
        //newNode가 tail이 된다.
        tail = newNode;
    }

    //추가가 되었으니 count++
    count++;
    cout << _data << "와 " << _data2 << "의 값을 가진 노드가 추가되었습니다.\n";

    return count;
}

template<typename T>
int LinkedList<T>::Delete(T _data, T _data2)
{
    //삭제할 노드가 있는지 search를 이용합시다.
    Node<T>* deleteNode = Search(_data, _data2);

    if (deleteNode == nullptr)
        cout << "삭제 가능한 노드가 없습니다!" << endl;

    //삭제할 노드를 찾았으면
    else
    {
        //노드가 빠지는 부분에 대해 앞뒤로 다시 잘 연결해줘야 함.
        if (deleteNode->pNode)
            deleteNode->pNode->nNode = deleteNode->nNode;
        //앞선 노드가 없다면 이게 head임. head를 다시 지정해주어야 함.
        else
            head = deleteNode->nNode;
        
        if (deleteNode->nNode)
            deleteNode->nNode->pNode = deleteNode->pNode;
        //뒤의 노드가 없다면 이게 tail임. Tail을 다시 지정해줘야 함.
        else
            tail = deleteNode->pNode;

        //연결이 끝났다면 삭제 후 카운트 다운
        cout << _data << "와 " << _data2 << "의 값을 가진 노드가 삭제되었습니다.\n";
        delete deleteNode;
        count--;
    }

    return count;
}

template<typename T>
Node<T>* LinkedList<T>::Search(T _data, T _data2)
{
    //순회하면서 원하는 값을 찾자.
    Node<T>* nowNode = head;

    //만약 리스트가 비어있다면
    if (count == 0)
        cout << "리스트가 비어있습니다!" << endl;

    else
    {
        while (nowNode)
        {
            //찾으면
            if(nowNode->data1 == _data && nowNode->data2 == _data2)
            {
                return nowNode;
            }

            nowNode = nowNode->nNode;
        }
    }
   
    return nullptr;
}

template<typename T>
void LinkedList<T>::ShowAll()
{
    //순회하면서 모든 노드의 값을 보여주면 된다.
    //시작은 머리에서 부터
    Node<T>* nowNode = head;

    //list가 비어있다면
    if (count == 0)
        cout << "리스트가 비어있습니다!" << endl;

    //비어있지 않다면 순회하자!
    else
    {
        cout << "Show All Node : \n";
        while (nowNode)
        {
            //출력하고 다음노드로
            cout << nowNode->data1 << ", " << nowNode->data2 << " \n";
            
            nowNode = nowNode->nNode;
        }
        cout << "\n";
    }
}

template<typename T>
void LinkedList<T>::Clear()
{
    //모든 노드를 순회하면서 삭제시켜준다.
    Node<T>* nowNode = head;

    if (count == 0)
        cout << "이미 리스트가 비어있습니다!" << endl;

    else
    {
        while (nowNode)
        {
            Node<T>* deleteNode = nowNode;

            //삭제할때도 연결을 잘 확인하면서 가야함.
            //노드가 빠지는 부분에 대해 앞뒤로 다시 잘 연결해줘야 함.
            if (nowNode->pNode)
                nowNode->pNode->nNode = nowNode->nNode;
            
            if (nowNode->nNode)
                nowNode->nNode->pNode = nowNode->pNode;
           

            //연결이 끝났다면 다음으로 간 다음
            nowNode = nowNode->nNode;

            // 삭제 후 카운트 다운
            delete deleteNode;
            count--;
        }

        //기본값 초기화
        head = nullptr;
        tail = nullptr;
        count = 0;

        cout << "리스트가 초기화 되었습니다!" << endl;
    }

}
