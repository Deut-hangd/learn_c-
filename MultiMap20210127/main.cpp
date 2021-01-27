#include "head.h"
void DisplayMap(const multimap<int, int>& m)
{
    for (auto& e : m)
    {
        cout << e.first << "--->" << e.second << endl;
    }
}

int main(int arg, char** args)
{
    // 定义一个multimap
    multimap<int, int> m;
    // 插入元素
    m.insert(pair<int, int>(1, 2));
    m.insert(make_pair(1, 3));
    m.insert(make_pair(2, 3));
    m.insert(make_pair(6, 7));
    DisplayMap(m);
    // 向multimap中插入一个键值对, 并接收返回的迭代器
    auto ret = m.insert(make_pair(2, 4));
    cout << ret->first << "=====" << ret->second << endl;
    // 删除key为2的所有键值对;   
    size_t c = m.erase(2);
    cout << "count of c is " << c << endl;
    DisplayMap(m);
    // 清空multimap
    m.clear();
    cout << "size: " << m.size() << endl;
    return 0;
}