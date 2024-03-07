#include "LinkedList.h"


int main()
{
	LinkedList<int>* samplelist = new LinkedList<int>();

	// ���������� �ڿ��� �߰��ؼ� �־����ϴ�.
	for (int i = 0; i < 10; i++)
	{
		samplelist->Push_Back(i);
	}

	samplelist->PrintAll();

	std::cout << std::endl;

	// ���� ���� 
	for (int i = 0; i < 5; i++)
	{
		samplelist->Pop_Front();
	}

	samplelist->PrintAll();

	//���� �߰�
	for (int i = 0; i < 3; i++)
	{
		samplelist->Push_Front(i);
	}

	std::cout << std::endl;
	samplelist->PrintAll();

	//�Ĺ� �߰�
	for (int i = 10; i < 13; i++)
	{
		samplelist->Push_Back(i);
	}

	std::cout << std::endl;
	samplelist->PrintAll();

	// �Ĺ� ����
	for (int i = 0; i < 2; i++)
	{
		samplelist->Pop_Back();
	}
	std::cout << std::endl;

	samplelist->PrintAll();

	std::cout << std::endl;
	//�߰�����
	samplelist->Insert(100,100);

	samplelist->PrintAll();

	samplelist->Clear();

	std::cout << std::endl;

	samplelist->PrintAll();
}