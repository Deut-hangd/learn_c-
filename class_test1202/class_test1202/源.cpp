#include "head.h"
class A
{
public:
	A(){}
	A(int id, int age = 1)
	{
		_id = id;
		_age = age;
	}

public:
	int _id;
	int _age;
};

class P
{
public:
	P()
	{
		cout << "this is P" << endl;
		_id = 0;
		_age = 0;
	}

public:
	int _id;
	int _age;
};

class C
{
public:
	C()
	{
		cout << "this is C" << endl;
	}
public:
	int _id;
	int _age;
	P _p;
};

int m1()
{
	C c;
	system("pause");
	return 0;
}