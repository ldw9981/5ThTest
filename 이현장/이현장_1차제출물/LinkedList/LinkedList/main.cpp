#include "LinkedList.h"


int main()
{
	LinkedList<int>* samplelist = new LinkedList<int>();

	// 임의적으로 뒤에서 추가해서 넣엇습니다.
	for (int i = 0; i < 10; i++)
	{
		samplelist->Push_Back(i);
	}

	samplelist->PrintAll();

	std::cout << std::endl;

	// 전방 삭제 
	for (int i = 0; i < 5; i++)
	{
		samplelist->Pop_Front();
	}

	samplelist->PrintAll();

	//전방 추가
	for (int i = 0; i < 3; i++)
	{
		samplelist->Push_Front(i);
	}

	std::cout << std::endl;
	samplelist->PrintAll();

	//후방 추가
	for (int i = 10; i < 13; i++)
	{
		samplelist->Push_Back(i);
	}

	std::cout << std::endl;
	samplelist->PrintAll();

	// 후방 삭제
	for (int i = 0; i < 2; i++)
	{
		samplelist->Pop_Back();
	}
	std::cout << std::endl;

	samplelist->PrintAll();

	std::cout << std::endl;
	//중간삽입
	samplelist->Insert(100,100);

	samplelist->PrintAll();

	samplelist->Clear();

	std::cout << std::endl;

	samplelist->PrintAll();
}