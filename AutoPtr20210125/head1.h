#include <iostream>
#include <memory>
using std:: shared_ptr;
using std:: weak_ptr;
using std:: cout;
using std:: cin;
using std:: endl;

class ListNode1
{
    public:
    int _data;
    shared_ptr<ListNode1> _pre;
    shared_ptr<ListNode1> _next;

    ~ListNode1() {cout << "~ListNode1()" << endl;}

};

class ListNode2
{
    public:
    int _data;
    weak_ptr<ListNode2> _pre;
    weak_ptr<ListNode2> _next;


    ~ListNode2() {cout << "~ListNode2()" << endl;}
};