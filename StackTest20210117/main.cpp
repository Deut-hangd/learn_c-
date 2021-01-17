#include <iostream>
#include <stack>
using std:: cout;
using std:: cin;
using std:: endl;
using std:: stack;

void IfEmpty(const stack<int> &s)
{
    if (s.empty())
    {
        cout << "This stack is empty." << endl;
    }else 
    {
        cout << "This stack is not empty." << endl;
    }
}

// ��ֵ���ݵķ�ʽ������ӡջ������
void DisplayStack1(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// ��Ӧ�ô��ݵķ�ʽ������ӡջ������
void DisplayStack2(stack<int> &s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// ����stack�еĽӿ�
void TestBasicFunctions()
{
    stack<int> s;
    
    stack<int> s1(s);

    s1.push(1);
    s1.push(2);
    DisplayStack1(s1);
    IfEmpty(s1);
    DisplayStack2(s1);
    IfEmpty(s1);

}

int main()
{
    TestBasicFunctions();
    return 0;
}