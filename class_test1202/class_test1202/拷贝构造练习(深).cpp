#include "head.h"

class Date
{
public:
	Date(){}

	Date(int year, int month, int day)
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

int m4()
{
	Date d1;
	Date d2(d1);
	cout << &d1 << " " << &d2 << endl;
	system("pause");
	return 0;
}