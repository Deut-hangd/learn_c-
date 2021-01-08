#include <iostream>
#include <vector>
using std:: cout;
using std:: cin;
using std:: endl; 
using std:: vector;
int main()
{
    // 定义并初始化数组a
    int a[] = {16, 2, 34, 3};
    // 创建一个vector实例, 并使用迭代器进行初始化构造
    vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
    cout << "The contents of v are: ";
    // 使用迭代器遍历v的内容
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << " " << *it;
    }
    cout << '\0';
    return 0;
}