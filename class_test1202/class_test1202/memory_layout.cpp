#include "head.h"

void Test01()
{
	// C�����ж�̬�ڴ����ʽ
	int* p1 = (int*)malloc(sizeof(int) * 4);
	free(p1);
	int* p2 = (int*)calloc(4, sizeof(int));

	int* p3 = (int*)realloc(p2, sizeof(int) * 4);
	free(p3);
	cout << p2 << endl;
	cout << p3 << endl;
}

void Test02()
{
	// new �� delet������������

	// ��̬����һ��int���͵Ŀռ�
	int* ptr4 = new int;

	// ��̬����һ��int���͵Ŀռ�, ����ʼ��Ϊ10
	int* ptr5 = new int(10);

	// ��̬����10��int���͵Ŀռ�
	int* ptr6 = new int[10];

	int n = 10;
	int* ptr7 = new int[n];
	ptr6[0] = 1;
	ptr6[1] = 2;
	ptr6[2] = 3;

	cout << sizeof(ptr4) / sizeof(ptr4[0]) << endl;
	cout << sizeof(ptr5) / sizeof(ptr5[0]) << endl;
	cout << *ptr5 << endl;
	cout << ptr6[0] << ptr6[1] << ptr6[2] << endl;
	cout << sizeof(ptr6) / sizeof(ptr6[0]) << endl;

	delete ptr4;
	delete ptr5;
	delete[] ptr6;

}

int m16()
{
	//Test01();
	Test02();
	system("pause");
	return 0;
}