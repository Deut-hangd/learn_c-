#include <iostream>
#include <memory>
using std:: cout;
using std:: cin;
using std:: endl;
using std:: auto_ptr;


template<class T>
class AutoPtr
{
    public:
    // 默认构造函数
    AutoPtr(T* ptr = NULL)
    :_ptr(ptr)
    {}

    // 析构函数
    ~AutoPtr()
    {
        if (_ptr)
        {
            delete _ptr;
            _ptr = NULL;
        }
    }

    // 拷贝构造函数
    AutoPtr(AutoPtr<T> &ap)
    :_ptr(ap._ptr)
    {
        ap._ptr = NULL;
    }

    AutoPtr<T>& operator= (AutoPtr<T> &ap)
    {
        // 检测是否是自己给自己赋值
        if (this != &ap)
        {
            // 释放当前对象中的资源
            if (_ptr)
            {
                delete _ptr;
            }
            // 将对象ap中的资源转移到当前对象中
            _ptr = ap.ptr;
            ap.ptr = NULL;
        }
        return *this;
    }

    T& operator* ()
    {
        return *_ptr;
    }

    T* operator-> ()
    {
        return _ptr;
    }

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

