#include <iostream>
#include <string>

using std:: cout;
using std:: endl;
using std:: cin;
using std:: string;

class Person
{
    public:
    void display()
    {
        cout << _name << endl;
        cout << _age << endl;
    }

    protected:
    string _name = "peter";
    int _age = 18;
};

class Student : public Person
{
    public:
    void display()
    {
        Person:: display();
        cout << _stuId << endl;
    }
    protected:
    int _stuId = 12;
};

class Teacher : public Person
{
    protected:
    int _jobId;
};