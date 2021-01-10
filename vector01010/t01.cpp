#include <iostream>
#include <vector>
#include <algorithm>
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

void Recapacity()
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

void Pop()
{
    int a[] = {1, 2, 3, 4};
    // 定义一个vector, 并使用a进行初始化
    vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
    // 正向遍历向量v
    Iterator(v);
    // 尾删一个数据
    v.pop_back();
    // 正向遍历向量v
    Iterator(v);
}

void Resize()
{
    vector<int> v;
    // 插入10个数据
    for (size_t i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    v.resize(5);  // 重新定义数据个数为5, 即size为5, 若原size大于指定size, 则多余部分数据删除, capacity不变
    cout << "size: " << v.size() << " " << "capacity: " << v.capacity() << endl;
    Iterator(v);
    v.resize(8, 15);  // 重新定义数据个数为8, 即size为8, 若原size小于指定size, 则超出部分用15初始化, capacity不变
    cout << "size: " << v.size() << " " << "capacity: " << v.capacity() << endl;
    Iterator(v);
    v.resize(15);  // 重新定义数据个数为15, 若原size小于指定size, 则超出部分默认用0初始化
    cout << "size: " << v.size() << " " << "capacity: " << v.capacity() << endl;

    Iterator(v);
}

void Find()
{
    int a[] = {1, 2, 3, 5};
    vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
    // 查找值为5的数据位置
    vector<int>:: iterator pos = find(v.begin(), v.end(), 5);
    // 在值为5的数据位置前插入数据4
    pos = v.insert(pos, 4);
    v.insert(pos + 2, 8);
    Iterator(v);

    // 重新查找值为5的数据的位置
    pos = find(v.begin(), v.end(), 5);
    // 删除值为5的数据
    pos = v.erase(pos);
    Iterator(v);

}

void Index()
{
    int a[] = {1, 2, 3, 4};
    vector<int> v(a, a + sizeof(a) / sizeof(a[0]));

    v[0] = 6;
    Iterator(v);

    // 通过数组下标遍历vector
    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << "The contents of v are: " << v[i] << endl;
    }

    // 使用范围for遍历vector
    for (auto i : v)
    {
        cout << "The contents of v are: " << i << endl;
    }
}

int main()
{
    Find();
    return 0;
}

#if 0
int main()
{
    Pop();
    return 0;
}


int main()
{
    Reserve();
    return 0;
}


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