#include "head.h"
int main(int arg, char **args)
{
    Base b;
    Derive d;
    Base c;

    VFPTR *vTableB = (VFPTR *)(*(int*)&b) ;
    PrintVTable(vTableB);

    VFPTR *vTableD = (VFPTR *)(*(int*)&d);
    PrintVTable(vTableD);
    return 0;
}