#include "head.h"
int  count = 0;
mutex m;
void F1()
{
    // ����һ��lock_guard, ��������Դ
    lock_guard<mutex> lockGuard(m);
    // ��ȫ�ֱ���count����1000000�μ�1����
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