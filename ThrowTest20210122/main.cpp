#include "head.h"
// 求两个数的商
double Division(int a, int b)
{
    if (b == 0)
    {
        throw "Division by zero condition!";
    }else
    {
        return (double)a / (double)b;
    }
}
// 接收输入函数
void func()
{
    try
    {
        int len, time;
        cout << "Please input tow nums:" << endl;
        cin >> len >> time;
        cout << Division(len, time) << endl;
    }
    catch(...)
    {
        throw;
    }
    
}

// 主函数
int main()
{
    try
    {
        func();
    }
    catch (const char *errmsg)
    {
        cout << errmsg << endl;
    }
    catch (...)
    {
        cout << "Unkonw exception!" << endl;
    }
    return 0;
}