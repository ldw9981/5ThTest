#include "LinkedList.h"

int main()
{
	LinkedList<int> list;

	list.AddData(2);
	list.AddData(1);
	list.AddData(3);
	list.AddData(5);
	list.AddData(4);
	list.AddData(6);

	list.PrintData();
	
	// �� ���� �����͸� ���� ��
	list.DeleteData(0);
	list.PrintSize();
	list.PrintData();

	// �� ���� �����͸� ���� ��
	list.DeleteData(4);
	list.PrintSize();
	list.PrintData();

	// �߰� �����͸� ���� ��
	list.DeleteData(2);
	list.PrintSize();
	list.PrintData();

	// �߸��� ������ �ε����� �Է��� ��
	list.DeleteData(-1);
	list.DeleteData(10);

}