#include "head.h"

int main(int arg, char **args)
{
    // Student s;
    // Teacher t;
    // s.display();
    // t.display();
    Student s1;
    Person p = s1;
    Person *p2 = &s1;
    Person &p3 = s1;
    s1.display();
    Student *s2;
    s2 = (Student *)&p;
    s2->display();
    return 0;
}