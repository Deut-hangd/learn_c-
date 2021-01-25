#include "head1.h"

int main(int arg, char **args)
{
    shared_ptr<ListNode2> node1(new ListNode2);
    shared_ptr<ListNode2> node2(new ListNode2);
    cout << node1.use_count() << endl;
    cout << node2.use_count() << endl;
    // 引用计数未增加, 资源正常释放并回收
    node1->_next = node1;
    node2->_pre = node1;
    node1->_pre = node1;
    cout << node1.use_count() << endl;
    cout << node2.use_count() << endl;
    return 0;
}



#if 0
int main(int arg, char **args)
{
    shared_ptr<ListNode1> node1(new ListNode1);
    shared_ptr<ListNode1> node2(new ListNode1);
    cout << node1.use_count() << endl;
    cout << node2.use_count() << endl;
    // 循环引用, 会导致资源无法回收, 可以考虑使用weak_ptr解决
    node1->_next = node2;
    node2->_pre = node1;
    cout << node1.use_count() << endl;
    cout << node2.use_count() << endl;
    return 0;
}
#endif


#if 0
int main(int arg, char **args)
{
    auto_ptr<Date> ap(new Date);
    // auto_ptr 的拷贝构造会导致对象ap悬空, 从而导致ap->_year出错.
    //auto_ptr<Date> ap1(ap);
    ap->_year = 2022;
    cout << (*ap)._year << endl;
    return 0;
}
#endif