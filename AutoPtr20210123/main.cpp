#include "head.h"




#if 0
int main(int arg, char **args)
{
    auto_ptr<Date> ap(new Date);
    // auto_ptr �Ŀ�������ᵼ�¶���ap����, �Ӷ�����ap->_year����.
    auto_ptr<Date> ap1(ap);
    ap->_year = 2022;
    return 0;
}
#endif