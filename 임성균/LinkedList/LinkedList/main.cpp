#include <list>
#include <iostream>
using namespace std;

/// <summary>
/// ������ �ȳ� �� �ñ״�ó�� �����ϱ� ���� �������
/// </summary>
/// <returns></returns>

int main()
{
	std::list<int> li;
	std::list<int>::const_iterator citr;
	const int& val= 10;

	li.insert(citr, val);

	li.clear();
}