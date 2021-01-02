#include "head.h"

template<class T1, class T2>
T2 add(T1& a1, T2& a2)
{
	return a1 + a2;
}


template<class T>
class Vector
{
public:
	Vector(size_t capacity = 10)
		:_pData(new T[_capacity])
		, _size(0)
		, _capacity(capacity)
	{}

	~Vector();

	void PushBack(const T& data);
	void PopBack();

	size_t size()
	{
		return _size;
	}

	T& operator[](size_t pos)
	{
		assert(pos < size_t);
		return _pData[pos];
	}
private:
	T* _pData;
	size_t _size;
	size_t _capacity;
};

template<class T>
Vector<T>::~Vector()
{
	if (_pData)
		delete[] _pData;
	_pData = NULL;
	_size = _capacity = 0;
}
int m22() {
	int a1 = 1, a2 = 2;
	double a3 = 2.0, a4 = 3.0;
	cout << add(a1, a3) << endl;
	//cout << add(a1, a2) << endl;
    //double a3 = 2.0, a4 = 4.0;
	//cout << add(a3, a4) << endl;
	//int a5 = (int)a3;
	//cout << add(a1, a5) << endl;
	system("pause");
	return 0;
}

int m21() {
	Vector<int> v1;
	Vector<double> v2;
	system("pause");
	return 0;
}