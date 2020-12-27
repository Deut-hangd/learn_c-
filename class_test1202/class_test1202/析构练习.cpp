#include "head.h"

class String1
{
public:
	String1(const char* str = "jack")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String1()
	{
		cout << "~String()" << endl;
		free(_str);
		_str = NULL;
	}
private:
	char* _str;
};

class Person
{
public:
	String1 _name = "hello";
	int _age = 0;
};

void Test()
{
	
	Person p;
	printf("%s\n", p._name);
}

int m5()
{
	Test();
	system("pause");
	return 0;
}