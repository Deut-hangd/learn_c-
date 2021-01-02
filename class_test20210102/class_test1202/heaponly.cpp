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

	// 只声明, 不实现. 因为用不到.
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

