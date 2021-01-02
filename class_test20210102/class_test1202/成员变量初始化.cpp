#include "head.h"

class Time
{

public:
	Time(int hour = 0)
		:_hour(hour)
	{
		cout << "this hour is " << _hour << endl;
	}

private:
	int _hour;
};

class Day
{

public:
	Day(int day = 1)
	{}

private:
	int _day;
	Time _t;
};

int m8()
{
	Day d(2);
	system("pause");
	return 0;
}

class A
{
public:
	A()
		:_n2(0)
		, _n1(_n2 + 1)
	{
		cout << _n1 << " " << _n2 << endl;
	}

	

private:
	int _n1;
	int _n2;
};

int m9()
{
	A a;
	system("pause");
	return 0;
}

class Array
{
public:
	Array(int size)
		:_size(size)
		, _array((int*)malloc(sizeof(int) * (_size + 1)))
	{
		cout << sizeof(_array) / sizeof(_array[0]) << endl;
	}

private:
	int* _array;
	int _size;
};

int m10()
{
	Array array(10);
	system("pause");
	return 0;
}