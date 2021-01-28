#include "head.h"
int  count = 0;
mutex m;
void F1()
{
    // 定义一个lock_guard, 管理锁资源
    lock_guard<mutex> lockGuard(m);
    // 对全局变量count进行1000000次加1迭代
    for (size_t i = 0; i < 1000000; ++i)
    {
        ++count;
    }
}

void F2()
{
    lock_guard<mutex> lockGuard(m);
    for (size_t i = 0; i < 1000000; ++i)
    {
        ++count;
    }
}

int main(int arg, char** args)
{
    thread t1(F1);
    thread t2(F2);

    t1.join();
    t2.join();

    cout << "process is over" << endl;
    cout << "count = " << count << endl;
    return 0;
}