#include "head.h"

class Date
{
public:
	void Display();
	void Display() const;
	Date(int year = 2020, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
    int _year;
	int _month;
	int _day;
};

void Date::Display()
{
	_year = 2021;
	cout << _year << "-" << _month << "-" << _day << endl;
}

void Date::Display() const
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

int m6()
{
	Date d;
	d.Display();
	const Date d1;
	d1.Display();
	system("pause");
	return 0;
}