#include <iostream>
#include <queue>
using std:: cout;
using std:: cin;
using std:: endl;
using std:: queue;

// 判定队列是否为空
void IfEmpty(const queue<int> &q)
{
    if (q.empty())
    {
        cout << "This queue is empty." << endl;
    }else
    {
        cout << "This queue is not empty." << endl;
    }
}

// 以值传递的方式遍历打印队列
void DisplayQueue1(queue<int> q)
{
    cout << "The size of current q is " << q.size() << endl;
    IfEmpty(q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    
}

// 以引用传递的方式遍历打印队列
void DisplayQueue2(queue<int> &q)
{
    cout << "The size of current q is " << q.size() << endl;
    IfEmpty(q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    
}

void TestBasicFunctions()
{
    queue<int> q1;

    queue<int> q2(q1);

    for (int i = 0; i < 10; ++i)
    {
        q2.push(i);
    }

    DisplayQueue2(q2);
    DisplayQueue1(q2);


}

int main(int arg, char **args)
{
    TestBasicFunctions();
    return 0;
}