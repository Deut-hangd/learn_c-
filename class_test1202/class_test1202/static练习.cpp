#include "head.h"

class A
{
public:
	A(){ ++_scount; }
	A(const A& a) { ++_scount; }
	int GetCount()
	{
		return _scount;
	}
	static int GetACount() 
	{
		return _scount;
	}

public:
	static int _scount;
	int _count;
};

int A::_scount;

int m15()
{
	cout << A::GetACount() << " " << A::_scount << endl;
	A a;
	A a1(a);
	cout << A::GetACount() << " " << A::_scount << endl;
	system("pause");
	return 0;
}