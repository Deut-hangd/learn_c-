#include "head.h"




#if 0
int main(int arg, char **args)
{
    auto_ptr<Date> ap(new Date);
    // auto_ptr 的拷贝构造会导致对象ap悬空, 从而导致ap->_year出错.
    auto_ptr<Date> ap1(ap);
    ap->_year = 2022;
    return 0;
}
#endif