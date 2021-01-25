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
    // Ĭ�Ϲ��캯��
    AutoPtr(T* ptr = NULL)
    :_ptr(ptr)
    {}

    // ��������
    ~AutoPtr()
    {
        if (_ptr)
        {
            delete _ptr;
            _ptr = NULL;
        }
    }

    // �������캯��
    AutoPtr(AutoPtr<T> &ap)
    :_ptr(ap._ptr)
    {
        ap._ptr = NULL;
    }

    AutoPtr<T>& operator= (AutoPtr<T> &ap)
    {
        // ����Ƿ����Լ����Լ���ֵ
        if (this != &ap)
        {
            // �ͷŵ�ǰ�����е���Դ
            if (_ptr)
            {
                delete _ptr;
            }
            // ������ap�е���Դת�Ƶ���ǰ������
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

