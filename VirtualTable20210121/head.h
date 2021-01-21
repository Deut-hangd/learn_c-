#include <iostream>
using std:: cout;
using std:: cin;
using std:: endl;
typedef void(*VFPTR) ();
class Base
{
    public:
    virtual void func1() {cout << "Base:: func1" << endl;}
    virtual void func2() {cout << "Base:: func2" << endl;}

    private:
    int _a;
};

class Derive: public Base
{
    public:
    virtual void func1() {cout << "Derive:: func1" << endl;}
    virtual void func2() {cout << "Derive:: func2" << endl;}
    virtual void func3() {cout << "Derive:: func3" << endl;}

    private:
    int _b;
};

void PrintVTable(VFPTR vTable[])
{
    cout << "There is address of VT: " << vTable << endl;
    for (int i = 0; vTable[i] != nullptr; ++i)
    {
        printf("order: %d address: 0X%x, ->", i, vTable[i]);
        VFPTR f = vTable[i];
        f();
    }
    cout << endl;
}