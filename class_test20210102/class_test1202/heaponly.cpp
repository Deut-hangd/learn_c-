#include "head.h"

class HeapOnly
{
public:
	static HeapOnly* CreatObject()
	{
		return new HeapOnly;
	}

private:
	HeapOnly() {}

	// ֻ����, ��ʵ��. ��Ϊ�ò���.
	HeapOnly(const HeapOnly&);
};

class StackOnly
{
public:
	static StackOnly CreatObject()
	{
		return StackOnly();
	}
private:
	StackOnly(){}
};

