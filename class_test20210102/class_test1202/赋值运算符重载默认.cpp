#include "head.h"

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

public:
	int _year;
	int _month;
	int _day;
};

class String
{
public:

	const char* getStr() const
	{
		return _str;
	}

	String& operator=(const String& str)
	{
		if (this != &str)
		{
			if (_str != NULL)
			{
				free(_str);
				_str = NULL;
			}
			_str = (char*)malloc(strlen(str._str) + 1);
			strcpy(_str, str._str);
			return *this;
		}
		return *this;
	}

	String(const char* str = "")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		free(_str);
		_str = NULL;
	}

private:
	char* _str;
};

int m7()
{
	Date d1;
	Date d2(2020, 12, 2);
	d1 = d2;
	cout << &d1 << " " << &d2 << endl;
	cout << d1._year << " " << d1._month << " " << d1._day << endl;

	String s1("hello");
	String s2("word");
	s1 = s2;
	const char* s3 = s1.getStr();
	cout << *s3 << endl;
	cout << *(s3 + 1) << endl;
	system("pause");
	return 0;

}