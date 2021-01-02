#include "head.h"

void Test01()
{
	// C语言中动态内存管理方式
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
	// new 和 delet操作内置类型

	// 动态申请一个int类型的空间
	int* ptr4 = new int;

	// 动态申请一个int类型的空间, 并初始化为10
	int* ptr5 = new int(10);

	// 动态申请10个int类型的空间
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