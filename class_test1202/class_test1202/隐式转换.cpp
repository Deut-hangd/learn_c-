#include "head.h"

class Date
{
public:
	/*Date(int time)
		:_time(time)
	{}*/

    explicit Date(int time)
		:_time(time)
	{}

private:
	int _time;
};

int m11()
{
	Date d(12);
	/*d = 2019;*/
	system("pause");
	return 0;
}