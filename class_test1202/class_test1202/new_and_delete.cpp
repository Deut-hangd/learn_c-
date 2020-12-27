#include "head.h"

class Test
{
public:
	Test()
		:_data(0)
	{
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}


public:
	int _data;
};


int m17()
{
	Test t;
	cout << t._data << endl;
	system("pause");
	return 0;
}