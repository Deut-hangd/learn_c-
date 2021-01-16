#include <iostream>
#include <list>

using std:: cout;
using std:: cin;
using std:: endl;
using std:: list;

// This function is used for testing the constructor of list
void ConstructT()
{
    list<int> l1;  // �����list
    list<int> l2(4, 100);  // ���쳤��Ϊ4, ��ʼֵΪ100��list
    list<int> l3(l2.begin(), l2.end());  // ��l2��[begin(), end())��Ϊ�������乹��l3
    list<int> l4(l3);  // ʹ�ÿ������캯������l4
    
    int a[] = {1, 2, 3, 4};
    // ������ķ�Χ��Ϊ�������乹��l5
    list<int> l5(a, a + sizeof(a) / sizeof(a[0]));

    // ʹ�õ�������ӡl5�е�Ԫ��
    cout << "There are elems of l5: ";
    for (list<int>:: iterator it = l5.begin(); it != l5.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // ʹ�÷�Χfor������ӡl5�е�Ԫ��
    cout << "Threre are elems of l5: ";
    for (list<int>:: iterator it = l5.begin(); it != l5.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    for (list<int>:: reverse_iterator it = l5.rbegin(); it != l5.rend(); ++it)
    {
        cout << *it << " ";
    }

}

// This function is used to traverse a list backwards 
void ReverseOrder(list<int> &l) {
    
    cout << "There are elems of list: ";
    for (list<int>:: reverse_iterator it = l.rbegin(); it != l.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void Order(const list<int> &l) 
{
    cout << "There are elems of list: ";
    for (list<int>:: const_iterator it = l.begin(); it != l.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// This function is used for testing the basic functions of list
void FuntionTest()
{
    int a[] = {1, 2, 3, 4};
    // ������ķ�Χ��Ϊ�������乹��l5
    list<int> l(a, a + sizeof(a) / sizeof(a[0]));
    cout << "The size of current list is: " << l.size() << endl;
    l.push_back(5);
    l.push_front(0);
    Order(l);

}

// main function
int main(int arg, char ** args)
{

    FuntionTest();
    // int a[] = {1, 2, 3, 4};
    // // ������ķ�Χ��Ϊ�������乹��l5
    // list<int> l5(a, a + sizeof(a) / sizeof(a[0]));
    // ReverseOrder(l5);

    //ConstructT();
    return 0;
}