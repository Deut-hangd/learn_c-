#include <iostream>
#include <vector>
#include <assert.h>
using std:: cout;
using std:: cin;
using std:: endl; 
using std:: vector;

void Display(vector<int>& v)
{
    assert(!v.empty() && v.size() > 0);

    cout << "The contents of v are: ";
    // 使用迭代器遍历v的内容
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << " " << *it;
    }
    cout << '\n';
}

// 使用正向迭代器遍历vector
void Iterator(vector<int>& v)
{
    assert(!v.empty() && v.size() > 0);

    cout << "The contents of v are: ";
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << " " << *it;
    }
    cout << "\n";

}

void Resize()
{
    // 定义一个vector
    vector<int> v;
    // 获取v的空间大小
    size_t sz = v.capacity();
    cout << "the sz is: " << sz << endl;
    // 向v中添加100个8, 观察其扩容情况
    for (size_t i = 0; i < 100; i++)
    {
        v.push_back(8);
        if (sz != v.capacity())
        {
            sz = v.capacity();
            cout << "the sz is: " << sz << endl;
        }
    }
}

void Reserve()
{
    vector<int> v;
    size_t sz = v.capacity();
    v.reserve(100);

    cout << "The capacity is: ";
    for (size_t i = 0; i < 100; i++)
    {
        v.push_back(8);
        if (sz != v.capacity())
        {
            sz = v.capacity();
            cout << " " << sz;
        }

    }
    cout << '\n';

}

int main()
{
    Reserve();
    return 0;
}

#if 0
int main()
{
    vector<int> v(10);
    Iterator(v);
    return 0;
}

int main()
{
    // 定义并初始化数组a
    int a[] = {16, 2, 34, 3};
      // 创建一个vector实例, 并使用迭代器进行初始化构造
    vector<int> v(a, a + sizeof(a) / sizeof(a[0]));

    return 0;
}
#endif