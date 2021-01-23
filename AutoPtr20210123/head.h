#include <iostream>
#include <memory>
using std:: cout;
using std:: cin;
using std:: endl;


template<class T>
class AutoPtr
{
    public:
    AutoPtr(T* ptr = NULL)
    :_ptr(ptr)
    {}



    private:
    T* _ptr;
};

class Date
{

    public:
    Date()
    :_year(0)
    ,_month(0)
    ,_day(0)
    {cout << "Date()" << endl;}

    ~Date(){cout << "~Date()" << endl;}

    
    int _year;
    int _month;
    int _day;
};

