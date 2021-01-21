#include <iostream>

using std:: cout;
using std:: cin;
using std:: endl;

typedef void(*VFPTR) ();
class Person
{
    public:
    virtual void func1() {cout << "Person::func1" << endl;}
    virtual void func2() {cout << "Person::func2" << endl;}

    private:
    int _a;
};

class Student
{
    public:
    virtual void func1() {cout << "Student::func1" << endl;}
    virtual void func2() {cout << "Student::func2" << endl;}

    private:
    int _b;
};

class Child: public Student, public Person
{
    public:
    virtual void func1() {cout << "Child::func1" << endl;}
    virtual void func3() {cout << "Child::func2" << endl;}

    private:
    int _c;

};

void PrintVTable(VFPTR vTable[])
{
    cout << "The address of virtual table is: " << vTable << endl;

    for (int i = 0; vTable[i] != nullptr; ++i)
    {
        printf("order: %d address: 0X%x -> ", i, vTable[i]);
        VFPTR f = vTable[i];
        f();
    }
    cout << endl;
}